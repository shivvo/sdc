#include "simple_drain_node.h"

#include <iostream>
#include "network_fabric.h"
#include "schedule.h"

namespace sdc {

  // Enqueue a packet

  void simple_drain_node::enqueue_packet(sdc::packet pkt, int node_id) {
    m_local_queues[node_id].push(pkt);
    if (!m_targets_included[node_id] && m_count_targets < m_node_count - 1) {
      m_targets_included[node_id] = true;
      m_targets[m_count_targets++] = node_id;
    }
  }

  // Constructors/destructor
  
  simple_drain_node::simple_drain_node(int node_id, int node_count, sdc::clock *clk) 
  : node(node_id, node_count, clk), m_targets_included(0) {
    m_targets = new int[node_count];
    m_count_targets = 0;
    m_count_targets_sent = 0;
  }
  
  simple_drain_node::~simple_drain_node() {
    delete[] m_targets;
  }

  // Overridden packet transmission

  void simple_drain_node::transmit_next_packet() {
    int slot = m_clk->current_time() % (m_node_count - 1);
    int target_node = -1;
    if (m_count_targets_sent < m_count_targets) {
      target_node = m_targets[m_count_targets_sent++];
    } else if (m_count_targets > 0) {
      target_node = m_targets[slot % m_count_targets];
    }

    if (target_node != -1 && m_local_queues[target_node].size() > 0) {
      sdc::packet pkt = m_local_queues[target_node].front();
      m_local_queues[target_node].pop();
      m_network->push_packet(pkt, target_node);
      m_count_sent++;

      if (m_local_queues[target_node].size() == 0) {
        m_targets_included[target_node] = false;
      }
    }

    if (slot == m_node_count - 2) {
      m_count_targets = 0;
      m_count_targets_sent = 0;
      for (int i = 1; i < m_node_count; i++) {
        int node_id = (m_node_id + i) % m_node_count;
        if (m_targets_included[node_id]) {
          m_targets[m_count_targets++] = node_id;
        }
      }
    }
  }
}