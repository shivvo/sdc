#include "flow.h"

namespace sdc {

  // Constructors/destructor

  flow::flow(int flow_id, int size) {
    m_flow_id = flow_id;
    m_size = size;
  }

  // Setters

  void flow::set_start_time(time_t start_time) {
    m_start_time = start_time;
  }

  void flow::set_end_time(time_t end_time) {
    m_end_time = end_time;
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