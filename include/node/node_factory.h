#ifndef SDC_NODE_FACTORY_H
#define SDC_NODE_FACTORY_H

namespace sdc {

  class clock;
  class node;

  // Node factory - abstractly produce nodes implementations
  class node_factory {
  public:
    
    // Constructors/destructor
    node_factory();
    
    // Make node
    virtual sdc::node *make_node(int node_id, int node_count, sdc::clock *clk);
  };

}

#endif