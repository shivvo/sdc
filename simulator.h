#ifndef SDC_SIMULATOR_H
#define SDC_SIMULATOR_H

#include "node.h"
#include "network_fabric.h"
#include "clock.h"
#include "schedule.h"

namespace sdc {

  // Simulator - simulates SDC
	class simulator {
	private:
    // Number of nodes in the network
		int m_node_count;        
    // Nodes
		sdc::node **m_nodes;
    // Network fabric
    sdc::network_fabric m_network;
    // Network schedule
    sdc::schedule m_sched;
    // Clock
    sdc::clock m_clock;
	public:

    // Constructors/destructor
		simulator(int node_count);
		~simulator();

    // Run simulator
		void run();

    // Flow completion
    void packet_arrived(int flow_id);
	};
}

#endif