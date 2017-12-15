#ifndef SDC_SIMULATOR_H
#define SDC_SIMULATOR_H

#include <unordered_map>
#include "clock.h"
#include "controller.h"
#include "flow.h"
#include "flow_factory.h"
#include "logger.h"
#include "network_fabric.h"
#include "node.h"
#include "node_factory.h"
#include "schedule.h"

namespace sdc {

  // Simulator - simulates SDC
	class simulator {
	private:
    // Logger
    sdc::logger *m_log;
    // Node factory
    sdc::node_factory *m_node_gen;
    // Number of nodes in the network
		int m_node_count;
    // Clock
    sdc::clock m_clk;
    // Network schedule
    sdc::schedule m_sched;
    // Controller
    sdc::controller *m_ctrl;
    // Flow generator
    sdc::flow_factory *m_flw_gen;
    // Flows
    std::unordered_map<int, sdc::flow> m_flws;
    
    // Flow tracking
    int m_flows_max;
    int m_flows_completed;
    double m_fct_total;
    unsigned long m_time_flow_last_completed;

    // Nodes
		sdc::node **m_nodes;
    // Network fabric
    sdc::network_fabric *m_network;
    
	public:

    // Constructors/destructor
		simulator(sdc::logger *log, sdc::node_factory *node_gen, int node_count, int cycle_count, sdc::controller *ctrl, sdc::flow_factory *flw_gen, int flows_max);
		~simulator();

    // Run simulator
		void run();

    // Flow completion
    void packet_arrived(int flow_id);
	};
}

#endif