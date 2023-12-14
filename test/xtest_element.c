/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.home.blog>
*/
#include "trilobite/xscience/element.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts


//
// XUNIT TEST CASES
//

// Test case for creating a new element
XTEST_CASE(test_create_element) {
    celement element = element_create("Xx", 99, 99.99);
    TEST_ASSERT_EQUAL_STRING("Xx", element.symbol);
    TEST_ASSERT_EQUAL_INT(99, element.atomic_number);
}

// Test case for adding elements together
XTEST_CASE(test_add_elements) {
    celement element1 = element_lookup("H", element_count_chart());
    celement element2 = element_lookup("O", element_count_chart());
    celement result = element_add(element1, element2);

    TEST_ASSERT_EQUAL_INT(9, result.atomic_number);
}

XTEST_CASE(test_element_copy) {
    celement original_element = element_create("O", 8, 16.0);
    celement copied_element = element_copy(original_element);
    
    TEST_ASSERT_EQUAL_STRING("O", copied_element.symbol);
    TEST_ASSERT_EQUAL(8, copied_element.atomic_number);
}

XTEST_CASE(test_element_weight_within_range) {
    celement original_element = element_create("O", 8, 16.0);
    
    TEST_ASSERT_TRUE(element_weight_within_range(original_element, 10.0, 20.0));
    TEST_ASSERT_TRUE(element_weight_within_range(original_element, 15.0, 20.0));
    TEST_ASSERT_FALSE(element_weight_within_range(original_element, 16.1, 20.0));
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(test_element_group) {
    XTEST_RUN_UNIT(test_create_element, runner);
    XTEST_RUN_UNIT(test_add_elements,   runner);
    XTEST_RUN_UNIT(test_element_copy,   runner);
    XTEST_RUN_UNIT(test_element_weight_within_range, runner);
} // end of function main
