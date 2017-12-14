#include "flow.h"

#include <iostream>

namespace sdc {

  // Constructors/destructor

  flow::flow(int flow_id, int size) {
    m_flow_id = flow_id;
    m_size = size;
    m_count_arrived = 0;
    m_source_node = -1;
    m_target_node = -1;
  }

  flow::flow(const flow &other) {
    m_flow_id = other.m_flow_id;
    m_size = other.m_size;
    m_count_arrived = other.m_count_arrived;
    m_source_node = other.m_source_node;
    m_target_node = other.m_target_node;
  }

  flow::flow() : flow(-1, -1) {}

  // Flow state

  void flow::packet_arrived() {
    m_count_arrived++;
  }

  bool flow::completed() {
    return m_count_arrived == m_size;
  }

  // Setters

  void flow::set_start_time(unsigned long start_time) {
    m_start_time = start_time;
  }

  void flow::set_end_time(unsigned long end_time) {
    m_end_time = end_time;
  }

  void flow::set_source_node(int source_node) {
    m_source_node = source_node;
  }

  void flow::set_target_node(int target_node) {
    m_target_node = target_node;
  }

  // Getters

  int flow::flow_id() {
    return m_flow_id;
  }

  int flow::size() {
    return m_size;
  }

  int flow::source_node() {
    return m_source_node;
  }

  int flow::target_node() {
    return m_target_node;
  }

  unsigned long flow::start_time() {
    return m_start_time;
  }

  unsigned long flow::end_time() {
    return m_end_time;
  }
}