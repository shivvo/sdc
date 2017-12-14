
#include <iostream>

#include "simulator.h"

int main() {
	std::cout << "hello, world!" << std::endl;
  int n = 1024;
  int pair_count = n / 4;

  sdc::logger log("fct-log.csv", "gp-log.csv", "avg-log.csv");
  sdc::controller ctrl;
  sdc::flow_factory flw_gen(pair_count, (n-1));
  sdc::simulator sim(&log, n, 1, &ctrl, &flw_gen, pair_count);
  sim.run();
}