#ifndef SDC_SCHEDULE_H
#define SDC_SCHEDULE_H

#include "clock.h"

namespace sdc {

  // Schedule: a schedule for transmitting packets to nodes
  class schedule {
  private:
    // Schedule state
    int **m_matrix;
    int m_node_count;
    int m_cycle_length;
  public:
    
    // Constuctors/destructor
    schedule(int **matrix, int node_count, int cycle_lenth);
    ~schedule();

    // Access schedule information
    int target_from_source(int source_node, time_t clk_val);
  };
}

#endif