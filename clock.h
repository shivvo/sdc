#ifndef SDC_CLOCK_H
#define SDC_CLOCK_H

namespace sdc {
  
  // Clock - used for timing SDC operation
  class clock {
  private:
    // Time value
    unsigned long m_time;
  public:
    
    // Constructors/destructors
    clock(unsigned long start_time);
    
    // Modify time 
    void tick();
    void advance(unsigned long offset);
  
    // Getters
    unsigned long current_time();
  };
}

#endif