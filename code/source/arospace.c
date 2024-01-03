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
#include "fossil/xscience/arospace.h"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

// Constants for rocket masses
const double MASS_SPACEX_FALCON_9 = 549054;
const double MASS_SPACEX_FALCON_HEAVY = 1420788;
const double MASS_SPACEX_STARSHIP = 120000;

// Constants for NASA rocket masses
const double MASS_NASA_SLS = 2300000;
const double MASS_NASA_SLS_BLOCK_1B = 2600000;
const double MASS_NASA_ORION = 26000;

// Constants for other US-built rocket masses
const double MASS_BOEING_DELTA_IV_HEAVY = 733000;
const double MASS_BLUE_ORIGIN_NEW_GLENN = 4500000;

// Earth's orbital parameters
const double EARTH_ORBITAL_RADIUS = 149.6e9;
const double EARTH_ORBITAL_PERIOD = 365.25 * 24 * 3600;

// Threshold altitudes for state transitions (example values, adjust as needed)
const double ASCENT_THRESHOLD_ALTITUDE = 50000.0;
const double DESCENT_THRESHOLD_ALTITUDE = 30000.0;
const double MISSION_END_ALTITUDE = 100000.0;

// Gravitational acceleration constant
const double GRAVITATIONAL_ACCELERATION = 9.81;

// Earth gravitational constant (9.81 m/s^2 at sea level)
const double GRAVITY_CONSTANT = 9.81;

// Function to initialize rocket state for engine test
void fscl_rocket_create_for_test(crocket* rocket, double initial_velocity, double initial_fuel) {
    rocket->velocity = initial_velocity;
    rocket->fuel = initial_fuel;
}

// Function to apply thrust during engine test, considering fuel consumption
void fscl_rocket_apply_thrust(crocket* rocket, double time_step) {
    // Applying specific thrust rules during different phases of the rocket's flight

    // Phase 1: Initial ascent (up to velocity of 100 m/s)
    if (rocket->velocity < 100.0 && rocket->fuel > 0.0) {
        double specific_thrust_phase1 = 3000.0;  // newtons per kilogram
        rocket->thrust = specific_thrust_phase1 * rocket->mass;
        rocket->fuel -= (rocket->thrust / specific_thrust_phase1) * time_step;
    } // Phase 2: Constant specific thrust (up to velocity of 500 m/s)
    else if (rocket->velocity < 500.0 && rocket->fuel > 0.0) {
        double specific_thrust_phase2 = 2000.0;  // newtons per kilogram
        rocket->thrust = specific_thrust_phase2 * rocket->mass;
        rocket->fuel -= (rocket->thrust / specific_thrust_phase2) * time_step;
    } // Phase 3: Decreasing specific thrust (up to velocity of 1000 m/s)
    else if (rocket->velocity < 1000.0 && rocket->fuel > 0.0) {
        double specific_thrust_phase3 = 1000.0;  // newtons per kilogram
        rocket->thrust = specific_thrust_phase3 * rocket->mass;
        rocket->fuel -= (rocket->thrust / specific_thrust_phase3) * time_step;
    }
    // Turn off thrust if velocity limit is reached or fuel is depleted
    else {
        rocket->thrust = 0.0;
    }
}

// Adapter function to determine rocket state based on thrust value
RocketState determine_fscl_rocket_state(double thrust) {
    // Adjust the conditions based on your specific requirements
    if (thrust > 0.0) {
        return ASCENT;
    } else if (thrust < 0.0) {
        return DESCENT;
    } else {
        return COAST;
    }
}

