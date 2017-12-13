
#include <iostream>

#include "simulator.h"

int main() {
	std::cout << "hello, world!" << std::endl;
  int n = 256;
  sdc::controller ctrl;
  sdc::flow_factory flw_gen(n, n-1);
  sdc::simulator sim(n, sdc::std_sched(n, 1), &ctrl, &flw_gen, n);
}