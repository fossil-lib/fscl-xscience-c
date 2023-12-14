/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_ROCKET_H
#define TSCL_ROCKET_H

#include <math.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Constants for rocket masses
extern const double MASS_SPACEX_FALCON_9;        // mass of SpaceX Falcon 9 in kilograms
extern const double MASS_SPACEX_FALCON_HEAVY;    // mass of SpaceX Falcon Heavy in kilograms
extern const double MASS_SPACEX_STARSHIP;        // mass of SpaceX Starship in kilograms

// Constants for NASA rocket masses
extern const double MASS_NASA_SLS;               // mass of NASA Space Launch System (SLS) in kilograms
extern const double MASS_NASA_SLS_BLOCK_1B;      // mass of NASA SLS Block 1B in kilograms
extern const double MASS_NASA_ORION;             // mass of NASA Orion spacecraft in kilograms

// Constants for other US-built rocket masses
extern const double MASS_BOEING_DELTA_IV_HEAVY;  // mass of Boeing Delta IV Heavy in kilograms
extern const double MASS_BLUE_ORIGIN_NEW_GLENN;  // mass of Blue Origin New Glenn in kilograms

// Earth's orbital parameters
extern const double EARTH_ORBITAL_RADIUS;        // average radius of Earth's orbit around the Sun in meters (semi-major axis)
extern const double EARTH_ORBITAL_PERIOD;        // orbital period of Earth around the Sun in seconds

// Threshold altitudes for state transitions (example values, adjust as needed)
extern const double ASCENT_THRESHOLD_ALTITUDE;   // Altitude to transition from ascent to descent
extern const double DESCENT_THRESHOLD_ALTITUDE;  // Altitude to transition from descent to coast
extern const double MISSION_END_ALTITUDE;        // Altitude to end the simulation

// Gravitational acceleration constant
extern const double GRAVITATIONAL_ACCELERATION;  // m/s^2 (standard gravity at sea level on Earth)

// Earth gravitational constant (9.81 m/s^2 at sea level)
extern const double GRAVITY_CONSTANT;

// Enumeration for rocket states
typedef enum {
    ASCENT,
    DESCENT,
    COAST
} RocketState;

// Structure to represent a rocket
// Structure to represent a rocket
typedef struct {
    double mass;      // Rocket mass in kilograms
    double thrust;    // Rocket thrust in newtons
    double velocity;  // Rocket velocity in m/s
    double fuel;      // Rocket fuel in kilograms
    double position;  // Rocket position in meters (added for the state machine example)
} crocket;

// Structure to represent a rocket state machine
typedef struct {
    RocketState state;  // Current state of the rocket
    double ascent_thrust;  // Thrust during ascent phase
    double descent_thrust;  // Thrust during descent phase
} RocketStateMachine;

/**
 * @brief Initializes rocket state for an engine test.
 *
 * @param rocket Pointer to the rocket structure to be initialized.
 * @param initial_velocity Initial velocity of the rocket.
 * @param initial_fuel Initial amount of fuel for the rocket.
 */
void rocket_create_for_test(crocket* rocket, double initial_velocity, double initial_fuel);

/**
 * @brief Applies thrust during an engine test, considering fuel consumption.
 *
 * @param rocket Pointer to the rocket structure.
 * @param time_step Time step for the thrust application.
 */
void rocket_apply_thrust(crocket* rocket, double time_step);

/**
 * @brief Simulates a rocket engine test considering fuel.
 *
 * @param rocket Pointer to the rocket structure.
 * @param test_duration Duration of the engine test.
 * @param time_step Time step for the simulation.
 */
void rocket_engine_test_simulation(crocket* rocket, double test_duration, double time_step);

/**
 * @brief Calculates Mach number from velocity.
 *
 * @param velocity Velocity of the rocket.
 * @param speed_of_sound Speed of sound in the medium.
 * @return Calculated Mach number.
 */
double rocket_calculate_mach_number(double velocity, double speed_of_sound);

/**
 * @brief Calculates velocity from Mach number.
 *
 * @param mach_number Mach number of the rocket.
 * @param speed_of_sound Speed of sound in the medium.
 * @return Calculated velocity.
 */
double rocket_calculate_velocity_from_mach(double mach_number, double speed_of_sound);

/**
 * @brief Calculates gravitational acceleration at a given altitude.
 *
 * @param altitude Altitude above the Earth's surface.
 * @return Calculated gravitational acceleration.
 */
double rocket_calculate_gravitational_acceleration(double altitude);

typedef struct {
    double semi_major_axis; // in meters
    double eccentricity;
    double inclination; // in radians
    double mean_anomaly; // in radians
    double argument_of_perigee; // in radians
    double right_ascension; // in radians
} satellite_orbit;

typedef struct {
    double x;
    double y;
    double z;
} satellite_pos;

// Define a structure to represent a point on the Earth's surface
typedef struct {
    double latitude;
    double longitude;
} earth_point;

/**
 * @brief Calculate the satellite position at a given time.
 *
 * @param orbit Pointer to the satellite orbit parameters.
 * @param time The time at which to calculate the satellite position.
 * @return The calculated satellite position.
 */
satellite_pos satellite_calculate_position(const satellite_orbit* orbit, double time);

/**
 * @brief Calculate the ground track given a starting time and duration.
 *
 * @param orbit Pointer to the satellite orbit parameters.
 * @param start_time The starting time for calculating the ground track.
 * @param duration The duration for which to calculate the ground track.
 * @param track Array to store the calculated ground track points.
 * @param num_points The number of points in the ground track array.
 */
void satellite_ground_track(const satellite_orbit* orbit, double start_time, double duration, earth_point* track, int num_points);

/**
 * @brief Calculate the orbital period of the satellite.
 *
 * @param orbit Pointer to the satellite orbit parameters.
 * @return The orbital period of the satellite.
 */
double satellite_orbital_period(const satellite_orbit* orbit);

/**
 * @brief Calculate the satellite velocity at a given time.
 *
 * @param orbit Pointer to the satellite orbit parameters.
 * @param time The time at which to calculate the satellite velocity.
 * @return The calculated satellite velocity.
 */
satellite_pos satellite_velocity_at_time(const satellite_orbit* orbit, double time);

#ifdef __cplusplus
}
#endif

#endif