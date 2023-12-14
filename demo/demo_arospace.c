/*  ----------------------------------------------------------------------------
    File: demo.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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
#include <trilobite/xscience/arospace.h>
#include <stdio.h>

int main() {
    // Example usage for engine test simulation with fuel and utility functions
    crocket starship_test_with_fuel = {MASS_SPACEX_STARSHIP, 0.0, 0.0, 5000.0}; // SpaceX Starship for engine test with 5000 kg of initial fuel
    double test_duration = 20.0; // seconds
    double time_step = 1.0;      // seconds

    // Initialize rocket state for the test
    rocket_create_for_test(&starship_test_with_fuel, 0.0, 5000.0);

    // Simulate engine test with fuel consumption
    rocket_engine_test_simulation(&starship_test_with_fuel, test_duration, time_step);

    // Example usage of utility functions
    double velocity = 2000.0;  // m/s
    double speed_of_sound = 343.0;  // m/s at sea level

    double mach_number = rocket_calculate_mach_number(velocity, speed_of_sound);
    printf("Mach Number: %.2f\n", mach_number);

    double reconstructed_velocity = rocket_calculate_velocity_from_mach(mach_number, speed_of_sound);
    printf("Reconstructed Velocity: %.2f m/s\n", reconstructed_velocity);

    double altitude = 10000.0;  // meters
    double gravitational_acceleration = rocket_calculate_gravitational_acceleration(altitude);
    printf("Gravitational Acceleration at %f meters: %.2f m/s^2\n", altitude, gravitational_acceleration);

    return 0;
} // end of func
