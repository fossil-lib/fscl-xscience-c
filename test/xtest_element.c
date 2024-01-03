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
#include "fossil/xscience/element.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts


//
// XUNIT TEST CASES
//

// Test case for creating a new element
XTEST_CASE(test_create_element) {
    celement element = fscl_element_create("Xx", 99, 99.99);
    TEST_ASSERT_EQUAL_STRING("Xx", element.symbol);
    TEST_ASSERT_EQUAL_INT(99, element.atomic_number);
}

// Test case for adding elements together
XTEST_CASE(test_add_elements) {
    celement element1 = fscl_element_lookup("H", fscl_element_count_chart());
    celement element2 = fscl_element_lookup("O", fscl_element_count_chart());
    celement result = fscl_element_add(element1, element2);

    TEST_ASSERT_EQUAL_INT(9, result.atomic_number);
}

XTEST_CASE(test_fscl_element_copy) {
    celement original_element = fscl_element_create("O", 8, 16.0);
    celement copied_element = fscl_element_copy(original_element);
    
    TEST_ASSERT_EQUAL_STRING("O", copied_element.symbol);
    TEST_ASSERT_EQUAL(8, copied_element.atomic_number);
}

XTEST_CASE(test_fscl_element_weight_within_range) {
    celement original_element = fscl_element_create("O", 8, 16.0);
    
    TEST_ASSERT_TRUE(fscl_element_weight_within_range(original_element, 10.0, 20.0));
    TEST_ASSERT_TRUE(fscl_element_weight_within_range(original_element, 15.0, 20.0));
    TEST_ASSERT_FALSE(fscl_element_weight_within_range(original_element, 16.1, 20.0));
}

// Test case for a non-explosive reaction
XTEST_CASE(test_non_explosive_reaction) {
    celement product = fscl_element_create("H2O", 37, 18.015);
    TEST_ASSERT_EQUAL_INT(0, fscl_element_transform(&product));
}

// Test case for an explosive reaction
XTEST_CASE(test_explosive_reaction) {
    celement product = fscl_element_create("Na", 11, 22.990);
    TEST_ASSERT_EQUAL_INT(1, fscl_element_transform(&product));
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_fscl_element_group) {
    XTEST_RUN_UNIT(test_non_explosive_reaction);
    XTEST_RUN_UNIT(test_explosive_reaction);
    XTEST_RUN_UNIT(test_create_element);
    XTEST_RUN_UNIT(test_add_elements);
    XTEST_RUN_UNIT(test_fscl_element_copy);
    XTEST_RUN_UNIT(test_fscl_element_weight_within_range);
} // end of function main
