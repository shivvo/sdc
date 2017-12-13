#ifndef SDC_FLOW_FACTORY
#define SDC_FLOW_FACTORY

#include <vector>
#include "flow.h"

namespace sdc {

  // Flow factory - generate flows that enter the network at some time
  class flow_factory {
  private:
    int m_pair_count;
    int m_flow_size;
  public:
    
    // Constructors/destructor
    flow_factory(int pair_count, int flow_size);

    // Get flows for time
    std::vector<sdc::flow> flows_for_time(unsigned long clk_value); 

  };
}

#endif