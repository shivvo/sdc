#ifndef SDC_PACKET_H
#define SDC_PACKET_H

namespace sdc {
  
  // Packet - unit of transport in SDC
  class packet {
  private:
    // Source, target
    int m_source_node;
    int m_target_node;
    // Flow information
    int m_flow_id;
    int m_seq_num;
  public:
    
    // Constructors and destructors
    packet(int source_node, int target_node, int flow_id, int seq_num);

    // Getters
    int source_node();
    int target_node();
    int flow_id();
    int seq_num();
  };
}

#endif