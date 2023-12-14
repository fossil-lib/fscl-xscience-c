/*  ----------------------------------------------------------------------------
    File: xunit_runner.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

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
#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

#include <trilobite/xscience/qubit.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_hadamard_gate) {
    cqubit qubit = qubit_create();
    qubit = qubit_hadamard(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0 / sqrt(2), qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0 / sqrt(2), qubit.beta);
}

XTEST_CASE(test_pauli_x_gate) {
    cqubit qubit = qubit_create();
    qubit = qubit_pauli_x(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0, qubit.beta);
}

XTEST_CASE(test_pauli_y_gate) {
    cqubit qubit = qubit_create();
    qubit = qubit_pauli_y(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, -1.0, qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, qubit.beta);
}

XTEST_CASE(test_pauli_z_gate) {
    cqubit qubit = qubit_create();
    qubit = qubit_pauli_z(qubit);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0, qubit.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, -1.0, qubit.beta);
}

XTEST_CASE(test_cnot_gate) {
    cqubit control = qubit_create();
    cqubit target = qubit_create();
    cqubit result = qubit_cnot(control, target);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, control.alpha * target.alpha, result.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, control.beta * target.beta, result.beta);
}

XTEST_CASE(test_grover_oracle) {
    cqubit input = qubit_create();
    cqubit result = grover_oracle(input);

    TEST_ASSERT_DOUBLE_WITHIN(0.0001, input.alpha, result.alpha);
    TEST_ASSERT_DOUBLE_WITHIN(0.0001, -input.beta, result.beta);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_GROUP_DEFINE(test_qubit_group) {
    XTEST_RUN_UNIT(test_hadamard_gate, runner);
    XTEST_RUN_UNIT(test_pauli_x_gate,  runner);
    XTEST_RUN_UNIT(test_grover_oracle, runner);
    XTEST_RUN_UNIT(test_cnot_gate,     runner);
    XTEST_RUN_UNIT(test_pauli_z_gate,  runner);
    XTEST_RUN_UNIT(test_pauli_y_gate,  runner);
} // end of fixture
