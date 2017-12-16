#ifndef SDC_CONTROLLER_H
#define SDC_CONTROLLER_H

namespace sdc {
  
  class node;
  class schedule;
  class clock;

  // Controller - centralized controller that decides schedules
  class controller {  
  public:
    
    // Constructors/destructors
    controller();

    // Controller operations
    void update_schedule(sdc::schedule *sched, sdc::node **nodes, sdc::clock *clk);

  };
  
}

#endif