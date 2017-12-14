#ifndef SDC_FLOW_H
#define SDC_FLOW_H

namespace sdc {
  
  // Flow - glob of data to transport through the network
  class flow {
  private:
    // Flow info
    int m_flow_id;
    int m_size;
    int m_count_arrived;
    // Source, target
    int m_source_node;
    int m_target_node;
    // Flow start and end times
    unsigned long m_start_time;
    unsigned long m_end_time;
  public:
    
    // Constructors/destructor 
    flow(int flow_id, int size);
    flow(const flow &other);
    flow();

    // Flow state
    void packet_arrived();
    bool completed();
    double fct();

    // Setters 
    void set_start_time(unsigned long start_time);
    void set_end_time(unsigned long end_time);
    void set_source_node(int source_node);
    void set_target_node(int target_node);

    // Getters
    int flow_id();
    int size();
    int source_node();
    int target_node();
    unsigned long start_time();
    unsigned long end_time();
  };
}

#endif