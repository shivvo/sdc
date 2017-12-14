#ifndef SDC_FLOW_FACTORY
#define SDC_FLOW_FACTORY

#include <vector>
#include "flow.h"

namespace sdc {

  // Flow factory - generate flows that enter the network at some time
  class flow_factory {
  private:
    // Flow generation information
    int m_pair_count;
    int m_flow_size;

    // Helpers to generate flows
    void one_sided_pair(std::vector<flow> &flws);
    void two_sided_pair(std::vector<flow> &flws);
    void all_to_all(std::vector<flow> &flws);    

  public:
    
    // Constructors/destructor
    flow_factory(int pair_count, int flow_size);

    // Get flows for time
    std::vector<sdc::flow> flows_for_time(unsigned long clk_value); 

    // Estimated number of flows generated
    int estimated_count();
  };
}

#endif