#ifndef SDC_CONTROLLER_H
#define SDC_CONTROLLER_H

#include "node.h"
#include "schedule.h"
#include "clock.h"

namespace sdc {

	// Controller - a centralized controller that decides a schedule when demanded
	class controller {
	private:  
    sdc::node **m_nodes;
    sdc::schedule *m_sched;
    sdc::clock *m_clk;
  public:

    // Constructors/destructor
    controller(sdc::node **nodes, sdc:scedule *sched, sdc::clock *clk);

    // Controller operations
    void run();
	};
}

#endif