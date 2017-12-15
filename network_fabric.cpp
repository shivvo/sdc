#include "network_fabric.h"

#include "node.h"

namespace sdc {
  
  // Constructors/destructor

  network_fabric::network_fabric(sdc::node **nodes) {
    m_nodes = nodes;
  }

  // Route packet to node
  void network_fabric::do_route_packet(sdc::packet pkt, int target_node) {
    m_pkt_queue.push(pkt);
    m_target_queue.push(target_node);
  }

  void network_fabric::flush() {
    int count_pkts = m_pkt_queue.size();
    for (int i = 0; i < count_pkts; i++) {
      sdc::packet pkt = m_pkt_queue.front();
      int target_node = m_target_queue.front();
      m_nodes[target_node]->accept_packet(pkt);
      m_pkt_queue.pop();
      m_target_queue.pop();
    }
  }

}