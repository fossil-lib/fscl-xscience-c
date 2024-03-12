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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#include <fossil/xscience/qcircuit.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_qcircuit_creation) {
    qcircuit circuit = fscl_qcircuit_create(3);
    TEST_ASSERT_EQUAL(3, circuit.num_qubits);
}

XTEST_CASE(test_qcircuit_hadamard) {
    qcircuit circuit = fscl_qcircuit_create(1);
    fscl_qcircuit_hadamard(&circuit, 0);
    TEST_ASSERT_EQUAL(0, fscl_qcircuit_measure(&circuit, 0));
}

XTEST_CASE(test_qcircuit_cnot) {
    qcircuit circuit = fscl_qcircuit_create(2);
    fscl_qcircuit_cnot(&circuit, 0, 1);
    TEST_ASSERT_EQUAL(0, fscl_qcircuit_measure(&circuit, 0));
    TEST_ASSERT_EQUAL(0, fscl_qcircuit_measure(&circuit, 1));
}

XTEST_CASE(test_qcircuit_entanglement) {
    qcircuit circuit = fscl_qcircuit_create(2);
    fscl_qcircuit_entangle(&circuit, 0, 1);
    fscl_qcircuit_hadamard(&circuit, 0);
    TEST_ASSERT_EQUAL(fscl_qcircuit_measure(&circuit, 0), fscl_qcircuit_measure(&circuit, 1));
}

XTEST_CASE(test_qcircuit_composition) {
    qcircuit circuit1 = fscl_qcircuit_create(2);
    fscl_qcircuit_hadamard(&circuit1, 0);

    qcircuit circuit2 = fscl_qcircuit_create(1);
    fscl_qcircuit_hadamard(&circuit2, 0);

    qcircuit composed_circuit = fscl_qcircuit_compose(&circuit1, &circuit2);

    TEST_ASSERT_EQUAL(3, composed_circuit.num_qubits);
    TEST_ASSERT_EQUAL(0, fscl_qcircuit_measure(&composed_circuit, 0));
    TEST_ASSERT_EQUAL(0, fscl_qcircuit_measure(&composed_circuit, 1));
    TEST_ASSERT_EQUAL(0, fscl_qcircuit_measure(&composed_circuit, 2));
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_fscl_qcircuit_group) {
    XTEST_RUN_UNIT(test_qcircuit_creation);
    XTEST_RUN_UNIT(test_qcircuit_hadamard);
    XTEST_RUN_UNIT(test_qcircuit_cnot);
    XTEST_RUN_UNIT(test_qcircuit_entanglement);
    XTEST_RUN_UNIT(test_qcircuit_composition);
} // end of fixture