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

#include <trilobite/xscience/rocket.h> // library under test

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

crocket test_rocket;

//
// XUNIT-CASES: list of test cases testing project features
//

// Test the rocket engine simulation function
XTEST_CASE(test_rocket_engine_simulation) {
    // Initialize the rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the test duration and time step
    double test_duration = 20.0;
    double time_step = 1.0;

    // Call the rocket engine simulation function
    rocket_engine_test_simulation(&test_rocket, test_duration, time_step);

    // Add assertions to check if the rocket state is as expected after the simulation
    TEST_ASSERT_FLOAT_EQUAL(5000.0 - (100.0 * time_step), test_rocket.fuel);  // Check if fuel is consumed as expected
}

// Test the Mach number calculation function
XTEST_CASE(test_mach_number_calculation) {
    // Initialize the rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the velocity and speed of sound for testing
    double velocity = 2000.0;
    double speed_of_sound = 343.0;

    // Call the Mach number calculation function
    double mach_number = rocket_calculate_mach_number(velocity, speed_of_sound);

    // Add assertions to check if the Mach number is calculated correctly
    TEST_ASSERT_FLOAT_EQUAL(5.82, mach_number);  // Replace with the expected Mach number
}

// Test the velocity reconstruction function
XTEST_CASE(test_velocity_reconstruction) {
    // Initialize the rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the Mach number and speed of sound for testing
    double mach_number = 2.0;
    double speed_of_sound = 343.0;

    // Call the velocity reconstruction function
    double reconstructed_velocity = rocket_calculate_velocity_from_mach(mach_number, speed_of_sound);

    // Add assertions to check if the reconstructed velocity is as expected
    TEST_ASSERT_FLOAT_EQUAL(686.0, reconstructed_velocity);  // Replace with the expected reconstructed velocity
}

// Test the gravitational acceleration calculation function
XTEST_CASE(test_gravitational_acceleration_calculation) {
    // Initialize the rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the altitude for testing
    double altitude = 10000.0;

    // Call the gravitational acceleration calculation function
    double gravitational_acceleration = rocket_calculate_gravitational_acceleration(altitude);

    // Add assertions to check if the gravitational acceleration is as expected
    TEST_ASSERT_FLOAT_EQUAL(9.77, gravitational_acceleration);  // Replace with the expected gravitational acceleration
}

// Test the SpaceX rocket engine simulation function
XTEST_CASE(test_test_rocket_engine_simulation) {
    // Initialize the SpaceX rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the test duration and time step
    double test_duration = 20.0;
    double time_step = 1.0;

    // Call the SpaceX rocket engine simulation function
    rocket_engine_test_simulation(&test_rocket, test_duration, time_step);

    // Add assertions to check if the SpaceX rocket state is as expected after the simulation
    TEST_ASSERT_FLOAT_EQUAL(0.0, test_rocket.velocity);  // Check if the velocity is zero after the test
    TEST_ASSERT_FLOAT_EQUAL(5000.0 - (100.0 * time_step), test_rocket.fuel);  // Check if fuel is consumed as expected
}

// Test the SpaceX rocket specific thrust during initial ascent
XTEST_CASE(test_test_rocket_specific_thrust_phase1) {
    // Initialize the SpaceX rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the velocity and fuel for testing the initial ascent phase
    test_rocket.velocity = 50.0;  // Below the velocity threshold for phase 1
    test_rocket.fuel = 1000.0;

    // Call the SpaceX rocket apply thrust function
    rocket_apply_thrust(&test_rocket, 1.0);

    // Add assertions to check if the specific thrust during phase 1 is as expected
    TEST_ASSERT_FLOAT_EQUAL(3000.0 * test_rocket.mass, test_rocket.thrust);  // Replace with the expected thrust
    TEST_ASSERT_FLOAT_EQUAL(1000.0 - (3000.0 * test_rocket.mass / 3000.0), test_rocket.fuel);  // Check if fuel is consumed as expected
}

// Test the SpaceX rocket specific thrust during constant thrust phase
XTEST_CASE(test_test_rocket_specific_thrust_phase2) {
    // Initialize the SpaceX rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the velocity and fuel for testing the constant thrust phase
    test_rocket.velocity = 200.0;  // Below the velocity threshold for phase 2
    test_rocket.fuel = 2000.0;

    // Call the SpaceX rocket apply thrust function
    rocket_apply_thrust(&test_rocket, 1.0);

    // Add assertions to check if the specific thrust during phase 2 is as expected
    TEST_ASSERT_FLOAT_EQUAL(2000.0 * test_rocket.mass, test_rocket.thrust);  // Replace with the expected thrust
    TEST_ASSERT_FLOAT_EQUAL(2000.0 - (2000.0 * test_rocket.mass / 2000.0), test_rocket.fuel);  // Check if fuel is consumed as expected
}

