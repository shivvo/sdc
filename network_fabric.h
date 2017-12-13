
#ifndef SDC_NETWORK_FABRIC_H
#define SDC_NETWORK_FABRIC_H

#include "packet.h"
#include "node.h"

namespace sdc {
  class network_fabric {
  private:
    sdc::node **m_nodes;    
  public:
    network_fabric(int node_count, sdc::node **nodes);
    ~network_fabric();
    void do_route_packet(sdc::packet pkt);
  };
}

#endif