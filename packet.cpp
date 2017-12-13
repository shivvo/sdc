#include "packet.h"

namespace sdc {

  // Constructors and destructors

  packet::packet(int source_node, int target_node, int flow_id, int seq_num) {
    m_source_node = source_node;
    m_target_node = target_node;
    m_flow_id = flow_id;
    m_seq_num = seq_num;
  };
  
  // Getters

  int packet::source_node() {
    return m_source_node;
  }

  int packet::target_node() {
    return m_target_node;
  }

  int packet::flow_id() {
    return m_flow_id;
  }

  int packet::seq_num() {
    return m_seq_num;
  }
}