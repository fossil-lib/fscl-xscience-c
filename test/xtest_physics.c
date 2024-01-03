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

#include <fossil/xscience/physics.h> // library under test

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

    double result = fscl_physics_calculate_force(mass, acceleration);
    TEST_ASSERT_DOUBLE_EQUAL(50.0, result);
}

// Test case for fscl_physics_calculate_gravitational_potential_energy
XTEST_CASE(test_calculate_gravitational_potential_energy) {
    // Test the calculate_gravitational_potential_energy function
    double mass = 10.0;
    double height = 20.0;
    double expected_result = fscl_physics_calculate_gravitational_potential_energy(mass, height, GRAVITY_EARTH);

    // Call the function under test
    double result = fscl_physics_calculate_gravitational_potential_energy(mass, height, GRAVITY_EARTH);

    // Assert the result
    TEST_ASSERT_DOUBLE_EQUAL(expected_result, result);
}

XTEST_CASE(test_calculate_kinetic_energy) {
    // Test the calculate_kinetic_energy function
    double mass = 10.0;
    double velocity = 15.0;

    double result = fscl_physics_calculate_kinetic_energy(mass, velocity);
    TEST_ASSERT_DOUBLE_EQUAL(1125.0, result);
}

XTEST_CASE(test_calculate_work_done) {
    // Test the calculate_work_done function
    double force = 30.0;
    double distance = 10.0;
    double theta = M_PI / 4.0; // 45 degrees

    double result = fscl_physics_calculate_work_done(force, distance, theta);
    TEST_ASSERT_DOUBLE_EQUAL(150.0 * sqrt(2.0), result);

    // Additional edge case: Check with negative distance
    distance = -5.0;
    result = fscl_physics_calculate_work_done(force, distance, theta);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);

    // Additional edge case: Check with theta outside the valid range (0 to pi radians)
    theta = M_PI + 0.1; // Slightly more than pi radians
    result = fscl_physics_calculate_work_done(force, distance, theta);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);
}

XTEST_CASE(test_calculate_power) {
    // Test the calculate_power function
    double work_done = 120.0;
    double time = 6.0;

    double result = fscl_physics_calculate_power(work_done, time);
    TEST_ASSERT_DOUBLE_EQUAL(20.0, result);

    // Additional edge case: Check with zero time
    time = 0.0;
    result = fscl_physics_calculate_power(work_done, time);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);

    // Additional edge case: Check with negative work_done
    work_done = -50.0;
    time = 10.0;
    result = fscl_physics_calculate_power(work_done, time);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);
}

XTEST_CASE(test_calculate_centripetal_force) {
    // Test the calculate_centripetal_force function
    double mass = 8.0;
    double velocity = 12.0;
    double radius = 5.0;

    double result = fscl_physics_calculate_centripetal_force(mass, velocity, radius);
    TEST_ASSERT_DOUBLE_EQUAL(28.8, result);

    // Additional edge case: Check with zero radius
    radius = 0.0;
    result = fscl_physics_calculate_centripetal_force(mass, velocity, radius);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);

    // Additional edge case: Check with negative velocity
    velocity = -10.0;
    radius = 6.0;
    result = fscl_physics_calculate_centripetal_force(mass, velocity, radius);
    TEST_ASSERT_DOUBLE_EQUAL(0.0, result);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_fscl_physics_group) {
    XTEST_RUN_UNIT(test_calculate_force);
    XTEST_RUN_UNIT(test_calculate_gravitational_potential_energy);
    XTEST_RUN_UNIT(test_calculate_kinetic_energy);
    XTEST_RUN_UNIT(test_calculate_work_done);
    XTEST_RUN_UNIT(test_calculate_power);
    XTEST_RUN_UNIT(test_calculate_centripetal_force);
} // end of fixture
