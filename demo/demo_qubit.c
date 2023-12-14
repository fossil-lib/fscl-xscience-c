/*  ----------------------------------------------------------------------------
    File: demo.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xscience/qubit.h>
#include <stdio.h>

int main() {
    // Define the number of qubits in the quantum circuit
    int num_qubits = 3;

    // Create a quantum register with the specified number of qubits
    quantum_register qreg = qubit_create_register(num_qubits);

    // Apply Hadamard gates to create a superposition
    for (int i = 0; i < num_qubits; ++i) {
        qubit_apply_hadamard_gate(&qreg, i);
    }

    // Display the initial state
    printf("Initial State:\n");
    for (int i = 0; i < num_qubits; ++i) {
        printf("|%d⟩: alpha=%.3f, beta=%.3f\n", i, qreg.qubits[i].alpha, qreg.qubits[i].beta);
    }

    // Apply a Grover Search iteration
    qubit_apply_grover_search(&qreg, 1);

    // Display the state after Grover Search
    printf("\nAfter Grover Search:\n");
    for (int i = 0; i < num_qubits; ++i) {
        printf("|%d⟩: alpha=%.3f, beta=%.3f\n", i, qreg.qubits[i].alpha, qreg.qubits[i].beta);
    }

    // Measure the qubits and display the results
    printf("\nMeasurement Results:\n");
    for (int i = 0; i < num_qubits; ++i) {
        measurement_result result = qubit_measure(qreg.qubits[i]);
        printf("Qubit %d: %s\n", i, (result == ZERO) ? "|0⟩" : "|1⟩");
    }

    // Release memory occupied by the quantum register
    qubit_erase_register(&qreg);

    return 0;
} // end of func
