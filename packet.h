
#ifndef SDC_PACKET_H
#define SDC_PACKET_H

namespace sdc {
  class packet {
  private:
    // Source, target
    int m_source_node;
    int m_target_node;
    // Flow information
    int m_flow_id;
    int m_seq_num;
    // Time entered into network and time exited
    int m_enter_time;
    int m_exit_time;
  public:
    // Constructors and destructors
    packet(int source_node, int target_node, int flow_id, int seq_num);
    packet();

    // Setters
    void set_enter_time(int enter_time);
    void set_exit_time(int exit_time);

    // Getters
    int source_node();
    int target_node();
    int flow_id();
    int seq_num();
    int enter_time();
    int exit_time();
  };
}

#endif