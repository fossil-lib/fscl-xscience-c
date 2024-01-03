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
cqubit fscl_qubit_create(void);
cqubit fscl_qubit_hadamard(cqubit qubit);
cqubit fscl_qubit_pauli_x(cqubit qubit);
cqubit fscl_qubit_pauli_y(cqubit qubit);
cqubit fscl_qubit_pauli_z(cqubit qubit);
cqubit fscl_qubit_cnot(cqubit control, cqubit target);
cqubit grover_oracle(cqubit input);
void fscl_qubit_apply_hadamard(quantum_register* qreg, int target_fscl_qubit_index);
void fscl_qubit_apply_cnot(quantum_register* qreg, int control_index, int target_index);
void fscl_qubit_apply_grover_oracle(quantum_register* qreg, int target_index);
void fscl_qubit_apply_grover_iteration(quantum_register* qreg);
void fscl_qubit_apply_grover_search(quantum_register* qreg, int num_iterations);
quantum_gate fscl_qubit_create_gate(const char* name, int target_fscl_qubit_index);
void fscl_qubit_erase_gate(quantum_gate* gate);
quantum_state fscl_qubit_create_state(int size);
void fscl_qubit_erase_state(quantum_state* state);
quantum_register fscl_qubit_create_register(int size);
void fscl_qubit_erase_register(quantum_register* reg);
quantum_circuit fscl_qubit_create_circuit(int num_qubits);
void fscl_qubit_erase_circuit(quantum_circuit* circuit);
void fscl_qubit_apply_hadamard_gate(quantum_register* qreg, int target_fscl_qubit_index);
void fscl_qubit_apply_pauli_x_gate(quantum_register* qreg, int target_fscl_qubit_index);
void fscl_qubit_apply_pauli_y_gate(quantum_register* qreg, int target_fscl_qubit_index);
void fscl_qubit_apply_pauli_z_gate(quantum_register* qreg, int target_fscl_qubit_index);
measurement_result fscl_qubit_measure(cqubit qubit);
void fscl_qubit_apply_gate_to_qubit(quantum_gate* gate, cqubit* qubit);

#ifdef __cplusplus
}
#endif

#endif