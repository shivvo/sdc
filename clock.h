
#ifndef SDC_CLOCK_H
#define SDC_CLOCK_H

using time_t = unsigned long;

namespace sdc {
  class clock {
  private:
    // Time value
    time_t m_time;
  public:
    
    // Constructors/destructors
    clock(time_t start_time);
    
    // Modify time 
    void tick();
    void advance(time_t offset);
  
    // Getters
    time_t current_time();
  };
}

#endif