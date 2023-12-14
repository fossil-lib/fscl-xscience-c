/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_ELEMENT_H
#define TSCL_ELEMENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>

// Define the data structure for an element
typedef struct {
    char symbol[3];
    int atomic_number;
    double atomic_weight;
} celement;

/**
 * @brief Creates a new element with the given symbol, atomic number, and atomic weight.
 *
 * @param symbol The symbol of the element.
 * @param atomic_number The atomic number of the element.
 * @param atomic_weight The atomic weight of the element.
 * @return The created element.
 */
celement element_create(const char* symbol, int atomic_number, double atomic_weight);

/**
 * @brief Prints the details of the given element.
 *
 * @param element The element to print.
 */
void element_print(celement element);

/**
 * @brief Checks if two elements are equal.
 *
 * @param element1 The first element.
 * @param element2 The second element.
 * @return 1 if elements are equal, 0 otherwise.
 */
int element_equal(celement element1, celement element2);

/**
 * @brief Updates the atomic weight of the given element.
 *
 * @param element Pointer to the element to update.
 * @param new_weight The new atomic weight.
 */
void element_update_weight(celement *element, double new_weight);

/**
 * @brief Gets an element from the global elements lookup table by symbol.
 *
 * @param symbol The symbol of the element to look up.
 * @param num_elements The number of elements in the lookup table.
 * @return The found element or an empty element if not found.
 */
celement element_lookup(const char* symbol, size_t num_elements);

/**
 * @brief Calculates the mass of each element based on the quantity.
 *
 * @param element The element for which to calculate the mass.
 * @param quantity The quantity of the element.
 * @return The mass of the element.
 */
double element_individual_mass(celement element, int quantity);

/**
 * @brief Counts the number of elements on the chart.
 *
 * @return The count of elements on the chart.
 */
size_t element_count_chart();

/**
 * @brief Adds two elements together.
 *
 * @param element1 The first element.
 * @param element2 The second element.
 * @return The resulting element after addition.
 */
celement element_add(celement element1, celement element2);

/**
 * @brief Simulates a chemical reaction between two reactants.
 *
 * @param reactant1 The first reactant element.
 * @param reactant2 The second reactant element.
 */
void element_react(celement reactant1, celement reactant2);

/**
 * @brief Simulates a specific chemical reaction based on reactants.
 *
 * @param reactant1_symbol The symbol of the first reactant.
 * @param reactant2_symbol The symbol of the second reactant.
 */
void element_reaction(const char* reactant1_symbol, const char* reactant2_symbol);

/**
 * @brief Transforms the product based on reaction rules.
 *
 * @param product Pointer to the product element.
 * @return 1 if the transformation is successful, 0 otherwise.
 */
int element_transform(celement *product);

/**
 * @brief Creates a copy of the given element.
 *
 * @param element The element to copy.
 * @return The copied element.
 */
celement element_copy(celement element);

/**
 * @brief Checks if the atomic weight of the given element is within a specified range.
 *
 * @param element The element to check.
 * @param min_weight The minimum atomic weight.
 * @param max_weight The maximum atomic weight.
 * @return 1 if the atomic weight is within the range, 0 otherwise.
 */
int element_weight_within_range(celement element, double min_weight, double max_weight);

#ifdef __cplusplus
}
#endif

#endif
