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
#ifndef TSCL_SATELITE_H
#define TSCL_SATELITE_H

#ifdef __cplusplus
extern "C"
{
#endif

// Function to compute the Euclidean distance between two points in 3D space
double robotic_distance(double x1, double y1, double z1, double x2, double y2, double z2);

// Function to compute the dot product of two 3D vectors
double robotic_dot_product(double x1, double y1, double z1, double x2, double y2, double z2);

// Function to compute the cross product of two 3D vectors
void robotic_cross_product(double x1, double y1, double z1, double x2, double y2, double z2, double* result_x, double* result_y, double* result_z);

// Function to convert degrees to radians
double robotic_degrees_to_radians(double degrees);

// Function to convert radians to degrees
double robotic_radians_to_degrees(double radians);

// Function to compute the angle between two 3D vectors in radians
double robotic_angle_between_vectors(double x1, double y1, double z1, double x2, double y2, double z2);

// Function to compute the magnitude of a 3D vector
double robotic_magnitude(double x, double y, double z);

// Function to normalize a 3D vector
void robotic_normalize(double x, double y, double z, double* result_x, double* result_y, double* result_z);

// Function to rotate a 2D point (x, y) around the origin by a given angle in radians
void robotic_rotate_2d(double angle, double* x, double* y);

// Function to rotate a 3D point (x, y, z) around the X-axis by a given angle in radians
void robotic_rotate_x(double angle, double* x, double* y, double* z);

// Function to rotate a 3D point (x, y, z) around the Y-axis by a given angle in radians
void robotic_rotate_y(double angle, double* x, double* y, double* z);

// Function to rotate a 3D point (x, y, z) around the Z-axis by a given angle in radians
void robotic_rotate_z(double angle, double* x, double* y, double* z);

#ifdef __cplusplus
}
#endif

#endif