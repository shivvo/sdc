#include "simulator.h"

#include <iostream>
#include <vector>
#include "flow.h"
#include "schedule.h"

namespace sdc {

  // Constructors/destructor

  simulator::simulator(sdc::logger *log, int node_count, int cycle_length, sdc::controller *ctrl, sdc::flow_factory *flw_gen, int flows_max)
  : m_clk(0), m_sched(node_count, cycle_length) {
    m_log = log;
    m_node_count = node_count;
    m_ctrl = ctrl;
    m_flw_gen = flw_gen;

    m_nodes = new sdc::node *[m_node_count];
    for (int i = 0; i < m_node_count; i++) {
      m_nodes[i] = new sdc::node(i, m_node_count, &m_clk);
    }
    
    m_network = new sdc::network_fabric(m_nodes);

    for (int i = 0; i < m_node_count; i++) {
      m_nodes[i]->set_network(m_network);
      m_nodes[i]->set_schedule(&m_sched);
      m_nodes[i]->set_simulator(this);
    }

    m_flows_max = flows_max;
    m_flows_completed = 0;
    m_fct_total = 0;
    m_time_flow_last_completed = 0;
  }

  simulator::~simulator() {
    for (int i = 0; i < m_node_count; i++) {
      delete m_nodes[i];
    }
    delete[] m_nodes;
    delete m_network;
  }

  // Run simulator

  void simulator::run() {
    while (m_flows_completed < m_flows_max) {
      
      std::vector<sdc::flow> flws = m_flw_gen->flows_for_time(m_clk.current_time());
      if (flws.size() > 0) std::cout << "Starting " << flws.size() << " flows..." << std::endl;
      for (std::vector<flow>::iterator iter = flws.begin(); iter != flws.end(); ++iter) {
        sdc::flow flw = *iter;
        m_flws[flw.flow_id()] = flw;
        m_flws[flw.flow_id()].set_start_time(m_clk.current_time());
        m_nodes[flw.source_node()]->start_flow(flw);
      }

      for (int i = 0; i < m_node_count; i++) {
        m_nodes[i]->transmit_next_packet();
      }
      m_ctrl->update_schedule(&m_sched, m_nodes, &m_clk);
      m_clk.tick();
    }

    double total_sent = 0;
    for (int i = 0; i < m_node_count; i++) {
      double gp = (double) m_nodes[i]->count_sent() / m_time_flow_last_completed;
      m_log->log_gp(i, gp);
      total_sent += m_nodes[i]->count_sent();
    }

    m_log->log_avg("gp", total_sent / (m_node_count * m_time_flow_last_completed));
    m_log->log_avg("fct", m_fct_total / m_flows_completed);    
  }

  void simulator::packet_arrived(int flow_id) {
    m_flws[flow_id].packet_arrived();
    if (m_flws[flow_id].completed()) {
      std::cout << "Flow " << flow_id << " finished at " << m_clk.current_time() << "..." << std::endl;
      m_flws[flow_id].set_end_time(m_clk.current_time());
      m_flows_completed++;
      m_fct_total += m_flws[flow_id].fct();
      m_log->log_fct(m_flws[flow_id]);
      m_time_flow_last_completed = m_clk.current_time();
    }
  }

}