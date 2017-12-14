#include "network_fabric.h"

#include "node.h"

namespace sdc {
  
  // Constructors/destructor

  network_fabric::network_fabric(sdc::node **nodes) {
    m_nodes = nodes;
  }

  // Route packet to node
  void network_fabric::do_route_packet(sdc::packet pkt, int target_node) {
    m_nodes[target_node]->accept_packet(pkt);
  }

}