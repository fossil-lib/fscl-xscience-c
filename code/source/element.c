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
#include "fossil/xscience/element.h"
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
    {"Kr", 36, 83.80},
    {"H2O", 37, 18.015},    // Atomic weight of water (H2O)
    {"NaCl", 38, 58.44},    // Atomic weight of table salt (NaCl)
    {"CO2", 39, 44.01},     // Atomic weight of carbon dioxide (CO2)
    {"NH3", 40, 17.03},     // Atomic weight of ammonia (NH3)
    {"Fe2O3", 41, 159.69},  // Atomic weight of iron(III) oxide (Fe2O3)
    {"Mg3N2", 42, 100.95},  // Atomic weight of magnesium nitride (Mg3N2)
    {"SO2", 43, 64.07},     // Atomic weight of sulfur dioxide (SO2)
    {"AlF3", 44, 83.98},    // Atomic weight of aluminum fluoride (AlF3)
    {"SiO2", 45, 60.08},    // Atomic weight of silicon dioxide (SiO2)
    {"P4O10", 46, 283.89},  // Atomic weight of phosphorus pentoxide (P4O10)
    {"SF6", 47, 146.06},    // Atomic weight of sulfur hexafluoride (SF6)
    {"KOH", 48, 56.11},     // Atomic weight of potassium hydroxide (KOH)
    {"ArF", 49, 69.94},     // Atomic weight of argon fluoride (ArF)
    {"Sc2O3", 50, 137.87},  // Atomic weight of scandium(III) oxide (Sc2O3)
    {"TiO2", 51, 79.87},    // Atomic weight of titanium dioxide (TiO2)
    {"VCl5", 52, 157.30}    // Atomic weight of vanadium(V) chloride (VCl5)
};

// Function to create a new element
celement fscl_element_create(const char* symbol, int atomic_number, double atomic_weight) {
    celement new_element;
    strncpy(new_element.symbol, symbol, sizeof(new_element.symbol) - 1);
    new_element.symbol[sizeof(new_element.symbol) - 1] = '\0';
    new_element.atomic_number = atomic_number;
    new_element.atomic_weight = atomic_weight;
    return new_element;
}

// Function to print element details
void fscl_element_print(celement element) {
    printf("Symbol: %s\nAtomic Number: %d\nAtomic Weight: %lf\n",
           element.symbol, element.atomic_number, element.atomic_weight);
}

// Function to check if two elements are equal
int fscl_element_equal(celement element1, celement element2) {
    return (strcmp(element1.symbol, element2.symbol) == 0 &&
            element1.atomic_number == element2.atomic_number &&
            element1.atomic_weight == element2.atomic_weight);
}

// Function to update the atomic weight of an element
void fscl_element_update_weight(celement *element, double new_weight) {
    element->atomic_weight = new_weight;
}

// Function to get an element from the global elements lookup table by symbol
celement fscl_element_lookup(const char* symbol, size_t num_elements) {
    for (size_t i = 0; i < num_elements; ++i) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return elements[i];
        }
    }

    // Return an empty element if not found
    return fscl_element_create("", 0, 0.0);
}

// Function to calculate mass of each element
double fscl_element_individual_mass(celement element, int quantity) {
    return element.atomic_weight * quantity;
}

// Function to count elements on the chart
size_t fscl_element_count_chart() {
    return sizeof(elements) / sizeof(celement);
}

// Function to add elements together
celement fscl_element_add(celement element1, celement element2) {
    celement result;
    result.atomic_number = element1.atomic_number + element2.atomic_number;
    result.atomic_weight = element1.atomic_weight + element2.atomic_weight;
    // You might want to handle the symbol differently based on your needs
    snprintf(result.symbol, sizeof(result.symbol), "%d", result.atomic_number);
    return result;
}

// Function to simulate a chemical reaction
void fscl_element_react(celement reactant1, celement reactant2) {
    printf("Reactants:\n");
    fscl_element_print(reactant1);
    fscl_element_print(reactant2);

    // Simulate a simple reaction (e.g., combine reactants)
    celement product = fscl_element_add(reactant1, reactant2);

    // Check if the product transforms into another element based on rules
    if (fscl_element_transform(&product)) {
        printf("\nReaction Succeeded! Product transforms into:\n");
        fscl_element_print(product);
    } else {
        printf("\nReaction Failed! Product remains unchanged:\n");
        fscl_element_print(product);
    }
}

