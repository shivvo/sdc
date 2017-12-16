#ifndef SDC_SIMPLE_DRAIN_NODE_FACTORY_H
#define SDC_SIMPLE_DRAIN_NODE_FACTORY_H

#include "node_factory.h"

namespace sdc {

  class node;

  class simple_drain_node_factory: public node_factory {
  public:
    
    // Constructors/destructor
    simple_drain_node_factory();
    
    // Make a node
    sdc::node *make_node(int node_id, int node_count, sdc::clock *clk) override;
  };

}

#endif