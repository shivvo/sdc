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

    // Access/modify schedule information
    int target_from_source(int source_node, unsigned long clk_val);
    void set_schedule_for_node(int node_id, int *row);
  };

  schedule std_sched(int node_count, int cycle_count);

}

#endif