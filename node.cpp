#include "node.h"

namespace sdc {

  // Constructors/destructor  
  node::node(int node_id, int node_count) {
    m_node_id = node_id;
    m_node_count = node_count;
    m_local_queues = new std::queue<packet>[node_count];
  }
  
  node::node() : node(-1, 0) {};

  node::~node() {
    delete m_local_queues;
  }
  
  // Packet processing  

  void node::accept_packet(sdc::packet pkt) {
    int target_node = pkt.target_node();
    if (target_node == m_node_id) {
      // TODO
    }
    m_local_queues[target_node].push(pkt);
  }

  void node::transmit_next_packet() {

  }

  // Getters

  int node::node_id() {
    return m_node_id;
  }
}