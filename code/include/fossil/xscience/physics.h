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
#ifndef FSCL_PHY_H
#define FSCL_PHY_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef const double celestial;

// Constants for gravity on different celestial bodies
extern celestial GRAVITY_SUN;
extern celestial GRAVITY_MERCURY;
extern celestial GRAVITY_VENUS;
extern celestial GRAVITY_JUPITER;
extern celestial GRAVITY_SATURN;
extern celestial GRAVITY_URANUS;
extern celestial GRAVITY_NEPTUNE;
extern celestial GRAVITY_EARTH;
extern celestial GRAVITY_MOON;
extern celestial GRAVITY_MARS;

// =================================================================
// Avalible functions
// =================================================================
double fscl_physics_calculate_force(double mass, double acceleration);
double fscl_physics_calculate_gravitational_potential_energy(double mass, double height, double gravity);
double fscl_physics_calculate_kinetic_energy(double mass, double velocity);
double fscl_physics_calculate_work_done(double force, double distance, double theta);
double fscl_physics_calculate_power(double work_done, double time);
double fscl_physics_calculate_centripetal_force(double mass, double velocity, double radius);

#ifdef __cplusplus
}
#endif

#endif