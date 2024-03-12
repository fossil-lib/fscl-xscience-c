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
#include "fossil/xscience/decision.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create and initialize a decision
cdecision fscl_decision_create(const char* name, double score) {
    cdecision decision;
    decision.name = name;
    decision.score = score;
    return decision;
}

// Function to compare two decisions based on scores
int fscl_decision_compare(const cdecision* decision1, const cdecision* decision2) {
    if (decision1->score < decision2->score) {
        return -1;
    } else if (decision1->score > decision2->score) {
        return 1;
    } else {
        return 0;
    }
}

// Function to make a decision based on weighted scores
cdecision fscl_decision_make_weighted(const cdecision* decisions, int num_decisions, const double* weights) {
    if (num_decisions <= 0) {
        return fscl_decision_create("Invalid Decision", 0.0);
    }

    double total_score = 0.0;
    for (int i = 0; i < num_decisions; ++i) {
        total_score += decisions[i].score * weights[i];
    }

    return fscl_decision_create("Weighted Decision", total_score);
}

// Function to aggregate scores of multiple decisions
double fscl_decision_aggregate_scores(const cdecision* decisions, int num_decisions) {
    if (num_decisions <= 0) {
        return 0.0;
    }

    double aggregate_score = 0.0;
    for (int i = 0; i < num_decisions; ++i) {
        aggregate_score += decisions[i].score;
    }

    return aggregate_score;
}

// Function to print a decision
void fscl_decision_print(const cdecision* decision) {
    printf("Decision: %s, Score: %f\n", decision->name, decision->score);
}
