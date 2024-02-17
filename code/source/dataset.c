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
#include "fossil/xscience/dataset.h"

// Function to create a dataset
void fscl_data_create(cdataset *dataset, size_t size) {
    dataset->data = (double *)malloc(size * sizeof(double));
    dataset->size = size;
}

// Function to erase memory allocated for a dataset
void fscl_data_erase(cdataset *dataset) {
    free(dataset->data);
    dataset->size = 0;
}

// Function to print a dataset
void fscl_data_print(const cdataset *dataset) {
    printf("Dataset: [");
    for (size_t i = 0; i < dataset->size; ++i) {
        printf("%.2f", dataset->data[i]);
        if (i < dataset->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to fill the dataset with random values
void fscl_data_fill_random(cdataset *dataset) {
    for (size_t i = 0; i < dataset->size; ++i) {
        dataset->data[i] = ((double)rand() / RAND_MAX) * 100.0; // Adjust range as needed
    }
}

// Function to calculate the mean of the dataset
double fscl_data_mean(const cdataset *dataset) {
    double sum = 0.0;
    for (size_t i = 0; i < dataset->size; ++i) {
        sum += dataset->data[i];
    }
    return sum / dataset->size;
}

// Function to calculate the standard deviation of the dataset
double fscl_data_std_dev(const cdataset *dataset) {
    double mean = fscl_data_mean(dataset);
    double sum_squared_diff = 0.0;

    for (size_t i = 0; i < dataset->size; ++i) {
        double diff = dataset->data[i] - mean;
        sum_squared_diff += diff * diff;
    }

    return sqrt(sum_squared_diff / dataset->size);
}

// Function to scale the dataset by a given factor
void fscl_data_scale(cdataset *dataset, double factor) {
    for (size_t i = 0; i < dataset->size; ++i) {
        dataset->data[i] *= factor;
    }
}

// Function to perform element-wise addition of two datasets
void fscl_data_add(const cdataset *dataset1, const cdataset *dataset2, cdataset *result) {
    if (dataset1->size != dataset2->size || result->size != dataset1->size) {
        // Handle error: sizes must match
        return;
    }

    for (size_t i = 0; i < dataset1->size; ++i) {
        result->data[i] = dataset1->data[i] + dataset2->data[i];
    }
}

// Function to find the minimum value in the dataset
double fscl_data_min(const cdataset *dataset) {
    double min_val = dataset->data[0];
    for (size_t i = 1; i < dataset->size; ++i) {
        if (dataset->data[i] < min_val) {
            min_val = dataset->data[i];
        }
    }
    return min_val;
}

// Function to find the maximum value in the dataset
double fscl_data_max(const cdataset *dataset) {
    double max_val = dataset->data[0];
    for (size_t i = 1; i < dataset->size; ++i) {
        if (dataset->data[i] > max_val) {
            max_val = dataset->data[i];
        }
    }
    return max_val;
}

// Function to calculate the sum of all elements in the dataset
double fscl_data_sum(const cdataset *dataset) {
    double sum = 0.0;
    for (size_t i = 0; i < dataset->size; ++i) {
        sum += dataset->data[i];
    }
    return sum;
}

// Function to calculate the product of all elements in the dataset
double fscl_data_product(const cdataset *dataset) {
    double product = 1.0;
    for (size_t i = 0; i < dataset->size; ++i) {
        product *= dataset->data[i];
    }
    return product;
}

// Modified fscl_data_find without using ssize_t
int fscl_data_find(const cdataset *dataset, double value) {
    for (size_t i = 0; i < dataset->size; ++i) {
        if (dataset->data[i] == value) {
            return (int)i; // Found at index i
        }
    }
    return -1; // Value not found
}

// Function to perform element-wise multiplication of two datasets
void fscl_data_multiply(const cdataset *dataset1, const cdataset *dataset2, cdataset *result) {
    if (dataset1->size != dataset2->size || result->size != dataset1->size) {
        // Handle error: sizes must match
        return;
    }

    for (size_t i = 0; i < dataset1->size; ++i) {
        result->data[i] = dataset1->data[i] * dataset2->data[i];
    }
}

// Function to normalize the dataset between 0 and 1
void fscl_data_normalize(cdataset *dataset) {
    double min_val = fscl_data_min(dataset);
    double max_val = fscl_data_max(dataset);
    double range = max_val - min_val;

    if (range == 0.0) {
        // Handle case where all values are the same to avoid division by zero
        return;
    }

    for (size_t i = 0; i < dataset->size; ++i) {
        dataset->data[i] = (dataset->data[i] - min_val) / range;
    }
}

// Function to perform element-wise subtraction of two datasets
void fscl_data_subtract(const cdataset *dataset1, const cdataset *dataset2, cdataset *result) {
    if (dataset1->size != dataset2->size || result->size != dataset1->size) {
        // Handle error: sizes must match
        return;
    }

    for (size_t i = 0; i < dataset1->size; ++i) {
        result->data[i] = dataset1->data[i] - dataset2->data[i];
    }
}

// Function to calculate the dot product of two datasets
double fscl_data_dot_product(const cdataset *dataset1, const cdataset *dataset2) {
    if (dataset1->size != dataset2->size) {
        // Handle error: sizes must match
        return 0.0;
    }

    double dot_product = 0.0;
    for (size_t i = 0; i < dataset1->size; ++i) {
        dot_product += dataset1->data[i] * dataset2->data[i];
    }

    return dot_product;
}
