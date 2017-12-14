#ifndef SDC_NODE_H
#define SDC_NODE_H

#include <queue>
#include "clock.h"
#include "flow.h"
#include "packet.h"

namespace sdc {
  
  // Node - unit of communication lowest in SDC (ToRs, racks, etc.)
  class network_fabric;
  class schedule;
  class simulator;

  class node {
  private:
    // Node information
    int m_node_id;
    int m_node_count;
    long m_count_sent;
    // Local queues
    std::queue<packet> *m_local_queues;
    // Network
    sdc::network_fabric *m_network;
    // Schedule
    sdc::schedule *m_sched;
    // Clock
    sdc::clock *m_clk;
    // Simulator
    sdc::simulator *m_sim;
  public:
    
    // Constructors/destructor
    node(int node_id, int node_count, sdc::clock *clk);
    ~node();
    
    // Flow and packet processing
    void start_flow(sdc::flow flw);
    void accept_packet(sdc::packet pkt);
    void transmit_next_packet();
    
    // Setters
    void set_network(sdc::network_fabric *network);
    void set_schedule(sdc::schedule *sched);
    void set_simulator(sdc::simulator *sim);

    // Getters
    int node_id();

  };
}

#endif