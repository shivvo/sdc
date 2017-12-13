#include "simulator.h"

namespace sdc {

  // Constructors/destructor

  simulator::simulator(int node_count) {
    m_node_count = node_count;
    m_clock = sdc::clock(0);
    m_nodes = new sdc::node *[m_node_count];
    for (int i = 0; i < m_node_count; i++) {
      m_nodes[i] = new sdc::node(i, m_node_count, &m_clock);
    }
    m_network = sdc::network_fabric(m_node_count, m_nodes);
    for (int i = 0; i < m_node_count; i++) {
      m_nodes[i]->set_network(&m_network);
      m_nodes[i]->set_simulator(this);
    }
  }

  simulator::~simulator() {
    for (int i = 0; i < m_node_count; i++) {
      delete m_nodes[i];
    }
    delete m_nodes;
  }

  // Run simulator

  void simulator::run() {

  }

  void simulator::packet_arrived(int flow_id) {

  }

}