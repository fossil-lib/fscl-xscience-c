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
#ifndef TSCL_PHYSICS_H
#define TSCL_PHYSICS_H

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

/**
 * @brief Calculate force using Newton's second law: force = mass * acceleration.
 * 
 * @param mass The mass of the object.
 * @param acceleration The acceleration of the object.
 * @return The force exerted on the object.
 */
double physics_calculate_force(double mass, double acceleration);

/**
 * @brief Calculate gravitational potential energy: potential_energy = mass * gravity * height.
 * 
 * @param mass The mass of the object.
 * @param height The height above a reference point.
 * @return The gravitational potential energy of the object.
 */
double physics_calculate_gravitational_potential_energy(double mass, double height, double gravity);

/**
 * @brief Calculate kinetic energy: kinetic_energy = 0.5 * mass * velocity^2.
 * 
 * @param mass The mass of the object.
 * @param velocity The velocity of the object.
 * @return The kinetic energy of the object.
 */
double physics_calculate_kinetic_energy(double mass, double velocity);

/**
 * @brief Calculate work done: work_done = force * distance * cos(theta).
 * 
 * @param force The force applied on the object.
 * @param distance The displacement of the object.
 * @param theta The angle between the force and the displacement vectors (in radians).
 * @return The work done on the object.
 */
double physics_calculate_work_done(double force, double distance, double theta);

/**
 * @brief Calculate power: power = work_done / time.
 * 
 * @param work_done The work done on the object.
 * @param time The time taken to do the work.
 * @return The power exerted or consumed.
 */
double physics_calculate_power(double work_done, double time);

/**
 * @brief Calculate centripetal force: centripetal_force = (mass * velocity^2) / radius.
 * 
 * @param mass The mass of the object.
 * @param velocity The velocity of the object.
 * @param radius The radius of the circular path.
 * @return The centripetal force required to keep the object in circular motion.
 */
double physics_calculate_centripetal_force(double mass, double velocity, double radius);

#ifdef __cplusplus
}
#endif

#endif