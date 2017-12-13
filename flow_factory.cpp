#include "flow_factory.h"

namespace sdc {

  flow_factory::flow_factory(int pair_count, int flow_size) {
    m_pair_count = pair_count;
    m_flow_size = flow_size;
  }

  std::vector<sdc::flow> flow_factory::flows_for_time(unsigned long clk_value) {
    if (clk_value > 0) return std::vector<sdc::flow>();
    
    std::vector<sdc::flow> flws;
    int flow_id = 0;
    
    for (int i = 0; i < m_pair_count; i++) { 
      for (int j = 0; j < m_pair_count; j++) {
        if (i == j) continue;   
        sdc::flow flw(flow_id++, m_flow_size);
        flw.set_source_node(i);
        flw.set_target_node(j);    
        flws.push_back(flw);
      }
    }
    
    return flws;
  }

}