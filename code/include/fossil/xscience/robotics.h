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
#ifndef FSCL_SATELITE_H
#define FSCL_SATELITE_H

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalible functions
// =================================================================
double fscl_robotic_distance(double x1, double y1, double z1, double x2, double y2, double z2);
double fscl_robotic_dot_product(double x1, double y1, double z1, double x2, double y2, double z2);
void fscl_robotic_cross_product(double x1, double y1, double z1, double x2, double y2, double z2, double* result_x, double* result_y, double* result_z);
double fscl_robotic_degrees_to_radians(double degrees);
double fscl_robotic_radians_to_degrees(double radians);
double fscl_robotic_angle_between_vectors(double x1, double y1, double z1, double x2, double y2, double z2);
double fscl_robotic_magnitude(double x, double y, double z);
void fscl_robotic_normalize(double x, double y, double z, double* result_x, double* result_y, double* result_z);
void fscl_robotic_rotate_2d(double angle, double* x, double* y);
void fscl_robotic_rotate_x(double angle, double* x, double* y, double* z);
void fscl_robotic_rotate_y(double angle, double* x, double* y, double* z);
void fscl_robotic_rotate_z(double angle, double* x, double* y, double* z);

#ifdef __cplusplus
}
#endif

#endif