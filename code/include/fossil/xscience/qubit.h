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
#ifndef FSCL_QBIT_H
#define FSCL_QBIT_H

#ifdef __cplusplus
extern "C"
{
#endif

// Define the qubit structure
typedef struct {
    int state;  // 0 for |0⟩, 1 for |1⟩
} cqbit;

// =================================================================
// Avalible functions
// =================================================================

/**
 * Creates a quantum bit (qubit).
 *
 * @return The created quantum bit.
 */
cqbit fscl_qbit_create();

/**
 * Sets the quantum bit to the zero state.
 *
 * @param q The quantum bit to be set to zero.
 */
void fscl_qbit_set_zero(cqbit *q);

/**
 * Sets the quantum bit to the one state.
 *
 * @param q The quantum bit to be set to one.
 */
void fscl_qbit_set_one(cqbit *q);

/**
 * Measures the quantum bit, returning the measurement result (0 or 1).
 *
 * @param q The quantum bit to be measured.
 * @return The measurement result (0 or 1).
 */
int fscl_qbit_measure(cqbit *q);

/**
 * Applies the Hadamard gate to the quantum bit.
 *
 * @param q The quantum bit to which the Hadamard gate is applied.
 */
void fscl_qbit_hadamard(cqbit *q);

/**
 * Applies the Pauli-X gate to the quantum bit.
 *
 * @param q The quantum bit to which the Pauli-X gate is applied.
 */
void fscl_qbit_pauli_x(cqbit *q);

/**
 * Applies the Pauli-Y gate to the quantum bit.
 *
 * @param q The quantum bit to which the Pauli-Y gate is applied.
 */
void fscl_qbit_pauli_y(cqbit *q);

/**
 * Applies the Pauli-Z gate to the quantum bit.
 *
 * @param q The quantum bit to which the Pauli-Z gate is applied.
 */
void fscl_qbit_pauli_z(cqbit *q);

/**
 * Applies the CNOT (Controlled NOT) gate to the given control and target qubits.
 *
 * @param control The control qubit.
 * @param target The target qubit.
 */
void fscl_qbit_cnot(cqbit *control, cqbit *target);

/**
 * Entangles two qubits, creating an entangled state between them.
 *
 * @param qubit1 The first qubit to be entangled.
 * @param qubit2 The second qubit to be entangled.
 */
void fscl_qbit_entangle(cqbit *qubit1, cqbit *qubit2);

/**
 * Applies the phase gate to the quantum bit.
 *
 * @param q The quantum bit to which the phase gate is applied.
 */
void fscl_qbit_phase(cqbit *q);

/**
 * Teleports the state of the source qubit to the target qubit using an auxiliary qubit.
 *
 * @param source The source qubit.
 * @param auxiliary The auxiliary qubit.
 * @param target The target qubit.
 */
void fscl_qbit_teleport(cqbit *source, cqbit *auxiliary, cqbit *target);

/**
 * Swaps the states of two qubits.
 *
 * @param qubit1 The first qubit.
 * @param qubit2 The second qubit.
 */
void fscl_qbit_swap(cqbit *qubit1, cqbit *qubit2);

/**
 * Applies the Controlled NOT (CNOT) gate with two control qubits and one target qubit.
 *
 * @param control1 The first control qubit.
 * @param control2 The second control qubit.
 * @param target The target qubit.
 */
void fscl_qbit_controlled_not(cqbit *control1, cqbit *control2, cqbit *target);

/**
 * Prints the state of the quantum bit.
 *
 * @param q The quantum bit to be printed.
 */
void fscl_qbit_print(const cqbit *q);

#ifdef __cplusplus
}
#endif

#endif
