
#include <queue>
#include "packet.h"

namespace sdc {
  public class node {
    public:
      const int node_id;
      const int node_count; 
      const int[] flow_counts;
      const std::queue<packet>[] local_queues;
      

      node(int node_id, int node_count) {
        this->node_id = node_id;
        this->node_count = node_count;
        flow_counts = new int[node_count];
        local_queues = new std::queue<packet>[node_count];
        //for (int i = 0; i < node_count; i++) {
        //
        //}
      }
      
      ~node() {
        delete flow_counts;
        delete local_queues;
      }
      
      void enter_packet(sdc::packet pkt) {
        
      }
  }
}
