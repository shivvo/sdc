#ifndef SDC_FLOW_H
#define SDC_FLOW_H

#include "clock.h"

namespace sdc {
  
  // Flow - glob of data to transport through the network
  class flow {
  private:
    // Flow info
    int m_flow_id;
    int m_size;
    int m_count_arrived;
    // Source, target
    int m_source_node;
    int m_target_node;
    // Flow start and end times
    time_t m_start_time;
    time_t m_end_time;
  public:
    
    // Constructors/destructor 
    flow(int flow_id, int size);

    // Flow state
    void packet_arrived();
    bool completed();

    // Setters 
    void set_start_time(time_t start_time);
    void set_end_time(time_t end_time);
    void set_source_node(int source_node);
    void set_target_node(int target_node);

    // Getters
    int flow_id();
    int size();
    int source_node();
    int target_node();
    time_t start_time();
    time_t end_time();
  };
}

#endif