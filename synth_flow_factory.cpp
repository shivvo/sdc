#include "synth_flow_factory.h"

#include <iterator>
namespace sdc {

  void synth_flow_factory::next_flow() {
    std::string line;
    if (!std::getline(m_synthload, line)) return;

    std::istringstream iss(line);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    m_flw = new sdc::flow(std::stoi(results[0]), std::stoi(results[1]));
    m_flw->set_source_node(std::stoi(results[2]));
    m_flw->set_target_node(std::stoi(results[3]));
    m_flw->set_start_time(std::stoul(results[4]));
  }

  synth_flow_factory::~synth_flow_factory() {
    m_synthload.close();
  }

  // Constructors/destructor
  synth_flow_factory::synth_flow_factory(std::string synth_fn, int count_flows)
  : flow_factory(0, 0) {
    m_count_flows = count_flows;
    m_count_flows_remaining = count_flows;
    m_synthload.open(synth_fn);
    m_flw = NULL;
  }

  // Get flows for time
  std::vector<sdc::flow> synth_flow_factory::flows_for_time(unsigned long clk_value) {
    std::vector<sdc::flow> flws;
    if (m_flw == NULL) {
      next_flow();
    }

    if (m_flw != NULL && m_flw->start_time() == clk_value) {
      flws.push_back((*m_flw));
      delete m_flw;
      m_flw = NULL;  
    }

    while (m_flw == NULL) {
      next_flow();
      if (m_flw == NULL) return flws;
      if (m_flw->start_time() == clk_value) {
        flws.push_back((*m_flw));
        delete m_flw;
        m_flw = NULL;
      }
    }

    return flws;
  }

  // Estimated number of flows generated
  int synth_flow_factory::estimated_count() {
    return m_count_flows;
  }

}