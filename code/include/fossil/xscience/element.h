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

/**
 * Creates a new chemical element with the specified symbol, atomic number, and atomic weight.
 *
 * @param symbol The symbol of the element.
 * @param atomic_number The atomic number of the element.
 * @param atomic_weight The atomic weight of the element.
 * @return The created chemical element.
 */
celement fscl_element_create(const char* symbol, int atomic_number, double atomic_weight);

/**
 * Prints the information of a chemical element.
 *
 * @param element The chemical element to be printed.
 */
void fscl_element_print(celement element);

/**
 * Checks if two chemical elements are equal.
 *
 * @param element1 The first chemical element.
 * @param element2 The second chemical element.
 * @return 1 if equal, 0 otherwise.
 */
int fscl_element_equal(celement element1, celement element2);

/**
 * Updates the atomic weight of a chemical element.
 *
 * @param element The chemical element to be updated.
 * @param new_weight The new atomic weight.
 */
void fscl_element_update_weight(celement *element, double new_weight);

/**
 * Looks up a chemical element by its symbol.
 *
 * @param symbol The symbol of the element to be looked up.
 * @param num_elements The number of elements in the lookup table.
 * @return The found chemical element or an empty element if not found.
 */
celement fscl_element_lookup(const char* symbol, size_t num_elements);

/**
 * Calculates the mass of a given quantity of a chemical element.
 *
 * @param element The chemical element.
 * @param quantity The quantity of the element.
 * @return The mass of the specified quantity.
 */
double fscl_element_individual_mass(celement element, int quantity);

/**
 * Returns the number of elements in the chemical element chart.
 *
 * @return The number of elements in the chart.
 */
size_t fscl_element_count_chart();

/**
 * Adds two chemical elements to create a new element.
 *
 * @param element1 The first chemical element.
 * @param element2 The second chemical element.
 * @return The newly created chemical element.
 */
celement fscl_element_add(celement element1, celement element2);

/**
 * Reacts two chemical elements, modifying the reactant elements.
 *
 * @param reactant1 The first reactant element.
 * @param reactant2 The second reactant element.
 */
void fscl_element_react(celement reactant1, celement reactant2);

/**
 * Initiates a chemical reaction using the symbols of two reactant elements.
 *
 * @param reactant1_symbol The symbol of the first reactant.
 * @param reactant2_symbol The symbol of the second reactant.
 */
void fscl_element_reaction(const char* reactant1_symbol, const char* reactant2_symbol);

/**
 * Transforms a chemical element, possibly changing its state.
 *
 * @param product A pointer to the chemical element to be transformed.
 * @return 1 if transformation succeeded, 0 otherwise.
 */
int fscl_element_transform(celement *product);

/**
 * Creates a copy of a chemical element.
 *
 * @param element The chemical element to be copied.
 * @return The copied chemical element.
 */
celement fscl_element_copy(celement element);

/**
 * Checks if the atomic weight of a chemical element is within a specified range.
 *
 * @param element The chemical element to be checked.
 * @param min_weight The minimum atomic weight.
 * @param max_weight The maximum atomic weight.
 * @return 1 if within range, 0 otherwise.
 */
int fscl_element_weight_within_range(celement element, double min_weight, double max_weight);

#ifdef __cplusplus
}
#endif

#endif
