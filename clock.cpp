#include "clock.h"

namespace sdc {

  // Constructors/destructors
  
  clock::clock(time_t start_time) {
    m_time = start_time;
  }

  // Modify time 

  void clock::tick() {
    m_time++;
  }

  void clock::advance(time_t offset) {
    m_time += offset;
  }

  // Getters

  time_t clock::current_time() {
    return m_time;
  }
}