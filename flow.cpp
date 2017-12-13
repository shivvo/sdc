#include "flow.h"

namespace sdc {

  // Constructors/destructor

  flow::flow(int flow_id, int size) {
    m_flow_id = flow_id;
    m_size = size;
    m_count_arrived = 0;
  }

  // Flow state

  void flow::packet_arrived() {
    m_count_arrived++;
  }

  void flow::completed() {
    return m_count_arrived == m_size;
  }

  // Setters

  void flow::set_start_time(time_t start_time) {
    m_start_time = start_time;
  }

  void flow::set_end_time(time_t end_time) {
    m_end_time = end_time;
  }

  void flow::set_source_node(int source_node) {
    m_source_node = source_node;
  }

  void set_target_node(int target_node) {
    m_target_node = target_node;
  }

  // Getters

  int flow::flow_id() {
    return m_flow_id;
  }

  int flow::size() {
    return m_size;
  }

  time_t flow::start_time() {
    return m_start_time;
  }

  time_t flow::end_time() {
    return m_end_time;
  }
}