
namespace sdc {
  public class packet {
    public:
      const int source_node;
      const int target_node;
      const int flow_id;
      const int seq_num;
  
      Packet(int source_node, int target_node, int flow_id, int seq_num) {
        this->source_node = source_node;
        this->target_node = target_node;
        this->flow_id = flow_id;
        this->seq_num = seq_num;
      }
  }
}
