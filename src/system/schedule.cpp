#include "schedule.h"

namespace sdc {

  // Constructors/destructor

  schedule::schedule(int node_count) {
    m_matrix = new int *[node_count];    
    
    for (int i = 0; i < node_count; i++) {  
      m_matrix[i] = new int[node_count - 1];
      for (int j = 1; j < node_count; j++) {
        int node_id = (i + j) % node_count;
        m_matrix[i][j - 1] = node_id;
      }
    }

    m_node_count = node_count;
    m_cycle_length = (node_count - 1);
  }

  schedule::~schedule() {
    for (int i = 0; i < m_node_count; i++) {
      delete[] m_matrix[i];
    }
    delete[] m_matrix;
  }

  // Access schedule information

  int schedule::target_from_source(int source_id, unsigned long clk_val) {
    return m_matrix[source_id][clk_val % m_cycle_length];
  }

  // Setters

  int schedule::node_count() {
    return m_node_count;
  }

  int schedule::cycle_length() {
    return m_cycle_length;
  }

  int **schedule::matrix() {
    return m_matrix;
  }
}