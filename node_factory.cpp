#include "node_factory.h"

#include "clock.h"
#include "node.h"

namespace sdc {

  // Constructors/destructor
  node_factory::node_factory() {}

  // Make node
  sdc::node *node_factory::make_node(int node_id, int node_count, sdc::clock *clk) {
    return new sdc::node(node_id, node_count, clk);
  }

}