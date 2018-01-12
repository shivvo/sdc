
#include <iostream>
#include <sstream>
#include <string>
#include "simulator.h"
#include "simple_drain_node_factory.h"
#include "synth_flow_factory.h"

int main() {
  std::cout << "hello, world!" << std::endl;
  int n = 1024;
  
  if (true) {
    std::ostringstream fct_strstrm;
    fct_strstrm << "logs/synth-fct-simple-drain-log.csv";
    std::string fct_log_fn(fct_strstrm.str());

    std::ostringstream gp_strstrm;
    gp_strstrm << "logs/synth-gp-simple-drain-pairs-log.csv";    
    std::string gp_log_fn(gp_strstrm.str());

    std::ostringstream avg_strstrm;
    avg_strstrm << "logs/synth-avg-simple-drain-pairs-log.csv";    
    std::string avg_log_fn(avg_strstrm.str());

    sdc::logger log(fct_log_fn, gp_log_fn, avg_log_fn);
    sdc::simple_drain_node_factory node_gen;
    sdc::controller ctrl;
    sdc::synth_flow_factory flw_gen("synthload.csv", 10000);
    sdc::simulator sim(&log, &node_gen, n, 1, &ctrl, &flw_gen, flw_gen.estimated_count());
    sim.run();
  }

}