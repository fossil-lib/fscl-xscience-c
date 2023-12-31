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
#include "fossil/xscience/physics.h"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

celestial GRAVITY_SUN     = 274.0;
celestial GRAVITY_MERCURY = 3.7;
celestial GRAVITY_VENUS   = 8.87;
celestial GRAVITY_JUPITER = 24.79;
celestial GRAVITY_SATURN  = 10.44;
celestial GRAVITY_URANUS  = 8.69;
celestial GRAVITY_NEPTUNE = 11.15;
celestial GRAVITY_EARTH   = 9.81;
celestial GRAVITY_MOON    = 1.625;
celestial GRAVITY_MARS    = 3.72076;

// Function to calculate force using Newton's second law: force = mass * acceleration
double fscl_physics_calculate_force(double mass, double acceleration) {
    // Check for invalid input parameters
    if (mass <= 0.0) {
        fprintf(stderr, "Error: Mass must be a positive value.\n");
        return 0.0;
    }

    return mass * acceleration;
} // end of func

// Function to calculate gravitational potential energy: potential_energy = mass * gravity * height
double fscl_physics_calculate_gravitational_potential_energy(double mass, double height, double gravity) {
    // Check for invalid input parameters
    if (mass <= 0.0 || height < 0.0) {
        fprintf(stderr, "Error: Mass must be a positive value, and height must be non-negative.\n");
        return 0.0;
    }

    return mass * gravity * height;
} // end of func

// Function to calculate kinetic energy: kinetic_energy = 0.5 * mass * velocity^2
double fscl_physics_calculate_kinetic_energy(double mass, double velocity) {
    // Check for invalid input parameters
    if (mass <= 0.0 || velocity < 0.0) {
        fprintf(stderr, "Error: Mass must be a positive value, and velocity must be non-negative.\n");
        return 0.0;
    }

    return 0.5 * mass * pow(velocity, 2);
} // end of func

// Function to calculate work done: work_done = force * distance * cos(theta)
double fscl_physics_calculate_work_done(double force, double distance, double theta) {
    // Check for invalid input parameters
    if (distance < 0.0 || theta < 0.0 || theta > M_PI) {
        fprintf(stderr, "Error: Distance must be non-negative, and theta must be between 0 and pi radians.\n");
        return 0.0;
    }

    return force * distance * cos(theta);
} // end of func

// Function to calculate power: power = work_done / time
double fscl_physics_calculate_power(double work_done, double time) {
    // Check for invalid input parameters
    if (time <= 0.0) {
        fprintf(stderr, "Error: Time must be a positive value.\n");
        return 0.0;
    }

    return work_done / time;
} // end of func

// Function to calculate centripetal force: centripetal_force = (mass * velocity^2) / radius
double fscl_physics_calculate_centripetal_force(double mass, double velocity, double radius) {
    // Check for invalid input parameters
    if (mass <= 0.0 || velocity < 0.0 || radius <= 0.0) {
        fprintf(stderr, "Error: Mass must be a positive value, velocity must be non-negative, and radius must be a positive value.\n");
        return 0.0;
    }

    return (mass * pow(velocity, 2)) / radius;
} // end of func
