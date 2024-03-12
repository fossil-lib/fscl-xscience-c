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
#ifndef FSCL_BIOLOGIC_H
#define FSCL_BIOLOGIC_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    char *sequence;
    int length;
} cdna;

// =================================================================
// Avalible functions
// =================================================================



cdna fscl_dna_create(const char *sequence);
void fscl_dna_erase(cdna *dna);
void fscl_dna_set_sequence(cdna *dna, const char *sequence);
void fscl_dna_print(const cdna *dna);
void fscl_dna_mutate(cdna *dna, int position, char mutation);
int fscl_dna_find_subsequence(const cdna *dna, const char *subsequence);
cdna fscl_dna_concatenate(const cdna *dna1, const cdna *dna2);
cdna fscl_dna_extract_subsequence(const cdna *dna, int start, int length);

#ifdef __cplusplus
}
#endif

#endif