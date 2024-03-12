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

#include <fossil/xscience/qubit.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_qbit_creation) {
    cqbit qubit = fscl_qbit_create();
    TEST_ASSERT_EQUAL(0, fscl_qbit_measure(&qubit));
}

XTEST_CASE(test_qbit_hadamard) {
    cqbit qubit = fscl_qbit_create();
    fscl_qbit_hadamard(&qubit);
    TEST_ASSERT_NOT_EQUAL(0, fscl_qbit_measure(&qubit));
}

XTEST_CASE(test_qbit_pauli_x) {
    cqbit qubit = fscl_qbit_create();
    fscl_qbit_pauli_x(&qubit);
    TEST_ASSERT_EQUAL(1, fscl_qbit_measure(&qubit));
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_fscl_qubit_group) {
    XTEST_RUN_UNIT(test_qbit_creation);
    XTEST_RUN_UNIT(test_qbit_hadamard);
    XTEST_RUN_UNIT(test_qbit_pauli_x);
} // end of fixture
