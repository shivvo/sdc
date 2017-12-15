#ifndef SDC_NETWORK_FABRIC_H
#define SDC_NETWORK_FABRIC_H

#include <queue>
#include "packet.h"

namespace sdc {

  // Network Fabric - connects nodes and routes packets to them
  class node;
  class network_fabric {
  private:
    // Nodes connected to the network
    sdc::node **m_nodes;
    std::queue<packet> m_pkt_queue;
    std::queue<int> m_target_queue;
  public:
    
    // Constructors/destructor
    network_fabric(sdc::node **nodes);
    
    // Route packet to node
    void do_route_packet(sdc::packet pkt, int target_node);
    void flush();
  };
}

#endif