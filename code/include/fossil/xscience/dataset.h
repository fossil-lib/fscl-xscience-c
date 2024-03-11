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

/**
 * Creates a new dataset with the specified size.
 *
 * @param dataset Pointer to the dataset to be created.
 * @param size Size of the dataset.
 */
void fscl_data_create(cdataset *dataset, size_t size);

/**
 * Erases memory allocated for a dataset.
 *
 * @param dataset Pointer to the dataset to be erased.
 */
void fscl_data_erase(cdataset *dataset);

/**
 * Prints the contents of a dataset.
 *
 * @param dataset Pointer to the dataset to be printed.
 */
void fscl_data_print(const cdataset *dataset);

/**
 * Fills the dataset with random values.
 *
 * @param dataset Pointer to the dataset to be filled with random values.
 */
void fscl_data_fill_random(cdataset *dataset);

/**
 * Calculates the mean of the dataset.
 *
 * @param dataset Pointer to the dataset.
 * @return The mean value.
 */
double fscl_data_mean(const cdataset *dataset);

/**
 * Calculates the standard deviation of the dataset.
 *
 * @param dataset Pointer to the dataset.
 * @return The standard deviation.
 */
double fscl_data_std_dev(const cdataset *dataset);

/**
 * Scales the dataset by a given factor.
 *
 * @param dataset Pointer to the dataset to be scaled.
 * @param factor Scaling factor.
 */
void fscl_data_scale(cdataset *dataset, double factor);

/**
 * Performs element-wise addition of two datasets and stores the result in a third dataset.
 *
 * @param dataset1 Pointer to the first dataset.
 * @param dataset2 Pointer to the second dataset.
 * @param result Pointer to the dataset where the result will be stored.
 */
void fscl_data_add(const cdataset *dataset1, const cdataset *dataset2, cdataset *result);

/**
 * Finds the minimum value in the dataset.
 *
 * @param dataset Pointer to the dataset.
 * @return The minimum value.
 */
double fscl_data_min(const cdataset *dataset);

/**
 * Finds the maximum value in the dataset.
 *
 * @param dataset Pointer to the dataset.
 * @return The maximum value.
 */
double fscl_data_max(const cdataset *dataset);

/**
 * Calculates the sum of all elements in the dataset.
 *
 * @param dataset Pointer to the dataset.
 * @return The sum of all elements.
 */
double fscl_data_sum(const cdataset *dataset);

/**
 * Calculates the product of all elements in the dataset.
 *
 * @param dataset Pointer to the dataset.
 * @return The product of all elements.
 */
double fscl_data_product(const cdataset *dataset);

/**
 * Finds the index of the first occurrence of a specific value in the dataset.
 *
 * @param dataset Pointer to the dataset.
 * @param value The value to be found.
 * @return The index of the first occurrence or -1 if not found.
 */
int fscl_data_find(const cdataset *dataset, double value);

/**
 * Performs element-wise multiplication of two datasets and stores the result in a third dataset.
 *
 * @param dataset1 Pointer to the first dataset.
 * @param dataset2 Pointer to the second dataset.
 * @param result Pointer to the dataset where the result will be stored.
 */
void fscl_data_multiply(const cdataset *dataset1, const cdataset *dataset2, cdataset *result);

/**
 * Normalizes the dataset between 0 and 1.
 *
 * @param dataset Pointer to the dataset to be normalized.
 */
void fscl_data_normalize(cdataset *dataset);

/**
 * Performs element-wise subtraction of two datasets and stores the result in a third dataset.
 *
 * @param dataset1 Pointer to the first dataset.
 * @param dataset2 Pointer to the second dataset.
 * @param result Pointer to the dataset where the result will be stored.
 */
void fscl_data_subtract(const cdataset *dataset1, const cdataset *dataset2, cdataset *result);

/**
 * Calculates the dot product of two datasets.
 *
 * @param dataset1 Pointer to the first dataset.
 * @param dataset2 Pointer to the second dataset.
 * @return The dot product of the two datasets.
 */
double fscl_data_dot_product(const cdataset *dataset1, const cdataset *dataset2);

/**
 * Removes missing values from the dataset.
 *
 * @param dataset Pointer to the dataset.
 */
void fscl_data_remove_missing(cdataset *dataset);

/**
 * Replaces missing values in the dataset with a specified value.
 *
 * @param dataset Pointer to the dataset.
 * @param replacement_value The value to replace missing values with.
 */
void fscl_data_replace_missing(cdataset *dataset, double replacement_value);

/**
 * Removes outliers from the dataset using a z-score threshold.
 *
 * @param dataset Pointer to the dataset.
 * @param z_threshold The z-score threshold for detecting outliers.
 */
void fscl_data_remove_outliers(cdataset *dataset, double z_threshold);

/**
 * Standardizes the dataset (subtract mean, divide by standard deviation).
 *
 * @param dataset Pointer to the dataset to be standardized.
 */
void fscl_data_standardize(cdataset *dataset);

/**
 * Normalizes numeric features in the dataset.
 *
 * @param dataset Pointer to the dataset.
 */
void fscl_data_normalize_features(cdataset *dataset);

/**
 * Encodes categorical variables using one-hot encoding.
 *
 * @param dataset Pointer to the dataset containing categorical variables.
 * @param feature_index Index of the feature to be one-hot encoded.
 */
void fscl_data_one_hot_encode(cdataset *dataset, size_t feature_index);

#ifdef __cplusplus
}
#endif

#endif
