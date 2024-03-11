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
#ifndef FSCL_fscl_qubit_H
#define FSCL_fscl_qubit_H

#ifdef __cplusplus
extern "C"
{
#endif

// Define the structure for a qubit
typedef struct {
    double alpha; // Coefficient for |0⟩ state
    double beta;  // Coefficient for |1⟩ state
} cqubit;

typedef enum {
    ZERO,
    ONE
} measurement_result;

typedef struct {
    char* name;               // Name of the gate (e.g., "Hadamard", "X", etc.)
    int target_fscl_qubit_index;   // Index of the target qubit
    // Other parameters depending on the gate type
} quantum_gate;

typedef struct {
    int size;      // Number of qubits in the register
    cqubit* qubits; // Array of qubits
} quantum_register;

typedef struct {
    double* real_part;    // Array of real parts
    double* imaginary_part; // Array of imaginary parts
    int size;             // Dimensionality of the state space
} quantum_state;

typedef struct {
    int num_qubits;             // Number of qubits in the quantum circuit
    quantum_register* qreg;     // Quantum register on which the circuit operates
    quantum_gate* gates;        // Array of quantum gates in the circuit
    int num_gates;              // Number of gates in the circuit
} quantum_circuit;

// =================================================================
// Avalible functions
// =================================================================

/**
 * Creates a quantum bit (qubit) in the |0⟩ state.
 *
 * @return The created qubit.
 */
cqubit fscl_qubit_create(void);

/**
 * Applies the Hadamard gate to a qubit.
 *
 * @param qubit The input qubit.
 * @return The qubit after applying the Hadamard gate.
 */
cqubit fscl_qubit_hadamard(cqubit qubit);

/**
 * Applies the Pauli X gate to a qubit.
 *
 * @param qubit The input qubit.
 * @return The qubit after applying the Pauli X gate.
 */
cqubit fscl_qubit_pauli_x(cqubit qubit);

/**
 * Applies the Pauli Y gate to a qubit.
 *
 * @param qubit The input qubit.
 * @return The qubit after applying the Pauli Y gate.
 */
cqubit fscl_qubit_pauli_y(cqubit qubit);

/**
 * Applies the Pauli Z gate to a qubit.
 *
 * @param qubit The input qubit.
 * @return The qubit after applying the Pauli Z gate.
 */
cqubit fscl_qubit_pauli_z(cqubit qubit);

/**
 * Applies the Controlled NOT (CNOT) gate to a pair of qubits.
 *
 * @param control The control qubit.
 * @param target The target qubit.
 * @return The target qubit after applying the CNOT gate.
 */
cqubit fscl_qubit_cnot(cqubit control, cqubit target);

/**
 * Grover Oracle function to mark the desired state.
 *
 * @param input The input qubit.
 * @return The modified qubit.
 */
cqubit grover_oracle(cqubit input);

/**
 * Applies the Hadamard gate to a specific qubit in a quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index Index of the target qubit.
 */
void fscl_qubit_apply_hadamard(quantum_register* qreg, int target_qubit_index);

/**
 * Applies the Controlled NOT (CNOT) gate to a pair of qubits in a quantum register.
 *
 * @param qreg The quantum register.
 * @param control_index Index of the control qubit.
 * @param target_index Index of the target qubit.
 */
void fscl_qubit_apply_cnot(quantum_register* qreg, int control_index, int target_index);

/**
 * Applies the Grover Oracle to a specific qubit in a quantum register.
 *
 * @param qreg The quantum register.
 * @param target_index Index of the target qubit.
 */
void fscl_qubit_apply_grover_oracle(quantum_register* qreg, int target_index);

/**
 * Applies a Grover iteration to a quantum register.
 *
 * @param qreg The quantum register.
 */
void fscl_qubit_apply_grover_iteration(quantum_register* qreg);

/**
 * Applies Grover search to a quantum register for a specified number of iterations.
 *
 * @param qreg The quantum register.
 * @param num_iterations The number of iterations for Grover search.
 */
void fscl_qubit_apply_grover_search(quantum_register* qreg, int num_iterations);

/**
 * Creates a quantum gate with a specified name and target qubit index.
 *
 * @param name The name of the gate.
 * @param target_qubit_index Index of the target qubit for the gate.
 * @return The created quantum gate.
 */
quantum_gate fscl_qubit_create_gate(const char* name, int target_qubit_index);

/**
 * Erases memory allocated for a quantum gate.
 *
 * @param gate The quantum gate to erase.
 */
void fscl_qubit_erase_gate(quantum_gate* gate);

/**
 * Creates a quantum state with a specified size.
 *
 * @param size The size of the quantum state.
 * @return The created quantum state.
 */
quantum_state fscl_qubit_create_state(int size);

/**
 * Erases memory allocated for a quantum state.
 *
 * @param state The quantum state to erase.
 */
void fscl_qubit_erase_state(quantum_state* state);

/**
 * Creates a quantum register with a specified size.
 *
 * @param size The size of the quantum register.
 * @return The created quantum register.
 */
quantum_register fscl_qubit_create_register(int size);

/**
 * Erases memory allocated for a quantum register.
 *
 * @param reg The quantum register to erase.
 */
void fscl_qubit_erase_register(quantum_register* reg);

/**
 * Creates a quantum circuit with a specified number of qubits.
 *
 * @param num_qubits The number of qubits in the circuit.
 * @return The created quantum circuit.
 */
quantum_circuit fscl_qubit_create_circuit(int num_qubits);

/**
 * Erases memory allocated for a quantum circuit.
 *
 * @param circuit The quantum circuit to erase.
 */
void fscl_qubit_erase_circuit(quantum_circuit* circuit);

/**
 * Applies the Hadamard gate to a specific qubit in a quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index Index of the target qubit.
 */
void fscl_qubit_apply_hadamard_gate(quantum_register* qreg, int target_qubit_index);

/**
 * Applies the Pauli X gate to a specific qubit in a quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index Index of the target qubit.
 */
void fscl_qubit_apply_pauli_x_gate(quantum_register* qreg, int target_qubit_index);

/**
 * Applies the Pauli Y gate to a specific qubit in a quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index Index of the target qubit.
 */
void fscl_qubit_apply_pauli_y_gate(quantum_register* qreg, int target_qubit_index);

/**
 * Applies the Pauli Z gate to a specific qubit in a quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index Index of the target qubit.
 */
void fscl_qubit_apply_pauli_z_gate(quantum_register* qreg, int target_qubit_index);

/**
 * Measures the state of a qubit and returns the measurement result.
 *
 * @param qubit The qubit to measure.
 * @return The measurement result.
 */
measurement_result fscl_qubit_measure(cqubit qubit);

/**
 * Applies a quantum gate to a qubit.
 *
 * @param gate The quantum gate to apply.
 * @param qubit The qubit to which the gate is applied.
 */
void fscl_qubit_apply_gate_to_qubit(quantum_gate* gate, cqubit* qubit);

#ifdef __cplusplus
}
#endif

#endif
