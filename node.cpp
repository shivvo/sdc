#include "node.h"

#include "network_fabric.h"
#include "schedule.h"
#include "simulator.h"

namespace sdc {

  // Constructors/destructor  
  node::node(int node_id, int node_count, sdc::clock *clk) {
    m_node_id = node_id;
    m_node_count = node_count;
    m_count_sent = 0;
    m_local_queues = new std::queue<packet>[node_count];
    m_clk = clk;
  }
  
  node::~node() {
    delete[] m_local_queues;
  }
  
  // Flow and packet processing  

  void node::start_flow(sdc::flow flw) {
    int seq_no = 0;
    for (int i = 0; seq_no < flw.size(); i++) {
      int node_id = (flw.target_node() + i) % m_node_count;
      if (node_id == m_node_id) continue;
      sdc::packet pkt(flw.source_node(), flw.target_node(), flw.flow_id(), seq_no++);
      m_local_queues[node_id].push(pkt);
    }
  }

  void node::accept_packet(sdc::packet pkt) {
    int target_node = pkt.target_node();
    if (target_node == m_node_id) {
      m_sim->packet_arrived(pkt.flow_id());
    } else {
      m_local_queues[target_node].push(pkt);
    }
  }

  void node::transmit_next_packet() {
    int target_node = m_sched->target_from_source(m_node_id, m_clk->current_time());
    if (!m_local_queues[target_node].empty()) {
      sdc::packet pkt = m_local_queues[target_node].front();
      m_local_queues[target_node].pop();
      m_network->do_route_packet(pkt);
      m_count_sent++;
    }
  }

  // Setters

  void node::set_network(sdc::network_fabric *network) {
    m_network = network;
  }

  void node::set_schedule(sdc::schedule *sched) {
    m_sched = sched;
  }

  void node::set_simulator(sdc::simulator *sim) {
    m_sim = sim;
  }

  // Getters

  int node::node_id() {
    return m_node_id;
  }
}