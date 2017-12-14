#ifndef SDC_LOGGER_H
#define SDC_LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include "flow.h"

namespace sdc {
  
  // Logger - log information about throughput and flows
  class logger {
  private:
    // File streams
    std::ofstream m_flw_log;
    std::ofstream m_gp_log;
    std::ofstream m_avg_log;
    // File names
    std::string m_flw_log_fn;
    std::string m_gp_log_fn;
    std::string m_avg_log_fn;
  public:
    
    // Constructors/destructor
    logger(std::string flw_log_fn, std::string gp_log_fn, std::string avg_log_fn);
    ~logger();

    // Logging actions
    void log_fct(sdc::flow flw);
    void log_gp(int node_id, double gp);
    void log_avg(std::string avg_type, double value);
  };

}

#endif