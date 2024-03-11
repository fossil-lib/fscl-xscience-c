/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FSCL_QCIRCUIT_H
#define FSCL_QCIRCUIT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "qubits.h"

// Define the quantum circuit structure
typedef struct {
    int num_qubits;
    cqbit *qubits;  // Array of qubits in the circuit
} qcircuit;

// =================================================================
// Avalible functions
// =================================================================

// Quantum circuit functions
qcircuit fscl_qcircuit_create(int num_qubits);
void fscl_qcircuit_destroy(qcircuit *circuit);
void fscl_qcircuit_hadamard(qcircuit *circuit, int qubit_index);
void fscl_qcircuit_pauli_x(qcircuit *circuit, int qubit_index);
void fscl_qcircuit_cnot(qcircuit *circuit, int control_index, int target_index);
int* fscl_qcircuit_measure_all(qcircuit *circuit);

// Additional quantum circuit functions
void fscl_qcircuit_reset(qcircuit *circuit);
void fscl_qcircuit_pauli_y(qcircuit *circuit, int qubit_index);
void fscl_qcircuit_pauli_z(qcircuit *circuit, int qubit_index);
void fscl_qcircuit_entangle(qcircuit *circuit, int qubit1_index, int qubit2_index);
void fscl_qcircuit_phase(qcircuit *circuit, int qubit_index);
void fscl_qcircuit_teleport(qcircuit *circuit, int source_index, int auxiliary_index, int target_index);
void fscl_qcircuit_controlled_phase(qcircuit *circuit, int control_index, int target_index);
void fscl_qcircuit_toffoli(qcircuit *circuit, int control1_index, int control2_index, int target_index);
void fscl_qcircuit_swap(qcircuit *circuit, int qubit1_index, int qubit2_index);
void fscl_qcircuit_custom_gate(qcircuit *circuit, int qubit_index, void (*custom_gate)(cqbit *q));
void fscl_qcircuit_custom_two_qubit_gate(qcircuit *circuit, int control_index, int target_index, void (*custom_gate)(cqbit *control, cqbit *target));
int fscl_qcircuit_measure(qcircuit *circuit, int qubit_index);
void fscl_qcircuit_hadamard_all(qcircuit *circuit);
qcircuit fscl_qcircuit_compose(const qcircuit *circuit1, const qcircuit *circuit2);
void fscl_qcircuit_apply_gates_range(qcircuit *circuit, int start_index, int end_index, void (*gate_function)(cqbit *q));
int* fscl_qcircuit_measure_range(qcircuit *circuit, int start_index, int end_index);
void fscl_qcircuit_custom_gate_all(qcircuit *circuit, void (*custom_gate)(cqbit *q));
void fscl_qcircuit_print_range(const qcircuit *circuit, int start_index, int end_index);

#ifdef __cplusplus
}
#endif

#endif