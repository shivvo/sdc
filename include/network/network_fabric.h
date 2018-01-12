#ifndef SDC_NETWORK_FABRIC_H
#define SDC_NETWORK_FABRIC_H

#include <queue>
#include "packet.h"

namespace sdc {

  class node;  

  // Network Fabric - connects nodes and routes packets to them
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
    void push_packet(sdc::packet pkt, int target_node);
    void flush_all_packets();
  };
}

#endif