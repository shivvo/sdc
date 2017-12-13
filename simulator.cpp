#include "simulator.h"

namespace sdc {

  // Constructors/destructor

  simulator::simulator(int node_count) {
    m_node_count = node_count;
    m_nodes = new sdc::node *[m_node_count];
    for (int i = 0; i < m_node_count; i++) {
      m_nodes[i] = new sdc::node(i, m_node_count);
    }
    m_network = new sdc::network_fabric(m_node_count, m_nodes);
    m_clock = sdc::clock(0);
  }

  simulator::~simulator() {
    for (int i = 0; i < m_node_count; i++) {
      delete m_nodes[i];
    }
    delete m_nodes;
    delete m_network;
  }

  // Run simulator

  void simulator::run() {

  }

}