/*  ----------------------------------------------------------------------------
    File: element.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

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
#include "trilobite/xscience/element.h"
#include <string.h>
#include <stdio.h>

// Define the maximum number of elements in the periodic table
enum {MAX_ELEMENTS = 118};

// Global array to store elements in the periodic table
celement periodic_table[MAX_ELEMENTS];

// Global array to represent elements
celement elements[] = {
    {"H", 1, 1.008},
    {"He", 2, 4.0026},
    {"Li", 3, 6.94},
    {"Be", 4, 9.0122},
    {"B", 5, 10.81},
    {"C", 6, 12.011},
    {"N", 7, 14.007},
    {"O", 8, 16.00},
    {"F", 9, 18.998},
    {"Ne", 10, 20.180},
    {"Na", 11, 22.990},
    {"Mg", 12, 24.305},
    {"Al", 13, 26.982},
    {"Si", 14, 28.085},
    {"P", 15, 30.974},
    {"S", 16, 32.06},
    {"Cl", 17, 35.45},
    {"K", 19, 39.10},
    {"Ar", 18, 39.95},
    {"Ca", 20, 40.08},
    {"Sc", 21, 44.96},
    {"Ti", 22, 47.87},
    {"V", 23, 50.94},
    {"Cr", 24, 51.996},
    {"Mn", 25, 54.94},
    {"Fe", 26, 55.85},
    {"Ni", 28, 58.69},
    {"Co", 27, 58.93},
    {"Cu", 29, 63.55},
    {"Zn", 30, 65.38},
    {"Ga", 31, 69.72},
    {"Ge", 32, 72.63},
    {"As", 33, 74.92},
    {"Se", 34, 78.97},
    {"Br", 35, 79.90},
    {"Kr", 36, 83.80}
    // Add more elements as needed
};

// Function to create a new element
celement element_create(const char* symbol, int atomic_number, double atomic_weight) {
    celement element;
    strncpy(element.symbol, symbol, 2);
    element.symbol[2] = '\0';  // Ensure null-terminated string
    element.atomic_number = atomic_number;
    element.atomic_weight = atomic_weight;
    return element;
}

// Function to print element details
void element_print(celement element) {
    printf("Symbol: %s\nAtomic Number: %d\nAtomic Weight: %lf\n",
           element.symbol, element.atomic_number, element.atomic_weight);
}

// Function to check if two elements are equal
int element_equal(celement element1, celement element2) {
    return (strcmp(element1.symbol, element2.symbol) == 0 &&
            element1.atomic_number == element2.atomic_number &&
            element1.atomic_weight == element2.atomic_weight);
}

// Function to update the atomic weight of an element
void element_update_weight(celement *element, double new_weight) {
    element->atomic_weight = new_weight;
}

// Function to get an element from the global elements lookup table by symbol
celement element_lookup(const char* symbol, size_t num_elements) {
    for (size_t i = 0; i < num_elements; ++i) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return elements[i];
        }
    }

    // Return an empty element if not found
    return element_create("", 0, 0.0);
}

// Function to calculate mass of each element
double element_individual_mass(celement element, int quantity) {
    return element.atomic_weight * quantity;
}

// Function to count elements on the chart
size_t element_count_chart() {
    return sizeof(elements) / sizeof(celement);
}

// Function to add elements together
celement element_add(celement element1, celement element2) {
    celement result;
    result.atomic_number = element1.atomic_number + element2.atomic_number;
    result.atomic_weight = element1.atomic_weight + element2.atomic_weight;
    // You might want to handle the symbol differently based on your needs
    snprintf(result.symbol, sizeof(result.symbol), "%d", result.atomic_number);
    return result;
}

// Function to simulate a chemical reaction
void element_react(celement reactant1, celement reactant2) {
    printf("Reactants:\n");
    element_print(reactant1);
    element_print(reactant2);

    // Simulate a simple reaction (e.g., combine reactants)
    celement product = element_add(reactant1, reactant2);

    // Check if the product transforms into another element based on rules
    if (element_transform(&product)) {
        printf("\nReaction Succeeded! Product transforms into:\n");
        element_print(product);
    } else {
        printf("\nReaction Failed! Product remains unchanged:\n");
        element_print(product);
    }
}

// Function to simulate a specific reaction based on reactants
void element_reaction(const char* reactant1_symbol, const char* reactant2_symbol) {
    // Lookup reactants in the global elements array
    celement reactant1 = element_lookup(reactant1_symbol, sizeof(elements) / sizeof(celement));
    celement reactant2 = element_lookup(reactant2_symbol, sizeof(elements) / sizeof(celement));

    // Check if the reactants are valid
    if (reactant1.atomic_number == 0 || reactant2.atomic_number == 0) {
        printf("Invalid reactants.\n");
        return;
    }

    // Simulate the reaction
    printf("Simulating a specific reaction:\n");
    element_react(reactant1, reactant2);
}

// Function to transform the product based on reaction rules
int element_transform(celement *product) {
    // Add your specific reaction rules here
    // For demonstration purposes, let's say if the product has an atomic number
    // greater than 20, it transforms into a new element
    if (product->atomic_number > 20) {
        // Transform the product into a new element
        *product = element_lookup("Na", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    return 0; // Failure
} // end of func

// Function to create a copy of the given element
celement element_copy(celement element) {
    celement copy;
    strcpy(copy.symbol, element.symbol);
    copy.atomic_number = element.atomic_number;
    copy.atomic_weight = element.atomic_weight;
    return copy;
}

// Function to check if the atomic weight of the given element is within a specified range
int element_weight_within_range(celement element, double min_weight, double max_weight) {
    return (element.atomic_weight >= min_weight && element.atomic_weight <= max_weight);
} // end of func
