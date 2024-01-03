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
#include "fossil/xscience/robotics.h"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

double fscl_robotic_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

double fscl_robotic_dot_product(double x1, double y1, double z1, double x2, double y2, double z2) {
    return x1 * x2 + y1 * y2 + z1 * z2;
}

void fscl_robotic_cross_product(double x1, double y1, double z1, double x2, double y2, double z2,
                            double* result_x, double* result_y, double* result_z) {
    *result_x = y1 * z2 - z1 * y2;
    *result_y = z1 * x2 - x1 * z2;
    *result_z = x1 * y2 - y1 * x2;
}

double fscl_robotic_degrees_to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double fscl_robotic_radians_to_degrees(double radians) {
    return radians * 180.0 / M_PI;
}

double fscl_robotic_angle_between_vectors(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dot_product = fscl_robotic_dot_product(x1, y1, z1, x2, y2, z2);
    double magnitude1 = fscl_robotic_magnitude(x1, y1, z1);
    double magnitude2 = fscl_robotic_magnitude(x2, y2, z2);

    return acos(dot_product / (magnitude1 * magnitude2));
}

double fscl_robotic_magnitude(double x, double y, double z) {
    return sqrt(x * x + y * y + z * z);
}

void fscl_robotic_normalize(double x, double y, double z, double* result_x, double* result_y, double* result_z) {
    double magnitude = fscl_robotic_magnitude(x, y, z);
    *result_x = x / magnitude;
    *result_y = y / magnitude;
    *result_z = z / magnitude;
}

void fscl_robotic_rotate_2d(double angle, double* x, double* y) {
    double new_x = *x * cos(angle) - *y * sin(angle);
    double new_y = *x * sin(angle) + *y * cos(angle);
    *x = new_x;
    *y = new_y;
}

void fscl_robotic_rotate_x(double angle, double* x, double* y, double* z) {
    double new_y = *y * cos(angle) - *z * sin(angle);
    double new_z = *y * sin(angle) + *z * cos(angle);
    *y = new_y;
    *z = new_z;
}

void fscl_robotic_rotate_y(double angle, double* x, double* y, double* z) {
    double new_x = *x * cos(angle) + *z * sin(angle);
    double new_z = -*x * sin(angle) + *z * cos(angle);
    *x = new_x;
    *z = new_z;
}

void fscl_robotic_rotate_z(double angle, double* x, double* y, double* z) {
    double new_x = *x * cos(angle) - *y * sin(angle);
    double new_y = *x * sin(angle) + *y * cos(angle);
    *x = new_x;
    *y = new_y;
}