// Function to update rocket state based on dynamics using a state machine
void fscl_rocket_update_state(crocket* rocket, double thrust, double time_step) {
    // Determine the rocket state based on the current thrust
    RocketState state = determine_fscl_rocket_state(thrust);

    switch (state) {
        case ASCENT:
            // Update velocity, position, and other parameters for ascent
            rocket->velocity += thrust / rocket->mass * time_step;
            // Update position based on velocity (basic integration)
            rocket->position += rocket->velocity * time_step;

            // Check for conditions to transition to the next state (e.g., reaching a certain altitude)
            if (rocket->position >= ASCENT_THRESHOLD_ALTITUDE) {
                // Perform additional actions or end the simulation as needed
            }
            break;

        case DESCENT:
            // Update velocity, position, and other parameters for descent
            rocket->velocity -= thrust / rocket->mass * time_step;
            // Update position based on velocity (basic integration)
            rocket->position += rocket->velocity * time_step;

            // Check for conditions to transition to the next state (e.g., reaching a certain altitude)
            if (rocket->position <= DESCENT_THRESHOLD_ALTITUDE) {
                // Perform additional actions or end the simulation as needed
            }
            break;

        case COAST:
            // Update velocity, position, and other parameters for coasting
            // For simplicity, let's assume no thrust during coasting
            // Update position based on velocity (basic integration)
            rocket->velocity += GRAVITATIONAL_ACCELERATION * time_step;  // Gravity affects the rocket during coasting
            rocket->position += rocket->velocity * time_step;

            // Check for conditions to transition to the next state (e.g., reaching the end of the mission)
            if (rocket->position >= MISSION_END_ALTITUDE) {
                // Perform additional actions or end the simulation as needed
            }
            break;

        // Add more states and transitions as needed

        default:
            // Handle unexpected state (optional)
            break;
    }
}

// Function to simulate rocket engine test considering fuel
void fscl_rocket_engine_test_simulation(crocket* rocket, double test_duration, double time_step) {
    for (double time = 0.0; time <= test_duration; time += time_step) {
        // Apply thrust and fuel consumption during the test
        fscl_rocket_apply_thrust(rocket, time_step);

        // Update rocket state using the new fscl_rocket_update_state function
        fscl_rocket_update_state(rocket, rocket->thrust, time_step);

        // Output information (optional)
        printf("Time: %.2f s, Velocity: %.2f m/s, Fuel: %.2f kg\n", time, rocket->velocity, rocket->fuel);
    }
}

// Function to calculate Mach number from velocity
double fscl_rocket_calculate_mach_number(double velocity, double speed_of_sound) {
    // Mach number formula: Mach = velocity / speed_of_sound
    return velocity / speed_of_sound;
}

// Function to calculate velocity from Mach number
double fscl_rocket_calculate_velocity_from_mach(double mach_number, double speed_of_sound) {
    // Velocity formula: velocity = Mach * speed_of_sound
    return mach_number * speed_of_sound;
}

// Function to calculate gravitational acceleration at a given altitude
double fscl_rocket_calculate_gravitational_acceleration(double altitude) {
    // Gravitational acceleration formula: g = G * (M / (R + altitude)^2)
    // where G is the gravitational constant, M is the mass of Earth, R is Earth's radius
    const double EARTH_MASS = 5.972e24;  // kilograms
    const double EARTH_RADIUS = 6371000.0;  // meters

    return GRAVITY_CONSTANT * (EARTH_MASS / pow((EARTH_RADIUS + altitude), 2));
}

