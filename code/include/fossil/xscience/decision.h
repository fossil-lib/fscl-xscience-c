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
#ifndef FSCL_DECISION_H
#define FSCL_DECISION_H

#ifdef __cplusplus
extern "C"
{
#endif

// Decision type definition
typedef struct {
    char* name;
    double score;
} cdecision;

// =================================================================
// Avalible functions
// =================================================================

// Function to create and initialize a decision
cdecision fscl_decision_create(char* name, double score);

// Function to compare two decisions based on scores
int fscl_decision_compare(const cdecision* decision1, const cdecision* decision2);

// Function to make a decision based on weighted scores
cdecision fscl_decision_make_weighted(const cdecision* decisions, int num_decisions, const double* weights);

// Function to aggregate scores of multiple decisions
double fscl_decision_aggregate_scores(const cdecision* decisions, int num_decisions);

// Function to print a decision
void fscl_decision_print(const cdecision* decision);

#ifdef __cplusplus
}
#endif

#endif