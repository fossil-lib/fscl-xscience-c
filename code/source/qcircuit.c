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
#include "fossil/xscience/qcircuit.h"

#include <stdlib.h>
#include <stdio.h>

// Quantum circuit functions

qcircuit fscl_qcircuit_create(int num_qubits) {
    qcircuit circuit;
    circuit.num_qubits = num_qubits;
    circuit.qubits = (cqbit *)malloc(num_qubits * sizeof(cqbit));

    // Initialize each qubit in the circuit
    for (int i = 0; i < num_qubits; ++i) {
        circuit.qubits[i] = fscl_qbit_create();
    }

    return circuit;
}

void fscl_qcircuit_erase(qcircuit *circuit) { // Renamed from fscl_qcircuit_destroy
    free(circuit->qubits);
}

void fscl_qcircuit_hadamard(qcircuit *circuit, int qubit_index) {
    fscl_qbit_hadamard(&circuit->qubits[qubit_index]);
}

void fscl_qcircuit_pauli_x(qcircuit *circuit, int qubit_index) {
    fscl_qbit_pauli_x(&circuit->qubits[qubit_index]);
}

void fscl_qcircuit_cnot(qcircuit *circuit, int control_index, int target_index) {
    fscl_qbit_cnot(&circuit->qubits[control_index], &circuit->qubits[target_index]);
}

int* fscl_qcircuit_measure_all(qcircuit *circuit) {
    int* measurements = (int *)malloc(circuit->num_qubits * sizeof(int));

    for (int i = 0; i < circuit->num_qubits; ++i) {
        measurements[i] = fscl_qbit_measure(&circuit->qubits[i]);
    }

    return measurements;
}

// Additional quantum circuit functions

void fscl_qcircuit_reset(qcircuit *circuit) {
    for (int i = 0; i < circuit->num_qubits; ++i) {
        fscl_qbit_set_zero(&circuit->qubits[i]);
    }
}

void fscl_qcircuit_pauli_y(qcircuit *circuit, int qubit_index) {
    fscl_qbit_pauli_y(&circuit->qubits[qubit_index]);
}

void fscl_qcircuit_pauli_z(qcircuit *circuit, int qubit_index) {
    fscl_qbit_pauli_z(&circuit->qubits[qubit_index]);
}

void fscl_qcircuit_entangle(qcircuit *circuit, int qubit1_index, int qubit2_index) {
    fscl_qbit_entangle(&circuit->qubits[qubit1_index], &circuit->qubits[qubit2_index]);
}

void fscl_qcircuit_phase(qcircuit *circuit, int qubit_index) {
    fscl_qbit_phase(&circuit->qubits[qubit_index]);
}

void fscl_qcircuit_teleport(qcircuit *circuit, int source_index, int auxiliary_index, int target_index) {
    fscl_qbit_teleport(&circuit->qubits[source_index], &circuit->qubits[auxiliary_index], &circuit->qubits[target_index]);
}

void fscl_qcircuit_controlled_phase(qcircuit *circuit, int control_index, int target_index) {
    fscl_qbit_cnot(&circuit->qubits[control_index], &circuit->qubits[target_index]);
    fscl_qbit_phase(&circuit->qubits[target_index]);
    fscl_qbit_cnot(&circuit->qubits[control_index], &circuit->qubits[target_index]);
}

void fscl_qcircuit_toffoli(qcircuit *circuit, int control1_index, int control2_index, int target_index) {
    fscl_qbit_cnot(&circuit->qubits[control1_index], &circuit->qubits[target_index]);
    fscl_qbit_cnot(&circuit->qubits[control2_index], &circuit->qubits[target_index]);
    fscl_qbit_controlled_not(&circuit->qubits[control1_index], &circuit->qubits[control2_index], &circuit->qubits[target_index]);
}

void fscl_qcircuit_swap(qcircuit *circuit, int qubit1_index, int qubit2_index) {
    fscl_qbit_swap(&circuit->qubits[qubit1_index], &circuit->qubits[qubit2_index]);
}

void fscl_qcircuit_custom_gate(qcircuit *circuit, int qubit_index, void (*custom_gate)(cqbit *q)) {
    custom_gate(&circuit->qubits[qubit_index]);
}

void fscl_qcircuit_custom_two_qubit_gate(qcircuit *circuit, int control_index, int target_index, void (*custom_gate)(cqbit *control, cqbit *target)) {
    custom_gate(&circuit->qubits[control_index], &circuit->qubits[target_index]);
}

int fscl_qcircuit_measure(qcircuit *circuit, int qubit_index) {
    return fscl_qbit_measure(&circuit->qubits[qubit_index]);
}

void fscl_qcircuit_hadamard_all(qcircuit *circuit) {
    for (int i = 0; i < circuit->num_qubits; ++i) {
        fscl_qbit_hadamard(&circuit->qubits[i]);
    }
}

qcircuit fscl_qcircuit_compose(const qcircuit *circuit1, const qcircuit *circuit2) {
    qcircuit composed_circuit;
    composed_circuit.num_qubits = circuit1->num_qubits + circuit2->num_qubits;
    composed_circuit.qubits = (cqbit *)malloc(composed_circuit.num_qubits * sizeof(cqbit));

    // Copy qubits from circuit1
    for (int i = 0; i < circuit1->num_qubits; ++i) {
        composed_circuit.qubits[i] = circuit1->qubits[i];
    }

    // Copy qubits from circuit2
    for (int i = 0; i < circuit2->num_qubits; ++i) {
        composed_circuit.qubits[circuit1->num_qubits + i] = circuit2->qubits[i];
    }

    return composed_circuit;
}

void fscl_qcircuit_apply_gates_range(qcircuit *circuit, int start_index, int end_index, void (*gate_function)(cqbit *q)) {
    for (int i = start_index; i <= end_index; ++i) {
        gate_function(&circuit->qubits[i]);
    }
}

int* fscl_qcircuit_measure_range(qcircuit *circuit, int start_index, int end_index) {
    int* measurements = (int *)malloc((end_index - start_index + 1) * sizeof(int));

    for (int i = start_index; i <= end_index; ++i) {
        measurements[i - start_index] = fscl_qbit_measure(&circuit->qubits[i]);
    }

    return measurements;
}

void fscl_qcircuit_custom_gate_all(qcircuit *circuit, void (*custom_gate)(cqbit *q)) {
    for (int i = 0; i < circuit->num_qubits; ++i) {
        custom_gate(&circuit->qubits[i]);
    }
}

void fscl_qcircuit_print_range(const qcircuit *circuit, int start_index, int end_index) {
    for (int i = start_index; i <= end_index; ++i) {
        fscl_qbit_print(&circuit->qubits[i]);
    }
    printf("\n");
}
