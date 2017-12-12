
#ifndef SDC_NODE_H
#define SDC_NODE_H

#include <queue>
#include "packet.h"

namespace sdc {
  class node {
  private:
    // Node identifier
    int m_node_id;
    int m_node_count; 
    // Local queues
    std::queue<packet>* m_local_queues;
  public:
    // Constructors and destructor
    node(int node_id, int node_count);
    node();
    ~node();
    
    // Getters
    int node_id();

    // Packet processing
    void accept_packet(sdc::packet pkt);
    void transmit_next_packet();
  };
}

#endif