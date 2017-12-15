#include "node_factory.h"

namespace sdc {

  node_factory::node_factory() {}

  sdc::node *node_factory::make_node(int node_id, int node_count, sdc::clock *clk) {
    return new sdc::node(node_id, node_count, clk);
  }

}