// Function to calculate the satellite position at a given time
satellite_pos fscl_satellite_calculate_position(const satellite_orbit* orbit, double time) {
    satellite_pos position;

    // Constants
    const double G = 6.67430e-11; // gravitational constant
    const double M = 5.972e24;    // mass of the Earth

    // Orbital parameters
    double a = orbit->semi_major_axis;
    double e = orbit->eccentricity;
    double i = orbit->inclination;
    double M0 = orbit->mean_anomaly;
    double w = orbit->argument_of_perigee;
    double Omega = orbit->right_ascension;

    // Calculate mean motion
    double n = sqrt(G * M / (a * a * a));

    // Calculate mean anomaly
    double M_at_t = M0 + n * time;

    // Solve Kepler's equation for eccentric anomaly
    double E = M_at_t;
    double E_prev;
    do {
        E_prev = E;
        E = M_at_t + e * sin(E_prev);
    } while (fabs(E - E_prev) > 1e-12);

    // Calculate true anomaly
    double v = 2 * atan2(sqrt(1 + e) * sin(E / 2), sqrt(1 - e) * cos(E / 2));

    // Calculate satellite position in the orbital plane
    double r = a * (1 - e * cos(E));
    double x_orbital = r * (cos(Omega) * cos(w + v) - sin(Omega) * sin(w + v));
    double y_orbital = r * (sin(Omega) * cos(w + v) + cos(Omega) * sin(w + v));

    // Rotate the position to the Earth-centered inertial frame
    position.x = x_orbital * cos(i) - y_orbital * sin(i);
    position.y = x_orbital * sin(i) + y_orbital * cos(i);
    position.z = 0; // For simplicity, assuming the orbit is in the equatorial plane

    return position;
}

// Function to calculate the satellite velocity at a given time
satellite_pos fscl_satellite_velocity_at_time(const satellite_orbit* orbit, double time) {
    satellite_pos velocity;

    // Constants
    const double G = 6.67430e-11; // gravitational constant
    const double M = 5.972e24;    // mass of the Earth

    // Orbital parameters
    double a = orbit->semi_major_axis;
    double e = orbit->eccentricity;
    double M0 = orbit->mean_anomaly;
    double w = orbit->argument_of_perigee;
    double Omega = orbit->right_ascension;

    // Calculate mean motion
    double n = sqrt(G * M / (a * a * a));

    // Calculate mean anomaly
    double M_at_t = M0 + n * time;

    // Solve Kepler's equation for eccentric anomaly
    double E = M_at_t;
    double E_prev;
    do {
        E_prev = E;
        E = M_at_t + e * sin(E_prev);
    } while (fabs(E - E_prev) > 1e-12);

    // Calculate true anomaly
    double v = 2 * atan2(sqrt(1 + e) * sin(E / 2), sqrt(1 - e) * cos(E / 2));

    // Calculate specific angular momentum
    double h = sqrt(G * M * a * (1 - e * e));

    // Calculate radial and transverse components of velocity
    double vr = (G * M / h) * e * sin(v);
    double vt = h / a;

    // Calculate satellite velocity in the orbital plane
    velocity.x = vr * (cos(Omega) * cos(w + v) - sin(Omega) * sin(w + v)) - vt * (cos(Omega) * sin(w + v) + sin(Omega) * cos(w + v));
    velocity.y = vr * (sin(Omega) * cos(w + v) + cos(Omega) * sin(w + v)) + vt * (sin(Omega) * sin(w + v) - cos(Omega) * cos(w + v));
    velocity.z = 0; // For simplicity, assuming the orbit is in the equatorial plane

    return velocity;
}

// Function to calculate the orbital period of the satellite
double fscl_satellite_orbital_period(const satellite_orbit* orbit) {
    // Constants
    const double G = 6.67430e-11; // gravitational constant
    const double M = 5.972e24;    // mass of the Earth

    // Orbital parameter
    double a = orbit->semi_major_axis;

    // Calculate orbital period
    double T = 2 * M_PI * sqrt(a * a * a / (G * M));

    return T;
}

// Function to calculate the ground track of the satellite
void fscl_satellite_ground_track(const satellite_orbit* orbit, double start_time, double duration, earth_point* track, int num_points) {
    // Implementation needed based on the specific requirements and algorithms for calculating the ground track.
    // This function might involve solving complex equations and considering factors like satellite altitude, Earth's rotation, and orbital parameters.
    // The implementation might require external libraries or additional data.

    // For simplicity, return a straight line along the equator as a placeholder.
    double delta_longitude = 360.0 / num_points;
    for (int i = 0; i < num_points; ++i) {
        track[i].latitude = 0; // Equator
        track[i].longitude = i * delta_longitude;
    }
}
