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

#include <trilobite/xscience/physics.h> // library under test

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE(test_calculate_force) {
    // Test the calculate_force function
    double mass = 10.0;
    double acceleration = 5.0;

    double result = physics_calculate_force(mass, acceleration);
    TEST_ASSERT_DOUBLE_EQUAL(50.0, result);
}

// Test case for physics_calculate_gravitational_potential_energy
XTEST_CASE(test_calculate_gravitational_potential_energy) {
    // Test the calculate_gravitational_potential_energy function
    double mass = 10.0;
    double height = 20.0;
    double expected_result = physics_calculate_gravitational_potential_energy(mass, height, GRAVITY_EARTH);

    // Call the function under test
    double result = physics_calculate_gravitational_potential_energy(mass, height, GRAVITY_EARTH);

    // Assert the result
    TEST_ASSERT_DOUBLE_EQUAL(expected_result, result);
}

XTEST_CASE(test_calculate_kinetic_energy) {
    // Test the calculate_kinetic_energy function
    double mass = 10.0;
    double velocity = 15.0;

    double result = physics_calculate_kinetic_energy(mass, velocity);
    TEST_ASSERT_DOUBLE_EQUAL(1125.0, result);
}

XTEST_CASE(test_calculate_work_done) {
    // Test the calculate_work_done function
    double force = 30.0;
    double distance = 10.0;
    double theta = M_PI / 4.0; // 45 degrees

    double result = physics_calculate_work_done(force, distance, theta);
    TEST_ASSERT_DOUBLE_EQUAL(150.0 * sqrt(2.0), result);

    // Additional edge case: Check with negative distance
    distance = -5.0;
    result = physics_calculate_work_done(force, distance, theta);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);

    // Additional edge case: Check with theta outside the valid range (0 to pi radians)
    theta = M_PI + 0.1; // Slightly more than pi radians
    result = physics_calculate_work_done(force, distance, theta);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);
}

XTEST_CASE(test_calculate_power) {
    // Test the calculate_power function
    double work_done = 120.0;
    double time = 6.0;

    double result = physics_calculate_power(work_done, time);
    TEST_ASSERT_DOUBLE_EQUAL(20.0, result);

    // Additional edge case: Check with zero time
    time = 0.0;
    result = physics_calculate_power(work_done, time);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);

    // Additional edge case: Check with negative work_done
    work_done = -50.0;
    time = 10.0;
    result = physics_calculate_power(work_done, time);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);
}

XTEST_CASE(test_calculate_centripetal_force) {
    // Test the calculate_centripetal_force function
    double mass = 8.0;
    double velocity = 12.0;
    double radius = 5.0;

    double result = physics_calculate_centripetal_force(mass, velocity, radius);
    TEST_ASSERT_DOUBLE_EQUAL(28.8, result);

    // Additional edge case: Check with zero radius
    radius = 0.0;
    result = physics_calculate_centripetal_force(mass, velocity, radius);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);

    // Additional edge case: Check with negative velocity
    velocity = -10.0;
    radius = 6.0;
    result = physics_calculate_centripetal_force(mass, velocity, radius);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_GROUP_DEFINE(test_physics_group) {
    XTEST_RUN_UNIT(test_calculate_force, runner);
    XTEST_RUN_UNIT(test_calculate_gravitational_potential_energy, runner);
    XTEST_RUN_UNIT(test_calculate_kinetic_energy, runner);
    XTEST_RUN_UNIT(test_calculate_work_done, runner);
    XTEST_RUN_UNIT(test_calculate_power, runner);
    XTEST_RUN_UNIT(test_calculate_centripetal_force, runner);
} // end of fixture