// Function to simulate a specific reaction based on reactants
void fscl_element_reaction(const char* reactant1_symbol, const char* reactant2_symbol) {
    // Lookup reactants in the global elements array
    celement reactant1 = fscl_element_lookup(reactant1_symbol, sizeof(elements) / sizeof(celement));
    celement reactant2 = fscl_element_lookup(reactant2_symbol, sizeof(elements) / sizeof(celement));

    // Check if the reactants are valid
    if (reactant1.atomic_number == 0 || reactant2.atomic_number == 0) {
        printf("Invalid reactants.\n");
        return;
    }

    // Simulate the reaction
    printf("Simulating a specific reaction:\n");
    fscl_element_react(reactant1, reactant2);
}

int explosive_reaction(celement *product) {
        if (strcmp(product->symbol, "H2O") == 0 && strcmp(product->symbol, "Na") == 0) {
        // Example: Water and Sodium result in explosion
        printf("Explosive Reaction! Water and Sodium result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "O2") == 0 && strcmp(product->symbol, "H2") == 0) {
        // Example: Hydrogen and Oxygen result in explosion
        printf("Explosive Reaction! Hydrogen and Oxygen result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "Mg") == 0 && strcmp(product->symbol, "N2") == 0) {
        // Example: Magnesium and Nitrogen result in explosion
        printf("Explosive Reaction! Magnesium and Nitrogen result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "C2H2") == 0 && strcmp(product->symbol, "O2") == 0) {
        // Example: Acetylene and Oxygen result in explosion
        printf("Explosive Reaction! Acetylene and Oxygen result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    // Additional explosive reactions
    if (strcmp(product->symbol, "Cl2") == 0 && strcmp(product->symbol, "H2") == 0) {
        printf("Explosive Reaction! Chlorine and Hydrogen result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "N2") == 0 && strcmp(product->symbol, "O2") == 0) {
        printf("Explosive Reaction! Nitrogen and Oxygen result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "C4H10") == 0 && strcmp(product->symbol, "O2") == 0) {
        printf("Explosive Reaction! Butane and Oxygen result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "H2O") == 0 && strcmp(product->symbol, "Na") == 0) {
        // Example: Water and Sodium result in explosion
        printf("Explosive Reaction! Water and Sodium result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "O2") == 0 && strcmp(product->symbol, "H2") == 0) {
        // Example: Hydrogen and Oxygen result in explosion
        printf("Explosive Reaction! Hydrogen and Oxygen result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "Mg") == 0 && strcmp(product->symbol, "N2") == 0) {
        // Example: Magnesium and Nitrogen result in explosion
        printf("Explosive Reaction! Magnesium and Nitrogen result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "C2H2") == 0 && strcmp(product->symbol, "O2") == 0) {
        // Example: Acetylene and Oxygen result in explosion
        printf("Explosive Reaction! Acetylene and Oxygen result in explosion.\n");
        // Handle explosion logic here
        return 1; // Explosion
    }

    // Additional explosive reactions
    if (strcmp(product->symbol, "Cl2") == 0 && strcmp(product->symbol, "H2") == 0) {
        printf("Explosive Reaction! Chlorine and Hydrogen result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "N2") == 0 && strcmp(product->symbol, "O2") == 0) {
        printf("Explosive Reaction! Nitrogen and Oxygen result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "C4H10") == 0 && strcmp(product->symbol, "O2") == 0) {
        printf("Explosive Reaction! Butane and Oxygen result in explosion.\n");
        return 1; // Explosion
    }

    // More explosive reactions to cover the remaining cases
    if (strcmp(product->symbol, "K") == 0 && strcmp(product->symbol, "H2O") == 0) {
        printf("Explosive Reaction! Potassium and Water result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "Si") == 0 && strcmp(product->symbol, "F2") == 0) {
        printf("Explosive Reaction! Silicon and Fluorine result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "CO") == 0 && strcmp(product->symbol, "Cl2") == 0) {
        printf("Explosive Reaction! Carbon Monoxide and Chlorine result in explosion.\n");
        return 1; // Explosion
    }

    if (strcmp(product->symbol, "Kr") == 0 && strcmp(product->symbol, "H2O") == 0) {
        printf("Explosive Reaction! Krypton and Water result in explosion.\n");
        return 1; // Explosion
    }
    return 0; // Unknown
}

int adding_reaction(celement *product) {
    // Reaction 1: Hydrogen and Oxygen react to form water (H2O)
    if ((strcmp(product->symbol, "H") == 0 && product->atomic_number == 2) ||
        (strcmp(product->symbol, "O") == 0 && product->atomic_number == 1)) {
        *product = fscl_element_lookup("H2O", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 2: Sodium (Na) and Chlorine (Cl) react to form common salt (NaCl)
    if (strcmp(product->symbol, "Na") == 0 && strcmp(product->symbol, "Cl") == 0) {
        *product = fscl_element_lookup("NaCl", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 3: Carbon (C) and Oxygen (O) react to form carbon dioxide (CO2)
    if (strcmp(product->symbol, "C") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("CO2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 4: Hydrogen (H) and Nitrogen (N) react to form ammonia (NH3)
    if ((strcmp(product->symbol, "H") == 0 && strcmp(product->symbol, "N") == 0) ||
        (strcmp(product->symbol, "N") == 0 && strcmp(product->symbol, "H") == 0)) {
        *product = fscl_element_lookup("NH3", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 5: Iron (Fe) and Oxygen (O) react to form iron oxide (Fe2O3)
    if (strcmp(product->symbol, "Fe") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("Fe2O3", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 6: Magnesium (Mg) and Nitrogen (N) react to form magnesium nitride (Mg3N2)
    if (strcmp(product->symbol, "Mg") == 0 && strcmp(product->symbol, "N") == 0) {
        *product = fscl_element_lookup("Mg3N2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 7: Oxygen (O) and Sulfur (S) react to form sulfur dioxide (SO2)
    if (strcmp(product->symbol, "O") == 0 && strcmp(product->symbol, "S") == 0) {
        *product = fscl_element_lookup("SO2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 8: Aluminum (Al) and Fluorine (F) react to form aluminum fluoride (AlF3)
    if (strcmp(product->symbol, "Al") == 0 && strcmp(product->symbol, "F") == 0) {
        *product = fscl_element_lookup("AlF3", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 9: Silicon (Si) and Oxygen (O) react to form silicon dioxide (SiO2)
    if (strcmp(product->symbol, "Si") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("SiO2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 10: Phosphorus (P) and Oxygen (O) react to form phosphorus pentoxide (P4O10)
    if (strcmp(product->symbol, "P") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("P4O10", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 11: Sulfur (S) and Oxygen (O) react to form sulfur hexafluoride (SF6)
    if (strcmp(product->symbol, "S") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("SF6", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 12: Potassium (K) and Water (H2O) react to form potassium hydroxide (KOH)
    if (strcmp(product->symbol, "K") == 0 && strcmp(product->symbol, "H2O") == 0) {
        *product = fscl_element_lookup("KOH", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 13: Argon (Ar) and Fluorine (F) react to form argon fluoride (ArF)
    if (strcmp(product->symbol, "Ar") == 0 && strcmp(product->symbol, "F") == 0) {
        *product = fscl_element_lookup("ArF", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 14: Calcium (Ca) and Nitrogen (N) react to form calcium nitride (Ca3N2)
    if (strcmp(product->symbol, "Ca") == 0 && strcmp(product->symbol, "N") == 0) {
        *product = fscl_element_lookup("Ca3N2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 15: Titanium (Ti) and Chlorine (Cl) react to form titanium tetrachloride (TiCl4)
    if (strcmp(product->symbol, "Ti") == 0 && strcmp(product->symbol, "Cl") == 0) {
        *product = fscl_element_lookup("TiCl4", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 16: Vanadium (V) and Oxygen (O) react to form vanadium pentoxide (V2O5)
    if (strcmp(product->symbol, "V") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("V2O5", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 17: Chromium (Cr) and Oxygen (O) react to form chromium(III) oxide (Cr2O3)
    if (strcmp(product->symbol, "Cr") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("Cr2O3", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 18: Manganese (Mn) and Oxygen (O) react to form manganese(II) oxide (MnO)
    if (strcmp(product->symbol, "Mn") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("MnO", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 19: Nickel (Ni) and Oxygen (O) react to form nickel oxide (NiO)
    if (strcmp(product->symbol, "Ni") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("NiO", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 20: Copper (Cu) and Oxygen (O) react to form copper(II) oxide (CuO)
    if (strcmp(product->symbol, "Cu") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("CuO", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 21: Scandium (Sc) and Oxygen (O) react to form scandium(III) oxide (Sc2O3)
    if (strcmp(product->symbol, "Sc") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("Sc2O3", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 22: Titanium (Ti) and Oxygen (O) react to form titanium dioxide (TiO2)
    if (strcmp(product->symbol, "Ti") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("TiO2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 23: Vanadium (V) and Chlorine (Cl) react to form vanadium(V) chloride (VCl5)
    if (strcmp(product->symbol, "V") == 0 && strcmp(product->symbol, "Cl") == 0) {
        *product = fscl_element_lookup("VCl5", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 24: Chromium (Cr) and Oxygen (O) react to form chromium(VI) oxide (CrO3)
    if (strcmp(product->symbol, "Cr") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("CrO3", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 25: Manganese (Mn) and Oxygen (O) react to form manganese(IV) oxide (MnO2)
    if (strcmp(product->symbol, "Mn") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("MnO2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 26: Iron (Fe) and Chlorine (Cl) react to form iron(III) chloride (FeCl3)
    if (strcmp(product->symbol, "Fe") == 0 && strcmp(product->symbol, "Cl") == 0) {
        *product = fscl_element_lookup("FeCl3", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 27: Cobalt (Co) and Sulfur (S) react to form cobalt(II) sulfide (CoS)
    if (strcmp(product->symbol, "Co") == 0 && strcmp(product->symbol, "S") == 0) {
        *product = fscl_element_lookup("CoS", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 28: Nickel (Ni) and Fluorine (F) react to form nickel(II) fluoride (NiF2)
    if (strcmp(product->symbol, "Ni") == 0 && strcmp(product->symbol, "F") == 0) {
        *product = fscl_element_lookup("NiF2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 29: Copper (Cu) and Sulfur (S) react to form copper(I) sulfide (Cu2S)
    if (strcmp(product->symbol, "Cu") == 0 && strcmp(product->symbol, "S") == 0) {
        *product = fscl_element_lookup("Cu2S", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 30: Zinc (Zn) and Oxygen (O) react to form zinc oxide (ZnO)
    if (strcmp(product->symbol, "Zn") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("ZnO", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 31: Gallium (Ga) and Nitrogen (N) react to form gallium nitride (GaN)
    if (strcmp(product->symbol, "Ga") == 0 && strcmp(product->symbol, "N") == 0) {
        *product = fscl_element_lookup("GaN", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 32: Germanium (Ge) and Oxygen (O) react to form germanium dioxide (GeO2)
    if (strcmp(product->symbol, "Ge") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("GeO2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 33: Arsenic (As) and Oxygen (O) react to form arsenic pentoxide (As2O5)
    if (strcmp(product->symbol, "As") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("As2O5", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 34: Selenium (Se) and Hydrogen (H) react to form hydrogen selenide (H2Se)
    if (strcmp(product->symbol, "Se") == 0 && strcmp(product->symbol, "H") == 0) {
        *product = fscl_element_lookup("H2Se", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 35: Bromine (Br) and Oxygen (O) react to form bromine oxide (Br2O)
    if (strcmp(product->symbol, "Br") == 0 && strcmp(product->symbol, "O") == 0) {
        *product = fscl_element_lookup("Br2O", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }

    // Reaction 36: Krypton (Kr) and Fluorine (F) react to form krypton difluoride (KrF2)
    if (strcmp(product->symbol, "Kr") == 0 && strcmp(product->symbol, "F") == 0) {
        *product = fscl_element_lookup("KrF2", sizeof(elements) / sizeof(celement));
        return 1; // Success
    }
    return 0; // Failure
}

// Function to transform the product based on reaction rules
int fscl_element_transform(celement *product) {
    int reaction = 0;
    reaction = explosive_reaction(product);
    if (reaction == 1) {
        return reaction; // oh no an explosion in the lab
    }
    reaction = adding_reaction(product);
    if (reaction == 1) {
        return reaction; // made a new element to work with
    }
    puts("Reaction rule unknown");
    return 0; // Failure
} // end of func

// Function to create a copy of the given element
celement fscl_element_copy(celement element) {
    celement copy;
    strcpy(copy.symbol, element.symbol);
    copy.atomic_number = element.atomic_number;
    copy.atomic_weight = element.atomic_weight;
    return copy;
}

// Function to check if the atomic weight of the given element is within a specified range
int fscl_element_weight_within_range(celement element, double min_weight, double max_weight) {
    return (element.atomic_weight >= min_weight && element.atomic_weight <= max_weight);
} // end of func
