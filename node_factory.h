#ifndef SDC_NODE_FACTORY_H
#define SDC_NODE_FACTORY_H

#include "clock.h"
#include "node.h"

namespace sdc {

  class node_factory {
  public:
    
    node_factory();
    
    virtual sdc::node *make_node(int node_id, int node_count, sdc::clock *clk);
  };

}

#endif