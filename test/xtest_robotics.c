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

#include <fossil/xscience/robotics.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_distance) {
    TEST_ASSERT_DOUBLE_EQUAL(5.196, fscl_robotic_distance(1.0, 2.0, 3.0, 4.0, 5.0, 6.0));
}

XTEST_CASE(test_dot_product) {
    TEST_ASSERT_DOUBLE_EQUAL(56.0, fscl_robotic_dot_product(2.0, 3.0, 4.0, 5.0, 6.0, 7.0));
}

XTEST_CASE(test_cross_product) {
    double resultX, resultY, resultZ;
    fscl_robotic_cross_product(2.0, 3.0, 4.0, 5.0, 6.0, 7.0, &resultX, &resultY, &resultZ);
    TEST_ASSERT_DOUBLE_EQUAL(-3.0, resultX);
    TEST_ASSERT_DOUBLE_EQUAL(6.0, resultY);
    TEST_ASSERT_DOUBLE_EQUAL(-3.0, resultZ);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_robotics_group) {
    XTEST_RUN_UNIT(test_distance);
    XTEST_RUN_UNIT(test_dot_product);
    XTEST_RUN_UNIT(test_cross_product);
} // end of fixture