// Test the SpaceX rocket specific thrust during decreasing thrust phase
XTEST_CASE(test_test_rocket_specific_thrust_phase3) {
    // Initialize the SpaceX rocket state for each test
    rocket_create_for_test(&test_rocket, 0.0, 5000.0);

    // Set the velocity and fuel for testing the decreasing thrust phase
    test_rocket.velocity = 700.0;  // Below the velocity threshold for phase 3
    test_rocket.fuel = 3000.0;

    // Call the SpaceX rocket apply thrust function
    rocket_apply_thrust(&test_rocket, 1.0);

    // Add assertions to check if the specific thrust during phase 3 is as expected
    TEST_ASSERT_FLOAT_EQUAL(1000.0 * test_rocket.mass, test_rocket.thrust);  // Replace with the expected thrust
    TEST_ASSERT_FLOAT_EQUAL(3000.0 - (1000.0 * test_rocket.mass / 1000.0), test_rocket.fuel);  // Check if fuel is consumed as expected
}

XTEST_CASE(test_calculate_position) {
    // Define satellite orbit parameters
    satellite_orbit mySatelliteOrbit = {
        .semi_major_axis = 7000000.0,
        .eccentricity = 0.1,
        .inclination = 0.5,
        .mean_anomaly = 0.0,
        .argument_of_perigee = 1.0,
        .right_ascension = 2.0
    };

    // Calculate the satellite position at a given time
    double currentTime = 0.0;
    satellite_pos currentPosition = satellite_calculate_position(&mySatelliteOrbit, currentTime);

    // Define expected values based on your calculations
    // Assuming a simple scenario where X, Y, and Z are related to the semi-major axis
    double expectedX = mySatelliteOrbit.semi_major_axis * cos(mySatelliteOrbit.mean_anomaly);
    double expectedY = mySatelliteOrbit.semi_major_axis * sin(mySatelliteOrbit.mean_anomaly);
    double expectedZ = 0.0;  // Assuming a 2D orbit, so Z is zero


    TEST_ASSERT_FLOAT_EQUAL(expectedX, currentPosition.x);
    TEST_ASSERT_FLOAT_EQUAL(expectedY, currentPosition.y);
    TEST_ASSERT_FLOAT_EQUAL(expectedZ, currentPosition.z);
}

XTEST_CASE(test_orbital_period) {
    // Define satellite orbit parameters
    satellite_orbit mySatelliteOrbit = {
        .semi_major_axis = 7000000.0,
        .eccentricity = 0.1,
        .inclination = 0.5,
        .mean_anomaly = 0.0,
        .argument_of_perigee = 1.0,
        .right_ascension = 2.0
    };

    // Calculate the orbital period of the satellite
    double calculatedOrbitalPeriod = satellite_orbital_period(&mySatelliteOrbit);
    const double EARTH_MASS = 5.972e24;

    // Define expected orbital period based on Kepler's Third Law
    // T^2 is proportional to a^3 => T = K * a^(3/2), where K is a constant
    const double gravitationalConstant = 6.67430e-11;  // Gravitational constant (adjust as needed)
    double expectedOrbitalPeriod = 2.0 * M_PI * sqrt(pow(mySatelliteOrbit.semi_major_axis, 3) / (gravitationalConstant * EARTH_MASS));

    TEST_ASSERT_FLOAT_EQUAL(expectedOrbitalPeriod, calculatedOrbitalPeriod);
}

// XUNIT-GROUP: a group of test cases from the current test file

XTEST_GROUP_DEFINE(test_arospace_group) {
    XTEST_RUN_UNIT(test_rocket_engine_simulation, runner);
    XTEST_RUN_UNIT(test_mach_number_calculation, runner);
    XTEST_RUN_UNIT(test_velocity_reconstruction, runner);
    XTEST_RUN_UNIT(test_gravitational_acceleration_calculation, runner);
    XTEST_RUN_UNIT(test_test_rocket_engine_simulation,      runner);
    XTEST_RUN_UNIT(test_test_rocket_specific_thrust_phase1, runner);
    XTEST_RUN_UNIT(test_test_rocket_specific_thrust_phase2, runner);
    XTEST_RUN_UNIT(test_test_rocket_specific_thrust_phase3, runner);
    XTEST_RUN_UNIT(test_calculate_position, runner);
    XTEST_RUN_UNIT(test_orbital_period,     runner);
} // end of fixture
