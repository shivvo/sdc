#ifndef SDC_NODE_H
#define SDC_NODE_H

#include <queue>
#include "packet.h"
#include "network"
#include "clock.h"

namespace sdc {
  
  // Node - unit of communication lowest in SDC (ToRs, racks, etc.)
  class node {
  private:
    // Node identifier
    int m_node_id;
    int m_node_count; 

    // Local queues
    std::queue<packet> *m_local_queues;

    // Network
    sdc::network_fabric *m_network;

    // Clock
    sdc::clock *m_clock;
  public:
    
    // Constructors/destructor
    node(int node_id, int node_count, sdc::clock *clk);
    node();
    ~node();
    
    // Packet processing
    void accept_packet(sdc::packet pkt);
    void transmit_next_packet();
    
    // Setters
    void set_network(sdc::network_fabric network);

    // Getters
    int node_id();

  };
}

#endif