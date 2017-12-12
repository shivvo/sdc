
#ifndef SDC_FLOW_H
#define SDC_FLOW_H

namespace sdc {
  class flow {
  private:
    int m_flow_id;
    int m_size;
  public:
    flow(int flow_id, int size);

    int flow_id();
    int size();
  };
}

#endif