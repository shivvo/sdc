
#include "network_fabric.h"

namespace sdc {
  
  network_fabric::network_fabric(int node_count, sdc::node **nodes) {
    m_nodes = new sdc::node *[node_count];
    for (int i = 0; i < node_count; i++) {
      m_nodes[i] = nodes[i];
    }
  }

  network_fabric::~network_fabric() {
    delete m_nodes;
  }

  void network_fabric::do_route_packet(sdc::packet pkt) {
    m_nodes[pkt.target_node()]->accept_packet(pkt);
  }

}