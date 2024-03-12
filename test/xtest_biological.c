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

#include <fossil/xscience/biological.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_create_and_print) {
    xmock_io_setup();
    const char *sequence = "ATCG";
    cdna dna = fscl_dna_create(sequence);
    TEST_ASSERT_EQUAL_CSTRING(sequence, dna.sequence);
    TEST_ASSERT_EQUAL_INT(strlen(sequence), dna.length);

    // Redirect stdout to capture print output
    xmock_io_capture_output();
    fscl_dna_print(&dna);
    const char* printedOutput = xmock_io_get_output();
    xmock_io_restore_output();

    TEST_ASSERT_EQUAL_CSTRING("DNA Sequence: ATCG\n", printedOutput);

    fscl_dna_erase(&dna);
    xmock_io_teardown();
}

XTEST_CASE(test_mutate) {
    const char *sequence = "ATCG";
    cdna dna = fscl_dna_create(sequence);

    fscl_dna_mutate(&dna, 1, 'G');
    TEST_ASSERT_EQUAL_CSTRING("GTCG", dna.sequence);

    fscl_dna_erase(&dna);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_biological_group) {
    XTEST_RUN_UNIT(test_create_and_print);
    XTEST_RUN_UNIT(test_mutate);
} // end of fixture