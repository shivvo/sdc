
#ifndef SDC_SIMULATOR_H
#define SDC_SIMULATOR_H

#include "node.h"
#include "network_fabric.h"

namespace sdc {
    class simulator {
    private:
        int m_node_count;        
        sdc::node **m_nodes;
        sdc::network_fabric *m_network;
    public:
        simulator(int node_count);
        ~simulator();
        void run();
    };
}

#endif