/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_QUBIT_H
#define TSCL_QUBIT_H

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
    int target_qubit_index;   // Index of the target qubit
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

/**
 * @brief Initializes a qubit in the |0⟩ state.
 *
 * @return The initialized qubit.
 */
cqubit qubit_create(void);

/**
 * @brief Applies the Hadamard gate to a qubit.
 *
 * @param qubit The qubit to which the Hadamard gate is applied.
 * @return The resulting qubit state.
 */
cqubit qubit_hadamard(cqubit qubit);

/**
 * @brief Applies the Pauli X gate (bit flip) to a qubit.
 *
 * @param qubit The qubit to which the Pauli X gate is applied.
 * @return The resulting qubit state.
 */
cqubit qubit_pauli_x(cqubit qubit);

/**
 * @brief Applies the Pauli Y gate to a qubit.
 *
 * @param qubit The qubit to which the Pauli Y gate is applied.
 * @return The resulting qubit state.
 */
cqubit qubit_pauli_y(cqubit qubit);

/**
 * @brief Applies the Pauli Z gate to a qubit.
 *
 * @param qubit The qubit to which the Pauli Z gate is applied.
 * @return The resulting qubit state.
 */
cqubit qubit_pauli_z(cqubit qubit);

/**
 * @brief Performs a controlled-NOT (CNOT) operation.
 *
 * @param control The control qubit.
 * @param target The target qubit.
 * @return The resulting target qubit state.
 */
cqubit qubit_cnot(cqubit control, cqubit target);

/**
 * @brief Grover Oracle: Applies a phase flip for the target state.
 *
 * @param input The input qubit.
 * @return The resulting qubit state.
 */
cqubit grover_oracle(cqubit input);

/**
 * @brief Performs a Hadamard gate on a specific qubit in the quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index The index of the target qubit.
 */
void qubit_apply_hadamard(quantum_register* qreg, int target_qubit_index);

/**
 * @brief Applies a controlled-NOT (CNOT) operation to two qubits.
 *
 * @param qreg The quantum register.
 * @param control_index The index of the control qubit.
 * @param target_index The index of the target qubit.
 */
void qubit_apply_cnot(quantum_register* qreg, int control_index, int target_index);

/**
 * @brief Applies a Grover Oracle phase flip to a target qubit.
 *
 * @param qreg The quantum register.
 * @param target_index The index of the target qubit.
 */
void qubit_apply_grover_oracle(quantum_register* qreg, int target_index);

/**
 * @brief Applies a Grover Iteration to a quantum register.
 *
 * @param qreg The quantum register.
 */
void qubit_apply_grover_iteration(quantum_register* qreg);

/**
 * @brief Applies Grover Search to a quantum register.
 *
 * @param qreg The quantum register.
 * @param num_iterations The number of iterations for Grover Search.
 */
void qubit_apply_grover_search(quantum_register* qreg, int num_iterations);

/**
 * @brief Initializes a quantum gate.
 *
 * @param name The name of the gate.
 * @param target_qubit_index The index of the target qubit.
 * @return The initialized quantum gate.
 */
quantum_gate qubit_create_gate(const char* name, int target_qubit_index);

/**
 * @brief Releases memory occupied by a quantum gate.
 *
 * @param gate The quantum gate to be released.
 */
void qubit_erase_gate(quantum_gate* gate);

/**
 * @brief Initializes a quantum state.
 *
 * @param size The size of the quantum state.
 * @return The initialized quantum state.
 */
quantum_state qubit_create_state(int size);

/**
 * @brief Releases memory occupied by a quantum state.
 *
 * @param state The quantum state to be released.
 */
void qubit_erase_state(quantum_state* state);

/**
 * @brief Initializes a quantum register.
 *
 * @param size The size of the quantum register.
 * @return The initialized quantum register.
 */
quantum_register qubit_create_register(int size);

/**
 * @brief Releases memory occupied by a quantum register.
 *
 * @param reg The quantum register to be released.
 */
void qubit_erase_register(quantum_register* reg);

/**
 * @brief Initializes a quantum circuit.
 *
 * @param num_qubits The number of qubits in the quantum circuit.
 * @return The initialized quantum circuit.
 */
quantum_circuit qubit_create_circuit(int num_qubits);

/**
 * @brief Releases memory occupied by a quantum circuit.
 *
 * @param circuit The quantum circuit to be released.
 */
void qubit_erase_circuit(quantum_circuit* circuit);

/**
 * @brief Performs a Hadamard gate on a specific qubit in the quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index The index of the target qubit.
 */
void qubit_apply_hadamard_gate(quantum_register* qreg, int target_qubit_index);

/**
 * @brief Performs a Pauli X gate on a specific qubit in the quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index The index of the target qubit.
 */
void qubit_apply_pauli_x_gate(quantum_register* qreg, int target_qubit_index);

/**
 * @brief Performs a Pauli Y gate on a specific qubit in the quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index The index of the target qubit.
 */
void qubit_apply_pauli_y_gate(quantum_register* qreg, int target_qubit_index);

/**
 * @brief Performs a Pauli Z gate on a specific qubit in the quantum register.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index The index of the target qubit.
 */
void qubit_apply_pauli_z_gate(quantum_register* qreg, int target_qubit_index);

/**
 * @brief Measures a specific qubit in the quantum register and returns the result.
 *
 * @param qreg The quantum register.
 * @param target_qubit_index The index of the target qubit.
 * @return The measurement result (0 or 1).
 */
measurement_result qubit_measure(cqubit qubit);

/**
 * @brief Applies a quantum gate to a specific qubit in the quantum register.
 *
 * @param gate The quantum gate to be applied.
 * @param qubit The qubit to which the gate is applied.
 */
void qubit_apply_gate_to_qubit(quantum_gate* gate, cqubit* qubit);

#ifdef __cplusplus
}
#endif

#endif