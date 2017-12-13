#include "schedule.h"

namespace sdc {

    // Constructors/destructor

    schedule::schedule(int **matrix, int node_count, int cycle_length) {
        m_matrix = new int *[node_count];
        for (int i = 0; i < node_count; i++) {
            m_matrix[i] = new int[cycle_length];
            for (int j = 0; j < cycle_length; j++) {
                m_matrix[i][j] = matrix[i][j];
            }
        }
        m_node_count = node_count;
        m_cycle_length = cycle_length;
    }

    schedule::~schedule() {
        for (int i = 0; i < m_node_count; i++) {
            delete m_matrix[i];
        }
        delete m_matrix;
    }

    // Access schedule information

    int schedule::target_from_source(int source_id, time_t clk_val) {
        return m_matrix[source_id][clk_val % m_cycle_length];
    }

    void schedule::set_schedule_for_node(int node_id, int *row) {
        for (int i = 0; i < m_cycle_length; i++) {
            m_matrix[node_id][i] = row[i];
        }
    }
}