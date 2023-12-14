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

#include <trilobite/xscience/robotics.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_distance) {
    TEST_ASSERT_DOUBLE_EQUAL(5.196, robotic_distance(1.0, 2.0, 3.0, 4.0, 5.0, 6.0));
}

XTEST_CASE(test_dot_product) {
    TEST_ASSERT_DOUBLE_EQUAL(56.0, robotic_dot_product(2.0, 3.0, 4.0, 5.0, 6.0, 7.0));
}

XTEST_CASE(test_cross_product) {
    double resultX, resultY, resultZ;
    robotic_cross_product(2.0, 3.0, 4.0, 5.0, 6.0, 7.0, &resultX, &resultY, &resultZ);
    TEST_ASSERT_DOUBLE_EQUAL(-3.0, resultX);
    TEST_ASSERT_DOUBLE_EQUAL(6.0, resultY);
    TEST_ASSERT_DOUBLE_EQUAL(-3.0, resultZ);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_GROUP_DEFINE(test_robotics_group) {
    XTEST_RUN_UNIT(test_distance, runner);
    XTEST_RUN_UNIT(test_dot_product, runner);
    XTEST_RUN_UNIT(test_cross_product, runner);
} // end of fixture
