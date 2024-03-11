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

/**
 * Calculates the force using Newton's second law.
 *
 * @param mass Mass of the object.
 * @param acceleration Acceleration of the object.
 * @return The force acting on the object.
 */
double fscl_physics_calculate_force(double mass, double acceleration);

/**
 * Calculates the gravitational potential energy.
 *
 * @param mass Mass of the object.
 * @param height Height above the reference point.
 * @param gravity Acceleration due to gravity.
 * @return The gravitational potential energy.
 */
double fscl_physics_calculate_gravitational_potential_energy(double mass, double height, double gravity);

/**
 * Calculates the kinetic energy of an object.
 *
 * @param mass Mass of the object.
 * @param velocity Velocity of the object.
 * @return The kinetic energy of the object.
 */
double fscl_physics_calculate_kinetic_energy(double mass, double velocity);

/**
 * Calculates the work done by a force acting on an object.
 *
 * @param force Applied force.
 * @param distance Distance over which the force is applied.
 * @param theta Angle between force and displacement vectors in radians.
 * @return The work done.
 */
double fscl_physics_calculate_work_done(double force, double distance, double theta);

/**
 * Calculates the power based on work done and time.
 *
 * @param work_done Work done on an object.
 * @param time Time over which the work is done.
 * @return The power exerted.
 */
double fscl_physics_calculate_power(double work_done, double time);

/**
 * Calculates the centripetal force acting on an object moving in a circular path.
 *
 * @param mass Mass of the object.
 * @param velocity Velocity of the object.
 * @param radius Radius of the circular path.
 * @return The centripetal force.
 */
double fscl_physics_calculate_centripetal_force(double mass, double velocity, double radius);

#ifdef __cplusplus
}
#endif

#endif
