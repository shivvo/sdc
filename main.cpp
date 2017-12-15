
#include <iostream>
#include <sstream>
#include <string>
#include "simulator.h"
#include "simple_drain_node_factory.h"

int main() {
	std::cout << "hello, world!" << std::endl;
  int n = 1024;
  
  for (int i = 1; i <= n / 2; i++) {
    std::ostringstream fct_strstrm;
    fct_strstrm << "logs/fct-simple-drain-" << 2*i << "-pairs-log.csv";
    std::string fct_log_fn(fct_strstrm.str());

    std::ostringstream gp_strstrm;
    gp_strstrm << "logs/gp-simple-drain-" << 2*i << "-pairs-log.csv";    
    std::string gp_log_fn(gp_strstrm.str());

    std::ostringstream avg_strstrm;
    avg_strstrm << "logs/avg-simple-drain-" << 2*i << "-pairs-log.csv";    
    std::string avg_log_fn(avg_strstrm.str());

    sdc::logger log(fct_log_fn, gp_log_fn, avg_log_fn);
    sdc::simple_drain_node_factory node_gen;
    sdc::controller ctrl;
    sdc::flow_factory flw_gen(i, (n-1));
    sdc::simulator sim(&log, &node_gen, n, 1, &ctrl, &flw_gen, flw_gen.estimated_count());
    sim.run();
  }

  for (int i = 1; i <= n / 2; i++) {
    std::ostringstream fct_strstrm;
    fct_strstrm << "logs/fct-round-robin-" << 2*i << "-pairs-log.csv";
    std::string fct_log_fn(fct_strstrm.str());

    std::ostringstream gp_strstrm;
    gp_strstrm << "logs/gp-round-robin-" << 2*i << "-pairs-log.csv";    
    std::string gp_log_fn(gp_strstrm.str());

    std::ostringstream avg_strstrm;
    avg_strstrm << "logs/avg-round-robin-" << 2*i << "-pairs-log.csv";    
    std::string avg_log_fn(avg_strstrm.str());

    sdc::logger log(fct_log_fn, gp_log_fn, avg_log_fn);
    sdc::node_factory node_gen;
    sdc::controller ctrl;
    sdc::flow_factory flw_gen(i, (n-1));
    sdc::simulator sim(&log, &node_gen, n, 1, &ctrl, &flw_gen, flw_gen.estimated_count());
    sim.run();
  }
}