#ifndef SDC_SIMPLE_DRAIN_NODE_H
#define SDC_SIMPLE_DRAIN_NODE_H

#include <bitset>
#include <vector>
#include "node.h"

namespace sdc {
  
  // Simple drain node - only sends packets from non-empty queues
  class simple_drain_node: public node {
  protected:
    // Simple drain information
    std::bitset<2048> m_targets_included;
    int *m_targets;
    int m_count_targets;
    int m_count_targets_sent;

    // Enqueue a packet
    void enqueue_packet(sdc::packet pkt, int node_id) override;
  public:
    
    // Constructors/destructor
    simple_drain_node(int node_id, int node_count, sdc::clock *clk);
    ~simple_drain_node();

    // Overridden packet transmission
    void transmit_next_packet() override;
  };

}

#endif