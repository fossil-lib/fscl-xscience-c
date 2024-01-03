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

XTEST_CASE(test_hadamard_gate) {
    cqubit qubit = fscl_qubit_create();
    qubit = fscl_qubit_hadamard(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0 / sqrt(2), qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0 / sqrt(2), qubit.beta);
}

XTEST_CASE(test_pauli_x_gate) {
    cqubit qubit = fscl_qubit_create();
    qubit = fscl_qubit_pauli_x(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0, qubit.beta);
}

XTEST_CASE(test_pauli_y_gate) {
    cqubit qubit = fscl_qubit_create();
    qubit = fscl_qubit_pauli_y(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, -1.0, qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, qubit.beta);
}

XTEST_CASE(test_pauli_z_gate) {
    cqubit qubit = fscl_qubit_create();
    qubit = fscl_qubit_pauli_z(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0, qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, -1.0, qubit.beta);
}

XTEST_CASE(test_cnot_gate) {
    cqubit control = fscl_qubit_create();
    cqubit target = fscl_qubit_create();
    cqubit result = fscl_qubit_cnot(control, target);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, control.alpha * target.alpha, result.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, control.beta * target.beta, result.beta);
}

XTEST_CASE(test_grover_oracle) {
    cqubit input = fscl_qubit_create();
    cqubit result = grover_oracle(input);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, input.alpha, result.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, -input.beta, result.beta);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_fscl_qubit_group) {
    XTEST_RUN_UNIT(test_hadamard_gate);
    XTEST_RUN_UNIT(test_pauli_x_gate);
    XTEST_RUN_UNIT(test_grover_oracle);
    XTEST_RUN_UNIT(test_cnot_gate);
    XTEST_RUN_UNIT(test_pauli_z_gate);
    XTEST_RUN_UNIT(test_pauli_y_gate);
} // end of fixture
