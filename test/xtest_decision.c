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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#include <fossil/xscience/decision.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_decision_create) {
    cdecision decision = fscl_decision_create("Test Decision", 0.75);
    TEST_ASSERT_EQUAL_STRING("Test Decision", decision.name);
    TEST_ASSERT_FLOAT_EQUAL(0.75, decision.score);
}

XTEST_CASE(test_decision_compare) {
    cdecision decision1 = fscl_decision_create("Option A", 0.8);
    cdecision decision2 = fscl_decision_create("Option B", 0.6);
    int result = fscl_decision_compare(&decision1, &decision2);
    TEST_ASSERT_EQUAL_INT(1, result);
}

XTEST_CASE(test_decision_make_weighted) {
    cdecision decisions[] = {{"Option A", 0.8}, {"Option B", 0.6}, {"Option C", 0.9}};
    double weights[] = {0.4, 0.3, 0.3};
    cdecision weighted_decision = fscl_decision_make_weighted(decisions, 3, weights);
    TEST_ASSERT_EQUAL_STRING("Weighted Decision", weighted_decision.name);
}

XTEST_CASE(test_decision_aggregate_scores) {
    cdecision decisions[] = {{"Option A", 0.8}, {"Option B", 0.6}, {"Option C", 0.9}};
    double total_score = fscl_decision_aggregate_scores(decisions, 3);
    TEST_ASSERT_FLOAT_EQUAL(2.3, total_score);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_decision_group) {
    XTEST_RUN_UNIT(test_decision_create);
    XTEST_RUN_UNIT(test_decision_compare);
    XTEST_RUN_UNIT(test_decision_make_weighted);
    XTEST_RUN_UNIT(test_decision_aggregate_scores);
} // end of fixture