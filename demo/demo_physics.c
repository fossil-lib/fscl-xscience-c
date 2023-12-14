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
#include <trilobite/xscience/physics.h>
#include <stdio.h>

int main() {
    // Define parameters
    double mass = 10.0;      // in kilograms
    double acceleration = 5.0;  // in meters per second squared
    double height = 20.0;    // in meters
    double velocity = 15.0;  // in meters per second
    double distance = 30.0;  // in meters
    double theta = 45.0;     // angle in degrees
    double time = 2.0;       // in seconds
    double radius = 10.0;    // in meters

    // Calculate and display results
    double force = physics_calculate_force(mass, acceleration);
    double gravitational_potential_energy = physics_calculate_gravitational_potential_energy(mass, height);
    double kinetic_energy = physics_calculate_kinetic_energy(mass, velocity);
    double work_done = physics_calculate_work_done(force, distance, theta);
    double power = physics_calculate_power(work_done, time);
    double centripetal_force = physics_calculate_centripetal_force(mass, velocity, radius);

    // Display results
    printf("Force: %.2f Newtons\n", force);
    printf("Gravitational Potential Energy: %.2f Joules\n", gravitational_potential_energy);
    printf("Kinetic Energy: %.2f Joules\n", kinetic_energy);
    printf("Work Done: %.2f Joules\n", work_done);
    printf("Power: %.2f Watts\n", power);
    printf("Centripetal Force: %.2f Newtons\n", centripetal_force);

    return 0;
} // end of func
