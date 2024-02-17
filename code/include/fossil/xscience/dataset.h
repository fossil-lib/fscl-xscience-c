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
#ifndef FSCL_DATASET_H
#define FSCL_DATASET_H

#include <math.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Include necessary headers
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

// Define data types
typedef struct {
    double *data;
    size_t size;
} cdataset;

// =================================================================
// Avalible functions
// =================================================================
// Function to create a dataset
void fscl_data_create(cdataset *dataset, size_t size);

// Function to erase memory allocated for a dataset
void fscl_data_erase(cdataset *dataset);

// Function to print a dataset
void fscl_data_print(const cdataset *dataset);

// Function to fill the dataset with random values
void fscl_data_fill_random(cdataset *dataset);

// Function to calculate the mean of the dataset
double fscl_data_mean(const cdataset *dataset);

// Function to calculate the standard deviation of the dataset
double fscl_data_std_dev(const cdataset *dataset);

// Function to scale the dataset by a given factor
void fscl_data_scale(cdataset *dataset, double factor);

// Function to perform element-wise addition of two datasets
void fscl_data_add(const cdataset *dataset1, const cdataset *dataset2, cdataset *result);

// Function to find the minimum value in the dataset
double fscl_data_min(const cdataset *dataset);

// Function to find the maximum value in the dataset
double fscl_data_max(const cdataset *dataset);

// Function to calculate the sum of all elements in the dataset
double fscl_data_sum(const cdataset *dataset);

// Function to calculate the product of all elements in the dataset
double fscl_data_product(const cdataset *dataset);

// Function to find the index of the first occurrence of a specific value in the dataset
int fscl_data_find(const cdataset *dataset, double value);

// Function to perform element-wise multiplication of two datasets
void fscl_data_multiply(const cdataset *dataset1, const cdataset *dataset2, cdataset *result);

// Function to normalize the dataset between 0 and 1
void fscl_data_normalize(cdataset *dataset);

// Function to perform element-wise subtraction of two datasets
void fscl_data_subtract(const cdataset *dataset1, const cdataset *dataset2, cdataset *result);

// Function to calculate the dot product of two datasets
double fscl_data_dot_product(const cdataset *dataset1, const cdataset *dataset2);

// Function to remove missing values from the dataset
void fscl_data_remove_missing(cdataset *dataset);

// Function to replace missing values with a specified value
void fscl_data_replace_missing(cdataset *dataset, double replacement_value);

// Function to remove outliers from the dataset using a z-score threshold
void fscl_data_remove_outliers(cdataset *dataset, double z_threshold);

// Function to standardize the dataset (subtract mean, divide by standard deviation)
void fscl_data_standardize(cdataset *dataset);

// Function to normalize numeric features in the dataset
void fscl_data_normalize_features(cdataset *dataset);

// Function to encode categorical variables using one-hot encoding
void fscl_data_one_hot_encode(cdataset *dataset, size_t feature_index);

#ifdef __cplusplus
}
#endif

#endif