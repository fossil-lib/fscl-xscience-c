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
#ifndef FSCL_ROBOT_H
#define FSCL_ROBOT_H

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalible functions
// =================================================================

/**
 * Calculates the Euclidean distance between two points in 3D space.
 *
 * @param x1 X-coordinate of the first point.
 * @param y1 Y-coordinate of the first point.
 * @param z1 Z-coordinate of the first point.
 * @param x2 X-coordinate of the second point.
 * @param y2 Y-coordinate of the second point.
 * @param z2 Z-coordinate of the second point.
 * @return The Euclidean distance between the two points.
 */
double fscl_robotic_distance(double x1, double y1, double z1, double x2, double y2, double z2);

/**
 * Calculates the dot product of two 3D vectors.
 *
 * @param x1 X-component of the first vector.
 * @param y1 Y-component of the first vector.
 * @param z1 Z-component of the first vector.
 * @param x2 X-component of the second vector.
 * @param y2 Y-component of the second vector.
 * @param z2 Z-component of the second vector.
 * @return The dot product of the two vectors.
 */
double fscl_robotic_dot_product(double x1, double y1, double z1, double x2, double y2, double z2);

/**
 * Calculates the cross product of two 3D vectors.
 *
 * @param x1 X-component of the first vector.
 * @param y1 Y-component of the first vector.
 * @param z1 Z-component of the first vector.
 * @param x2 X-component of the second vector.
 * @param y2 Y-component of the second vector.
 * @param z2 Z-component of the second vector.
 * @param result_x Pointer to store the X-component of the result.
 * @param result_y Pointer to store the Y-component of the result.
 * @param result_z Pointer to store the Z-component of the result.
 */
void fscl_robotic_cross_product(double x1, double y1, double z1, double x2, double y2, double z2,
                                double* result_x, double* result_y, double* result_z);

/**
 * Converts degrees to radians.
 *
 * @param degrees Angle in degrees.
 * @return The equivalent angle in radians.
 */
double fscl_robotic_degrees_to_radians(double degrees);

/**
 * Converts radians to degrees.
 *
 * @param radians Angle in radians.
 * @return The equivalent angle in degrees.
 */
double fscl_robotic_radians_to_degrees(double radians);

/**
 * Calculates the angle (in radians) between two 3D vectors.
 *
 * @param x1 X-component of the first vector.
 * @param y1 Y-component of the first vector.
 * @param z1 Z-component of the first vector.
 * @param x2 X-component of the second vector.
 * @param y2 Y-component of the second vector.
 * @param z2 Z-component of the second vector.
 * @return The angle between the two vectors in radians.
 */
double fscl_robotic_angle_between_vectors(double x1, double y1, double z1, double x2, double y2, double z2);

/**
 * Calculates the magnitude of a 3D vector.
 *
 * @param x X-component of the vector.
 * @param y Y-component of the vector.
 * @param z Z-component of the vector.
 * @return The magnitude of the vector.
 */
double fscl_robotic_magnitude(double x, double y, double z);

/**
 * Normalizes a 3D vector.
 *
 * @param x X-component of the vector.
 * @param y Y-component of the vector.
 * @param z Z-component of the vector.
 * @param result_x Pointer to store the normalized X-component.
 * @param result_y Pointer to store the normalized Y-component.
 * @param result_z Pointer to store the normalized Z-component.
 */
void fscl_robotic_normalize(double x, double y, double z, double* result_x, double* result_y, double* result_z);

/**
 * Rotates a 2D point about the origin.
 *
 * @param angle Angle of rotation in radians.
 * @param x Pointer to the X-coordinate of the point (updated after rotation).
 * @param y Pointer to the Y-coordinate of the point (updated after rotation).
 */
void fscl_robotic_rotate_2d(double angle, double* x, double* y);

/**
 * Rotates a 3D point about the X-axis.
 *
 * @param angle Angle of rotation in radians.
 * @param x Pointer to the X-coordinate of the point (updated after rotation).
 * @param y Pointer to the Y-coordinate of the point (updated after rotation).
 * @param z Pointer to the Z-coordinate of the point (updated after rotation).
 */
void fscl_robotic_rotate_x(double angle, double* x, double* y, double* z);

/**
 * Rotates a 3D point about the Y-axis.
 *
 * @param angle Angle of rotation in radians.
 * @param x Pointer to the X-coordinate of the point (updated after rotation).
 * @param y Pointer to the Y-coordinate of the point (updated after rotation).
 * @param z Pointer to the Z-coordinate of the point (updated after rotation).
 */
void fscl_robotic_rotate_y(double angle, double* x, double* y, double* z);

/**
 * Rotates a 3D point about the Z-axis.
 *
 * @param angle Angle of rotation in radians.
 * @param x Pointer to the X-coordinate of the point (updated after rotation).
 * @param y Pointer to the Y-coordinate of the point (updated after rotation).
 * @param z Pointer to the Z-coordinate of the point (updated after rotation).
 */
void fscl_robotic_rotate_z(double angle, double* x, double* y, double* z);

#ifdef __cplusplus
}
#endif

#endif
