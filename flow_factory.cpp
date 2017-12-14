#include "flow_factory.h"

namespace sdc {

  // Helpers to generate flows
  
  void flow_factory::one_sided_pair(std::vector<flow> &flws) {
    int flow_id = 0;
    
    for (int i = 0; i < m_pair_count; i++) {
      sdc::flow flw1(flow_id++, m_flow_size);
      flw1.set_source_node(i);
      flw1.set_target_node(i + m_pair_count);    
      flws.push_back(flw1);
    }
  }

  void flow_factory::two_sided_pair(std::vector<flow> &flws) {
    int flow_id = 0;
    
    for (int i = 0; i < m_pair_count; i++) {
      sdc::flow flw1(flow_id++, m_flow_size);
      flw1.set_source_node(i);
      flw1.set_target_node(i + m_pair_count);    
      flws.push_back(flw1);

      sdc::flow flw2(flow_id++, m_flow_size);
      flw2.set_source_node(i + m_pair_count);
      flw2.set_target_node(i);    
      flws.push_back(flw2);
    }
  }

  void flow_factory::all_to_all(std::vector<flow> &flws) {
    int flow_id = 0;

    for (int i = 0; i < m_pair_count; i++) {
      for (int j = 0; j < m_pair_count; j++) {
        if (i == j) continue;
        sdc::flow flw1(flow_id, m_flow_size);
        flw1.set_source_node(i);
        flw1.set_target_node(j);    
        flws.push_back(flw1);
        flow_id++;
      }
    }
  }


  flow_factory::flow_factory(int pair_count, int flow_size) {
    m_pair_count = pair_count;
    m_flow_size = flow_size;
  }

  std::vector<sdc::flow> flow_factory::flows_for_time(unsigned long clk_value) {
    if (clk_value > 0) return std::vector<sdc::flow>();
    
    std::vector<sdc::flow> flws;    
    two_sided_pair(flws);
    
    return flws;
  }

  // Estimated number of flows generated
  
  int flow_factory::estimated_count() {
    return 2 * m_pair_count;
  }

}