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
#include "fossil/xscience/qubit.h"
#include <stdio.h>
#include <stdlib.h>

// Create and initialize a qubit in the |0⟩ state
cqbit fscl_qbit_create() {
    cqbit q;
    q.state = 0;
    return q;
}

// Set the qubit to |0⟩ state
void fscl_qbit_set_zero(cqbit *q) {
    if (q != NULL) {
        q->state = 0;
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_set_zero.\n");
        exit(EXIT_FAILURE);
    }
}

// Set the qubit to |1⟩ state
void fscl_qbit_set_one(cqbit *q) {
    if (q != NULL) {
        q->state = 1;
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_set_one.\n");
        exit(EXIT_FAILURE);
    }
}

// Measure the qubit and return the result (0 or 1)
int fscl_qbit_measure(cqbit *q) {
    if (q != NULL) {
        return q->state;
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_measure.\n");
        exit(EXIT_FAILURE);
    }
}

// Apply Hadamard gate to the qubit
void fscl_qbit_hadamard(cqbit *q) {
    if (q != NULL) {
        q->state = 1 - q->state;  // For simplicity, just toggle the state
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_hadamard.\n");
        exit(EXIT_FAILURE);
    }
}

// Apply Pauli X gate to the qubit (bit flip)
void fscl_qbit_pauli_x(cqbit *q) {
    if (q != NULL) {
        q->state = 1 - q->state;  // Bit flip
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_pauli_x.\n");
        exit(EXIT_FAILURE);
    }
}

// Apply Pauli Y gate to the qubit (bit flip and phase flip)
void fscl_qbit_pauli_y(cqbit *q) {
    if (q != NULL) {
        q->state = 1 - q->state;  // Bit flip
        // For simplicity, also introduce a phase flip (change the sign)
        // This is an approximation as a real Pauli Y gate includes a complex phase factor
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_pauli_y.\n");
        exit(EXIT_FAILURE);
    }
}

// Apply Pauli Z gate to the qubit (phase flip)
void fscl_qbit_pauli_z(cqbit *q) {
    if (q != NULL) {
        // For simplicity, introduce a phase flip (change the sign)
        // This is an approximation as a real Pauli Z gate includes a complex phase factor
        q->state = -q->state;
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_pauli_z.\n");
        exit(EXIT_FAILURE);
    }
}

// Apply Controlled NOT (CNOT) gate to two qubits
void fscl_qbit_cnot(cqbit *control, cqbit *target) {
    if (control != NULL && target != NULL) {
        if (control->state == 1) {
            // Flip the target qubit if the control qubit is in state |1⟩
            fscl_qbit_pauli_x(target);
        }
        // If the control qubit is in state |0⟩, do nothing
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_cnot.\n");
        exit(EXIT_FAILURE);
    }
}

// Create an entangled state between two qubits
void fscl_qbit_entangle(cqbit *qubit1, cqbit *qubit2) {
    if (qubit1 != NULL && qubit2 != NULL) {
        fscl_qbit_hadamard(qubit1);      // Apply Hadamard to the first qubit
        fscl_qbit_cnot(qubit1, qubit2);  // Apply CNOT to create entanglement
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_entangle.\n");
        exit(EXIT_FAILURE);
    }
}

// Apply Phase gate to the qubit
void fscl_qbit_phase(cqbit *q) {
    if (q != NULL) {
        // For simplicity, introduce a phase shift (change the sign)
        // This is an approximation as a real Phase gate includes a complex phase factor
        q->state = -q->state;
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_phase.\n");
        exit(EXIT_FAILURE);
    }
}

// Simulate quantum teleportation between three qubits
void fscl_qbit_teleport(cqbit *source, cqbit *auxiliary, cqbit *target) {
    if (source != NULL && auxiliary != NULL && target != NULL) {
        // Step 1: Create an entangled state between the source and auxiliary qubits
        fscl_qbit_entangle(auxiliary, source);

        // Step 2: Apply Hadamard and CNOT gates to the auxiliary qubit
        fscl_qbit_hadamard(auxiliary);
        fscl_qbit_cnot(source, auxiliary);

        // Step 3: Measure the source and auxiliary qubits
        int measurement1 = fscl_qbit_measure(source);
        int measurement2 = fscl_qbit_measure(auxiliary);

        // Step 4: Apply corrections to the target qubit based on measurements
        if (measurement2 == 1) {
            fscl_qbit_pauli_x(target);  // Bit flip if auxiliary is |1⟩
        }
        if (measurement1 == 1) {
            fscl_qbit_pauli_z(target);  // Phase flip if source is |1⟩
        }
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_teleport.\n");
        exit(EXIT_FAILURE);
    }
}

// Swap the state of two qubits
void fscl_qbit_swap(cqbit *qubit1, cqbit *qubit2) {
    int temp_state = qubit1->state;
    qubit1->state = qubit2->state;
    qubit2->state = temp_state;
}

// Apply a controlled NOT (CNOT) gate between control and target qubits
void fscl_qbit_controlled_not(cqbit *control, cqbit *target) {
    if (control->state == 1) {
        fscl_qbit_pauli_x(target);
    }
}

// Print the state of the qubit
void fscl_qbit_print(const cqbit *q) {
    if (q != NULL) {
        printf("Qubit State: |%d⟩\n", q->state);
    } else {
        fprintf(stderr, "Error: Null pointer in fscl_qbit_print.\n");
        exit(EXIT_FAILURE);
    }
}
