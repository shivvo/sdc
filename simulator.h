#ifndef SDC_SIMULATOR_H
#define SDC_SIMULATOR_H

#include <unordered_map>
#include "clock.h"
#include "controller.h"
#include "flow.h"
#include "flow_factory.h"
#include "network_fabric.h"
#include "node.h"

namespace sdc {

  class schedule;  

  // Simulator - simulates SDC
	class simulator {
	private:
    // Number of nodes in the network
		int m_node_count;        
    // Clock
    sdc::clock m_clk;
    // Network schedule
    sdc::schedule *m_sched;
    // Controller
    sdc::controller *m_ctrl;
    // Flow generator
    sdc::flow_factory *m_flw_gen;
    // Flows
    std::unordered_map<int, sdc::flow> m_flws;
    // Flow target tracking
    int m_flow_target;
    int m_flows_completed;

    // Nodes
		sdc::node **m_nodes;
    // Network fabric
    sdc::network_fabric *m_network;
    
	public:

    // Constructors/destructor
		simulator(int node_count, sdc::schedule &&sched, sdc::controller *ctrl, sdc::flow_factory *flw_gen, int flow_target);
		~simulator();

    // Run simulator
		void run();

    // Flow completion
    void packet_arrived(int flow_id);
	};
}

#endif