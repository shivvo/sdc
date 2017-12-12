#include "packet.h"

namespace sdc {

  packet::packet(int source_node, int target_node, int flow_id, int seq_num) {
    m_source_node = source_node;
    m_target_node = target_node;
    m_flow_id = flow_id;
    m_seq_num = seq_num;
  };
  
  packet::packet () : packet(-1, -1, -1, -1) {};   
  
  void packet::set_enter_time(int enter_time) {
    m_enter_time = enter_time;
  }

  void packet::set_exit_time(int exit_time) {
    m_exit_time = exit_time;
  }

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

  int packet::enter_time() {
    return m_enter_time; 
  }

  int packet::exit_time() {
    return m_exit_time;
  }
}