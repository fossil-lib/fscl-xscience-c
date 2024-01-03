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
#ifndef FSCL_ELEMENT_H
#define FSCL_ELEMENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>

// Define the data structure for an element
typedef struct {
    char symbol[10];
    int atomic_number;
    double atomic_weight;
} celement;

// =================================================================
// Avalible functions
// =================================================================
celement fscl_element_create(const char* symbol, int atomic_number, double atomic_weight);
void fscl_element_print(celement element);
int fscl_element_equal(celement element1, celement element2);
void fscl_element_update_weight(celement *element, double new_weight);
celement fscl_element_lookup(const char* symbol, size_t num_elements);
double fscl_element_individual_mass(celement element, int quantity);
size_t fscl_element_count_chart();
celement fscl_element_add(celement element1, celement element2);
void fscl_element_react(celement reactant1, celement reactant2);
void fscl_element_reaction(const char* reactant1_symbol, const char* reactant2_symbol);
int fscl_element_transform(celement *product);
celement fscl_element_copy(celement element);
int fscl_element_weight_within_range(celement element, double min_weight, double max_weight);

#ifdef __cplusplus
}
#endif

#endif
