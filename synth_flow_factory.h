#ifndef SDC_SYNTH_FLOW_FACTORY_H
#define SDC_SYNTH_FLOW_FACTORY_H

#include <string>
#include <fstream>
#include <queue>
#include <sstream>
#include "flow_factory.h"

namespace sdc {

  // Flow factory - generate flows that enter the network at some time
  class synth_flow_factory: public flow_factory {
  private:
    std::ifstream m_synthload;
    sdc::flow *m_flw;
    int m_count_flows;
    int m_count_flows_remaining;
    std::queue<sdc::flow> m_flws;
    void next_flow();
  public:
    
    // Constructors/destructor
    synth_flow_factory(std::string synth_fn, int count_flows);
    ~synth_flow_factory();

    // Get flows for time
    std::vector<sdc::flow> flows_for_time(unsigned long clk_value) override; 

    // Estimated number of flows generated
    int estimated_count() override;
  };
}

#endif