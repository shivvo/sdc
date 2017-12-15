#ifndef SDC_NODE_H
#define SDC_NODE_H

#include <queue>
#include "clock.h"
#include "flow.h"
#include "packet.h"

namespace sdc {
  
  // Node - unit of communication lowest in SDC (ToRs, racks, etc.). Round-robin operation
  class network_fabric;
  class schedule;
  class simulator;

  class node {
  protected:
    // Node information
    int m_node_id;
    int m_node_count;
    unsigned long m_count_sent;
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

    virtual void enqueue_packet(sdc::packet pkt, int node_id);
  public:
    
    // Constructors/destructor
    node(int node_id, int node_count, sdc::clock *clk);
    virtual ~node();
    
    // Flow and packet processing
    virtual void start_flow(sdc::flow flw);
    virtual void accept_packet(sdc::packet pkt);
    virtual void transmit_next_packet();
    
    // Setters
    void set_network(sdc::network_fabric *network);
    void set_schedule(sdc::schedule *sched);
    void set_simulator(sdc::simulator *sim);

    // Getters
    int node_id();
    unsigned long count_sent();

  };
}

#endif