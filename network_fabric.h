#ifndef SDC_NETWORK_FABRIC_H
#define SDC_NETWORK_FABRIC_H

#include "packet.h"
#include "node.h"

namespace sdc {

  // Network Fabric - connects nodes and routes packets to them
  class network_fabric {
  private:
    // Nodes connected to the network
    sdc::node **m_nodes;    
  public:
    
    // Constructors/destructor
    network_fabric(sdc::node **nodes);
    
    // Route packet to node
    void do_route_packet(sdc::packet pkt);
  };
}

#endif