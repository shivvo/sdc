#ifndef SDC_NODE_H
#define SDC_NODE_H

#include <queue>
#include "packet.h"

namespace sdc {
  
  // Node - unit of communication lowest in SDC (ToRs, racks, etc.)
  class node {
  private:
    // Node identifier
    int m_node_id;
    int m_node_count; 

    // Local queues
    std::queue<packet> *m_local_queues;
  public:
    
    // Constructors/destructor
    node(int node_id, int node_count);
    node();
    ~node();
    
    // Packet processing
    void accept_packet(sdc::packet pkt);
    void transmit_next_packet();
    
    // Getters
    int node_id();

  };
}

#endif