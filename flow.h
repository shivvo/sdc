
#ifndef SDC_FLOW_H
#define SDC_FLOW_H

#include "clock.h"

namespace sdc {
  class flow {
  private:
    // Flow info
    int m_flow_id;
    int m_size;

    // Flow start and end times
    time_t m_start_time;
    time_t m_end_time;
  public:
    
    // Constructors/destructor 
    flow(int flow_id, int size);

    // Setters 
    void set_start_time(time_t start_time);
    void set_end_time(time_t end_time);

    // Getters
    int flow_id();
    int size();
    time_t start_time();
    time_t end_time();
  };
}

#endif