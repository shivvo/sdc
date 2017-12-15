#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "simulator.h"

int n = 1024;

void get_avgs(std::string type, std::vector<double> &gps, std::vector<double> &fcts) {

  for (int i = 1; i <= n/2; i++) {
    std::ostringstream avg_strstrm;
    avg_strstrm << "logs/avg-" << type << "-" << 2*i << "-pairs-log.csv";    
    std::string avg_log_fn(avg_strstrm.str());

    std::ifstream avg_log(avg_log_fn);
    std::string line;
    std::getline(avg_log, line);
    std::getline(avg_log, line, ',');
    std::getline(avg_log, line);    

    double gp = std::stod(line);
    gps.push_back(gp);

    std::getline(avg_log, line, ',');
    std::getline(avg_log, line);    
    
    double fct = std::stod(line);
    fcts.push_back(fct);

    avg_log.close();
  }
}

int main() {
  std::vector<double> roundrobin_gp;
  std::vector<double> roundrobin_fcts;
  std::vector<double> simpledrain_gp;
  std::vector<double> simpledrain_fcts;
  get_avgs("round-robin", roundrobin_gp, roundrobin_fcts);
  get_avgs("simple-drain", simpledrain_gp, simpledrain_fcts);
  
  std::ofstream avg_gp_agg_log("logs/avg-gp-agg-log.csv");
  avg_gp_agg_log << "fraction, round-robin, simple-drain" << std::endl;
  for (int i = 1; i <= n/2; i++) {
    double frac = (double) (2*i) / n;
    avg_gp_agg_log << frac << "," << roundrobin_gp[i-1] << "," << simpledrain_gp[i-1] << std::endl;
  }
  avg_gp_agg_log.close();

  std::ofstream avg_fct_agg_log("logs/avg-fct-agg-log.csv");
  avg_fct_agg_log << "fraction, round-robin, simple-drain" << std::endl;
  for (int i = 1; i <= n/2; i++) {
    double frac = (double) (2*i) / n;
    avg_fct_agg_log << frac << "," << roundrobin_fcts[i-1] << "," << simpledrain_fcts[i-1] << std::endl;
  }
  avg_fct_agg_log.close();
}