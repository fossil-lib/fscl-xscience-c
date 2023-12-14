/*  ----------------------------------------------------------------------------
    File: robotics.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

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
#include "trilobite/xscience/robotics.h"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

double robotic_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

double robotic_dot_product(double x1, double y1, double z1, double x2, double y2, double z2) {
    return x1 * x2 + y1 * y2 + z1 * z2;
}

void robotic_cross_product(double x1, double y1, double z1, double x2, double y2, double z2,
                            double* result_x, double* result_y, double* result_z) {
    *result_x = y1 * z2 - z1 * y2;
    *result_y = z1 * x2 - x1 * z2;
    *result_z = x1 * y2 - y1 * x2;
}

double robotic_degrees_to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double robotic_radians_to_degrees(double radians) {
    return radians * 180.0 / M_PI;
}

double robotic_angle_between_vectors(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dot_product = robotic_dot_product(x1, y1, z1, x2, y2, z2);
    double magnitude1 = robotic_magnitude(x1, y1, z1);
    double magnitude2 = robotic_magnitude(x2, y2, z2);

    return acos(dot_product / (magnitude1 * magnitude2));
}

double robotic_magnitude(double x, double y, double z) {
    return sqrt(x * x + y * y + z * z);
}

void robotic_normalize(double x, double y, double z, double* result_x, double* result_y, double* result_z) {
    double magnitude = robotic_magnitude(x, y, z);
    *result_x = x / magnitude;
    *result_y = y / magnitude;
    *result_z = z / magnitude;
}

void robotic_rotate_2d(double angle, double* x, double* y) {
    double new_x = *x * cos(angle) - *y * sin(angle);
    double new_y = *x * sin(angle) + *y * cos(angle);
    *x = new_x;
    *y = new_y;
}

void robotic_rotate_x(double angle, double* x, double* y, double* z) {
    double new_y = *y * cos(angle) - *z * sin(angle);
    double new_z = *y * sin(angle) + *z * cos(angle);
    *y = new_y;
    *z = new_z;
}

void robotic_rotate_y(double angle, double* x, double* y, double* z) {
    double new_x = *x * cos(angle) + *z * sin(angle);
    double new_z = -*x * sin(angle) + *z * cos(angle);
    *x = new_x;
    *z = new_z;
}

void robotic_rotate_z(double angle, double* x, double* y, double* z) {
    double new_x = *x * cos(angle) - *y * sin(angle);
    double new_y = *x * sin(angle) + *y * cos(angle);
    *x = new_x;
    *y = new_y;
}
