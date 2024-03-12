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

// Quantum operations
cqbit fscl_qbit_create();
void fscl_qbit_set_zero(cqbit *q);
void fscl_qbit_set_one(cqbit *q);
int fscl_qbit_measure(cqbit *q);
void fscl_qbit_hadamard(cqbit *q);
void fscl_qbit_pauli_x(cqbit *q);
void fscl_qbit_pauli_y(cqbit *q);
void fscl_qbit_pauli_z(cqbit *q);
void fscl_qbit_cnot(cqbit *control, cqbit *target);
void fscl_qbit_entangle(cqbit *qubit1, cqbit *qubit2);
void fscl_qbit_phase(cqbit *q);
void fscl_qbit_teleport(cqbit *source, cqbit *auxiliary, cqbit *target);
void fscl_qbit_swap(cqbit *qubit1, cqbit *qubit2);
void fscl_qbit_controlled_not(cqbit *control1, cqbit *control2, cqbit *target);

// Utility functions
void fscl_qbit_print(const cqbit *q);

#ifdef __cplusplus
}
#endif

#endif
