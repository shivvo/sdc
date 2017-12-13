#include "controller.h"

namespace sdc {

   // Constructors/destructor
    
   controller::controller(sdc::node **nodes, sdc:scedule *sched, sdc::clock *clk) {
      m_nodes = nodes;
      m_sched = sched;
      m_clk = clk;
   }
   
   // Controller operations
    
   void controller::run() {

   }

}