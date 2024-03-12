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
#include "fossil/xscience/biological.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

cdna fscl_dna_create(const char *sequence) {
    cdna new_dna;
    new_dna.length = strlen(sequence);
    new_dna.sequence = malloc((new_dna.length + 1) * sizeof(char));
    strcpy(new_dna.sequence, sequence);
    return new_dna;
}

void fscl_dna_erase(cdna *dna) {
    free(dna->sequence);
    dna->sequence = NULL;
    dna->length = 0;
}

void fscl_dna_set_sequence(cdna *dna, const char *sequence) {
    free(dna->sequence);
    dna->length = strlen(sequence);
    dna->sequence = malloc((dna->length + 1) * sizeof(char));
    strcpy(dna->sequence, sequence);
}

void fscl_dna_print(const cdna *dna) {
    printf("DNA Sequence: %s\n", dna->sequence);
}

void fscl_dna_mutate(cdna *dna, int position, char mutation) {
    if (position >= 0 && position < dna->length) {
        dna->sequence[position] = mutation;
    } else {
        printf("Invalid mutation position\n");
    }
}

int fscl_dna_find_subsequence(const cdna *dna, const char *subsequence) {
    char *found = strstr(dna->sequence, subsequence);
    if (found != NULL) {
        return found - dna->sequence; // Return the position of the first occurrence
    } else {
        return -1; // Subsequence not found
    }
}

cdna fscl_dna_concatenate(const cdna *dna1, const cdna *dna2) {
    cdna concatenated_dna;
    concatenated_dna.length = dna1->length + dna2->length;
    concatenated_dna.sequence = malloc((concatenated_dna.length + 1) * sizeof(char));
    
    strcpy(concatenated_dna.sequence, dna1->sequence);
    strcat(concatenated_dna.sequence, dna2->sequence);
    
    return concatenated_dna;
}

cdna fscl_dna_extract_subsequence(const cdna *dna, int start, int length) {
    cdna extracted_dna;
    
    if (start >= 0 && start + length <= dna->length) {
        extracted_dna.length = length;
        extracted_dna.sequence = malloc((length + 1) * sizeof(char));
        strncpy(extracted_dna.sequence, dna->sequence + start, length);
        extracted_dna.sequence[length] = '\0'; // Null-terminate the sequence
    } else {
        printf("Invalid extraction parameters\n");
        extracted_dna = fscl_dna_create(""); // Return an empty sequence
    }
    
    return extracted_dna;
}