#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>

#include "simulator.h"

int n = 1024;

int main() {

  std::default_random_engine generator;

  std::normal_distribution<double> small_rng(100, 25);
  std::normal_distribution<double> big_rng(10000, 250);
  std::exponential_distribution<> time_rng(1 / 300.0);
  std::uniform_int_distribution<> node_rng(0, 1023);
  std::uniform_real_distribution<> small_big_rng(0, 1);

  std::ofstream synthload("synthload.csv");
  double total_time = 0; 
  for (int i = 0; i < 10000; i++) {
    double next_time = time_rng(generator);
    while (next_time <= 0) next_time = time_rng(generator);
    total_time += next_time;
    int size = 0;
    if (small_big_rng(generator) < 0.1) {
      size = (int) big_rng(generator);
    } else {
      size = (int) small_rng(generator);
    }

    int source = 0, target = 0;
    source = node_rng(generator);
    while ((target = node_rng(generator)) == source);
    
    synthload << i << " " << size << " " << source << " " << target << " " << (unsigned long) (total_time) << std::endl; 
  }
  synthload.close();
}