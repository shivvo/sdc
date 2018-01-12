#include "clock.h"

namespace sdc {

  // Constructors/destructors
  
  clock::clock(unsigned long start_time) {
    m_time = start_time;
  }

  // Modify time 

  void clock::tick() {
    m_time++;
  }

  void clock::advance(unsigned long offset) {
    m_time += offset;
  }

  // Getters

  unsigned long clock::current_time() {
    return m_time;
  }
}