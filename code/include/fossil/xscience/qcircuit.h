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

#include "fossil/xscience/qubit.h"

// Define the quantum circuit structure
typedef struct {
    int num_qubits;
    cqbit *qubits;  // Array of qubits in the circuit
} qcircuit;

// =================================================================
// Avalible functions
// =================================================================

/**
 * Creates a quantum circuit with the specified number of qubits.
 *
 * @param num_qubits The number of qubits in the quantum circuit.
 * @return The created quantum circuit.
 */
qcircuit fscl_qcircuit_create(int num_qubits);

/**
 * Destroys the quantum circuit, freeing allocated memory.
 *
 * @param circuit The quantum circuit to be destroyed.
 */
void fscl_qcircuit_destroy(qcircuit *circuit);

/**
 * Applies the Hadamard gate to the specified qubit in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit_index The index of the qubit to which the Hadamard gate is applied.
 */
void fscl_qcircuit_hadamard(qcircuit *circuit, int qubit_index);

/**
 * Applies the Pauli-X gate to the specified qubit in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit_index The index of the qubit to which the Pauli-X gate is applied.
 */
void fscl_qcircuit_pauli_x(qcircuit *circuit, int qubit_index);

/**
 * Applies the Controlled NOT (CNOT) gate to the specified control and target qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param control_index The index of the control qubit.
 * @param target_index The index of the target qubit.
 */
void fscl_qcircuit_cnot(qcircuit *circuit, int control_index, int target_index);

/**
 * Measures all qubits in the quantum circuit, returning an array of measurement results.
 * The caller is responsible for freeing the memory allocated for the result array.
 *
 * @param circuit The quantum circuit to be measured.
 * @return An array of measurement results (0 or 1) for each qubit.
 */
int* fscl_qcircuit_measure_all(qcircuit *circuit);

/**
 * Resets all qubits in the quantum circuit to the |0⟩ state.
 *
 * @param circuit The quantum circuit.
 */
void fscl_qcircuit_reset(qcircuit *circuit);

/**
 * Applies the Pauli-Y gate to the specified qubit in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit_index The index of the qubit to which the Pauli-Y gate is applied.
 */
void fscl_qcircuit_pauli_y(qcircuit *circuit, int qubit_index);

/**
 * Applies the Pauli-Z gate to the specified qubit in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit_index The index of the qubit to which the Pauli-Z gate is applied.
 */
void fscl_qcircuit_pauli_z(qcircuit *circuit, int qubit_index);

/**
 * Entangles two qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit1_index The index of the first qubit.
 * @param qubit2_index The index of the second qubit.
 */
void fscl_qcircuit_entangle(qcircuit *circuit, int qubit1_index, int qubit2_index);

/**
 * Applies the phase gate to the specified qubit in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit_index The index of the qubit to which the phase gate is applied.
 */
void fscl_qcircuit_phase(qcircuit *circuit, int qubit_index);

/**
 * Teleports the state of one qubit to another in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param source_index The index of the source qubit.
 * @param auxiliary_index The index of the auxiliary qubit.
 * @param target_index The index of the target qubit.
 */
void fscl_qcircuit_teleport(qcircuit *circuit, int source_index, int auxiliary_index, int target_index);

/**
 * Applies the controlled-phase gate to the specified control and target qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param control_index The index of the control qubit.
 * @param target_index The index of the target qubit.
 */
void fscl_qcircuit_controlled_phase(qcircuit *circuit, int control_index, int target_index);

/**
 * Applies the Toffoli gate to the specified control and target qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param control1_index The index of the first control qubit.
 * @param control2_index The index of the second control qubit.
 * @param target_index The index of the target qubit.
 */
void fscl_qcircuit_toffoli(qcircuit *circuit, int control1_index, int control2_index, int target_index);

/**
 * Swaps the states of two qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit1_index The index of the first qubit.
 * @param qubit2_index The index of the second qubit.
 */
void fscl_qcircuit_swap(qcircuit *circuit, int qubit1_index, int qubit2_index);

/**
 * Applies a custom gate to the specified qubit in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param qubit_index The index of the qubit to which the custom gate is applied.
 * @param custom_gate The custom gate function.
 */
void fscl_qcircuit_custom_gate(qcircuit *circuit, int qubit_index, void (*custom_gate)(cqbit *q));

/**
 * Applies a custom two-qubit gate to the specified control and target qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param control_index The index of the control qubit.
 * @param target_index The index of the target qubit.
 * @param custom_gate The custom two-qubit gate function.
 */
void fscl_qcircuit_custom_two_qubit_gate(qcircuit *circuit, int control_index, int target_index, void (*custom_gate)(cqbit *control, cqbit *target));

/**
 * Measures the specified qubit in the quantum circuit, returning the measurement result (0 or 1).
 *
 * @param circuit The quantum circuit.
 * @param qubit_index The index of the qubit to be measured.
 * @return The measurement result (0 or 1).
 */
int fscl_qcircuit_measure(qcircuit *circuit, int qubit_index);

/**
 * Applies the Hadamard gate to all qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 */
void fscl_qcircuit_hadamard_all(qcircuit *circuit);

/**
 * Composes two quantum circuits, concatenating them into a new quantum circuit.
 *
 * @param circuit1 The first quantum circuit.
 * @param circuit2 The second quantum circuit.
 * @return The composed quantum circuit.
 */
qcircuit fscl_qcircuit_compose(const qcircuit *circuit1, const qcircuit *circuit2);

/**
 * Applies a custom gate function to a range of qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param start_index The starting index of the qubits to apply the gate to.
 * @param end_index The ending index of the qubits to apply the gate to.
 * @param gate_function The custom gate function to apply.
 */
void fscl_qcircuit_apply_gates_range(qcircuit *circuit, int start_index, int end_index, void (*gate_function)(cqbit *q));

/**
 * Measures a range of qubits in the quantum circuit, returning an array of measurement results (0 or 1).
 *
 * @param circuit The quantum circuit.
 * @param start_index The starting index of the qubits to measure.
 * @param end_index The ending index of the qubits to measure.
 * @return An array of measurement results (0 or 1).
 */
int* fscl_qcircuit_measure_range(qcircuit *circuit, int start_index, int end_index);

/**
 * Applies a custom gate function to all qubits in a range of the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param custom_gate The custom gate function to apply.
 */
void fscl_qcircuit_custom_gate_all(qcircuit *circuit, void (*custom_gate)(cqbit *q));

/**
 * Prints the state of a range of qubits in the quantum circuit.
 *
 * @param circuit The quantum circuit.
 * @param start_index The starting index of the qubits to print.
 * @param end_index The ending index of the qubits to print.
 */
void fscl_qcircuit_print_range(const qcircuit *circuit, int start_index, int end_index);

#ifdef __cplusplus
}
#endif

#endif