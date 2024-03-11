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
#ifndef FSCL_AROSPACE_H
#define FSCL_AROSPACE_H

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

// =================================================================
// Avalible functions
// =================================================================

/**
 * Creates a rocket for testing with specified initial velocity and initial fuel.
 *
 * @param rocket The rocket to create.
 * @param initial_velocity The initial velocity of the rocket.
 * @param initial_fuel The initial amount of fuel for the rocket.
 */
void fscl_rocket_create_for_test(crocket* rocket, double initial_velocity, double initial_fuel);

/**
 * Applies thrust to a rocket for a specified time step.
 *
 * @param rocket The rocket to apply thrust to.
 * @param time_step The time step for applying thrust.
 */
void fscl_rocket_apply_thrust(crocket* rocket, double time_step);

/**
 * Performs engine test simulation for a rocket over a specified duration with a given time step.
 *
 * @param rocket The rocket to simulate.
 * @param test_duration The duration of the engine test.
 * @param time_step The time step for the simulation.
 */
void fscl_rocket_engine_test_simulation(crocket* rocket, double test_duration, double time_step);

/**
 * Calculates the Mach number of a rocket given its velocity and the speed of sound.
 *
 * @param velocity The velocity of the rocket.
 * @param speed_of_sound The speed of sound.
 * @return The Mach number of the rocket.
 */
double fscl_rocket_calculate_mach_number(double velocity, double speed_of_sound);

/**
 * Calculates the velocity of a rocket from its Mach number and the speed of sound.
 *
 * @param mach_number The Mach number of the rocket.
 * @param speed_of_sound The speed of sound.
 * @return The velocity of the rocket.
 */
double fscl_rocket_calculate_velocity_from_mach(double mach_number, double speed_of_sound);

/**
 * Calculates the gravitational acceleration at a given altitude.
 *
 * @param altitude The altitude at which to calculate gravitational acceleration.
 * @return The gravitational acceleration at the specified altitude.
 */
double fscl_rocket_calculate_gravitational_acceleration(double altitude);

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

// =================================================================
// Avalible functions
// =================================================================

/**
 * Calculates the position of a satellite in its orbit at a specific time.
 *
 * @param orbit The orbit parameters of the satellite.
 * @param time The time for which to calculate the satellite position.
 * @return The position of the satellite at the specified time.
 */
satellite_pos fscl_satellite_calculate_position(const satellite_orbit* orbit, double time);

/**
 * Calculates the ground track of a satellite over a specified duration.
 *
 * @param orbit The orbit parameters of the satellite.
 * @param start_time The starting time of the ground track calculation.
 * @param duration The duration for which to calculate the ground track.
 * @param track An array to store the earth points along the ground track.
 * @param num_points The number of points in the track array.
 */
void fscl_satellite_ground_track(const satellite_orbit* orbit, double start_time, double duration, earth_point* track, int num_points);

/**
 * Calculates the orbital period of a satellite.
 *
 * @param orbit The orbit parameters of the satellite.
 * @return The orbital period of the satellite.
 */
double fscl_satellite_orbital_period(const satellite_orbit* orbit);

/**
 * Calculates the velocity of a satellite at a specific time in its orbit.
 *
 * @param orbit The orbit parameters of the satellite.
 * @param time The time for which to calculate the satellite velocity.
 * @return The velocity of the satellite at the specified time.
 */
satellite_pos fscl_satellite_velocity_at_time(const satellite_orbit* orbit, double time);

#ifdef __cplusplus
}
#endif

#endif
