#include "simple_drain_node_factory.h"

#include "simple_drain_node.h"

namespace sdc {

  simple_drain_node_factory::simple_drain_node_factory() : node_factory::node_factory() {}

  sdc::node *simple_drain_node_factory::make_node(int node_id, int node_count, sdc::clock *clk) {
    return new sdc::simple_drain_node(node_id, node_count, clk);
  }

}