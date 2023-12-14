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
#include <trilobite/xscience/rocket.h>
#include <stdio.h>

int main() {
    // Define satellite orbit parameters
    satellite_orbit mySatelliteOrbit = {
        .semi_major_axis = 7000000.0,       // Example semi-major axis in meters
        .eccentricity = 0.1,                // Example eccentricity
        .inclination = 0.5,                 // Example inclination in radians
        .mean_anomaly = 0.0,                // Example mean anomaly in radians
        .argument_of_perigee = 1.0,         // Example argument of perigee in radians
        .right_ascension = 2.0              // Example right ascension in radians
    };

    // Calculate the satellite position at a given time
    double currentTime = 0.0;  // Example time in seconds
    satellite_pos currentPosition = satellite_calculate_position(&mySatelliteOrbit, currentTime);

    // Print the calculated position
    printf("Satellite Position at Time %.2f seconds:\n", currentTime);
    printf("X: %.2f meters\n", currentPosition.x);
    printf("Y: %.2f meters\n", currentPosition.y);
    printf("Z: %.2f meters\n", currentPosition.z);

    // Calculate the orbital period of the satellite
    double orbitalPeriod = satellite_orbital_period(&mySatelliteOrbit);

    // Print the calculated orbital period
    printf("\nOrbital Period: %.2f seconds\n", orbitalPeriod);

    // Calculate the satellite velocity at a given time
    satellite_pos currentVelocity = satellite_velocity_at_time(&mySatelliteOrbit, currentTime);

    // Print the calculated velocity
    printf("\nSatellite Velocity at Time %.2f seconds:\n", currentTime);
    printf("X Velocity: %.2f m/s\n", currentVelocity.x);
    printf("Y Velocity: %.2f m/s\n", currentVelocity.y);
    printf("Z Velocity: %.2f m/s\n", currentVelocity.z);

    // Calculate and print the ground track for a specific duration
    double startTime = 0.0;
    double duration = 3600.0;  // Example duration in seconds
    int numPoints = 10;

    earth_point groundTrack[numPoints];
    satellite_ground_track(&mySatelliteOrbit, startTime, duration, groundTrack, numPoints);

    printf("\nGround Track for %.2f seconds:\n", duration);
    for (int i = 0; i < numPoints; ++i) {
        printf("Point %d - Latitude: %.2f, Longitude: %.2f\n", i + 1, groundTrack[i].latitude, groundTrack[i].longitude);
    }

    return 0;
} // end of func
