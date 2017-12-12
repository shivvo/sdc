
#include "flow.h"

namespace sdc {

  flow::flow(int flow_id, int size) {
    m_flow_id = flow_id;
    m_size = size;
  }

  int flow::flow_id() {
    return m_flow_id;
  }

  int flow::size() {
    return m_size;
  }
}