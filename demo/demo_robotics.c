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
#include <trilobite/xscience/robotics.h>
#include <stdio.h>

int main() {
    // Example usage of functions in the robotic_math library

    // Compute the Euclidean distance between two points in 3D space
    double distance = robotic_distance(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    printf("Distance between points: %.2f\n", distance);

    // Compute the dot product of two 3D vectors
    double dotProduct = robotic_dot_product(2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
    printf("Dot product of vectors: %.2f\n", dotProduct);

    // Compute the cross product of two 3D vectors
    double crossProductX, crossProductY, crossProductZ;
    robotic_cross_product(2.0, 3.0, 4.0, 5.0, 6.0, 7.0, &crossProductX, &crossProductY, &crossProductZ);
    printf("Cross product of vectors: (%.2f, %.2f, %.2f)\n", crossProductX, crossProductY, crossProductZ);

    // Convert degrees to radians
    double radians = robotic_degrees_to_radians(45.0);
    printf("45 degrees in radians: %.2f\n", radians);

    // Convert radians to degrees
    double degrees = robotic_radians_to_degrees(1.57);
    printf("1.57 radians in degrees: %.2f\n", degrees);

    // Compute the angle between two 3D vectors in radians
    double angle = robotic_angle_between_vectors(2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
    printf("Angle between vectors in radians: %.2f\n", angle);

    // Compute the magnitude of a 3D vector
    double magnitude = robotic_magnitude(3.0, 4.0, 5.0);
    printf("Magnitude of vector: %.2f\n", magnitude);

    // Normalize a 3D vector
    double normalizedX, normalizedY, normalizedZ;
    robotic_normalize(3.0, 4.0, 5.0, &normalizedX, &normalizedY, &normalizedZ);
    printf("Normalized vector: (%.2f, %.2f, %.2f)\n", normalizedX, normalizedY, normalizedZ);

    // Rotate a 2D point (x, y) around the origin by a given angle in radians
    double x = 2.0, y = 3.0;
    robotic_rotate_2d(robotic_degrees_to_radians(45.0), &x, &y);
    printf("Rotated 2D point: (%.2f, %.2f)\n", x, y);

    // Rotate a 3D point (x, y, z) around the X-axis by a given angle in radians
    double pointX = 2.0, pointY = 3.0, pointZ = 4.0;
    robotic_rotate_x(robotic_degrees_to_radians(30.0), &pointX, &pointY, &pointZ);
    printf("Rotated 3D point around X-axis: (%.2f, %.2f, %.2f)\n", pointX, pointY, pointZ);

    // Rotate a 3D point (x, y, z) around the Y-axis by a given angle in radians
    pointX = 2.0, pointY = 3.0, pointZ = 4.0;
    robotic_rotate_y(robotic_degrees_to_radians(45.0), &pointX, &pointY, &pointZ);
    printf("Rotated 3D point around Y-axis: (%.2f, %.2f, %.2f)\n", pointX, pointY, pointZ);

    // Rotate a 3D point (x, y, z) around the Z-axis by a given angle in radians
    pointX = 2.0, pointY = 3.0, pointZ = 4.0;
    robotic_rotate_z(robotic_degrees_to_radians(60.0), &pointX, &pointY, &pointZ);
    printf("Rotated 3D point around Z-axis: (%.2f, %.2f, %.2f)\n", pointX, pointY, pointZ);

    return 0;
} // end of func
