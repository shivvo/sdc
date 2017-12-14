
#include <iostream>

#include "simulator.h"

int main() {
	std::cout << "hello, world!" << std::endl;
  int n = 1024;
  int pair_count = n / 8;
  sdc::controller ctrl;
  sdc::flow_factory flw_gen(pair_count, (n-1)*(n-1));
  sdc::simulator sim(n, 1, &ctrl, &flw_gen, pair_count);
  sim.run();
}