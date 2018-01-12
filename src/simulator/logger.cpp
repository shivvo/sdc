#include "logger.h"

namespace sdc {

  // Constructors/destructor

  logger::logger(std::string flw_log_fn, std::string gp_log_fn, std::string avg_log_fn) {
    m_flw_log_fn = flw_log_fn;
    m_gp_log_fn = gp_log_fn;
    m_avg_log_fn = avg_log_fn;
    
    m_flw_log.open(m_flw_log_fn);
    m_gp_log.open(m_gp_log_fn);
    m_avg_log.open(m_avg_log_fn);

    m_flw_log << "flow_id,size,source,target,fct" << std::endl;
    m_gp_log << "node_id,gp" << std::endl;
    m_avg_log << "avg,value" << std::endl;
  }

  logger::~logger() {
    m_flw_log.close();
    m_gp_log.close();
    m_avg_log.close();    
  }

  // Logging actions

  void logger::log_fct(sdc::flow flw) {
    m_flw_log << flw.flow_id() << ",";
    m_flw_log << flw.size() << ",";
    m_flw_log << flw.source_node() << ",";
    m_flw_log << flw.target_node() << ",";
    m_flw_log << flw.fct() << std::endl;    
  }

  void logger::log_gp(int node_id, double gp) {
    m_gp_log << node_id << "," << gp << std::endl;
  }

  void logger::log_avg(std::string avg_type, double value) {
    m_avg_log << avg_type << "," << value << std::endl;
  }
 
}