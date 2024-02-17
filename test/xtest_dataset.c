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

#include <fossil/xscience/dataset.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_fscl_data_create_and_erase) {
    cdataset myDataset;
    fscl_data_create(&myDataset, 5);

    TEST_ASSERT_NOT_CNULLPTR(myDataset.data);
    TEST_ASSERT_EQUAL_UINT(5, myDataset.size);

    fscl_data_erase(&myDataset);

    TEST_ASSERT_CNULLPTR(myDataset.data);
    TEST_ASSERT_EQUAL_UINT(0, myDataset.size);
}

XTEST_CASE(test_fscl_data_fill_random) {
    cdataset myDataset;
    fscl_data_create(&myDataset, 10);

    fscl_data_fill_random(&myDataset);

    for (size_t i = 0; i < myDataset.size; ++i) {
        TEST_ASSERT_TRUE(myDataset.data[i] >= 0.0 && myDataset.data[i] <= 100.0);
    }

    fscl_data_erase(&myDataset);
}

XTEST_CASE(test_fscl_data_mean) {
    cdataset myDataset;
    fscl_data_create(&myDataset, 5);

    // Populate the dataset with known values
    for (size_t i = 0; i < myDataset.size; ++i) {
        myDataset.data[i] = i * 1.5;
    }

    double expected_mean = (0 * 1.5 + 1 * 1.5 + 2 * 1.5 + 3 * 1.5 + 4 * 1.5) / 5.0;
    double actual_mean = fscl_data_mean(&myDataset);

    TEST_ASSERT_DOUBLE_EQUAL(expected_mean, actual_mean);

    fscl_data_erase(&myDataset);
}

XTEST_CASE(test_fscl_data_add) {
    cdataset dataset1, dataset2, result;
    fscl_data_create(&dataset1, 3);
    fscl_data_create(&dataset2, 3);
    fscl_data_create(&result, 3);

    // Populate datasets with known values
    for (size_t i = 0; i < dataset1.size; ++i) {
        dataset1.data[i] = i * 2.0;
        dataset2.data[i] = i * 1.5;
    }

    fscl_data_add(&dataset1, &dataset2, &result);

    for (size_t i = 0; i < result.size; ++i) {
        double expected_value = i * 2.0 + i * 1.5;
        TEST_ASSERT_DOUBLE_EQUAL(expected_value, result.data[i]);
    }

    fscl_data_erase(&dataset1);
    fscl_data_erase(&dataset2);
    fscl_data_erase(&result);
}

XTEST_CASE(test_fscl_data_multiply) {
    cdataset dataset1, dataset2, result;
    fscl_data_create(&dataset1, 3);
    fscl_data_create(&dataset2, 3);
    fscl_data_create(&result, 3);

    // Populate datasets with known values
    for (size_t i = 0; i < dataset1.size; ++i) {
        dataset1.data[i] = i * 2.0;
        dataset2.data[i] = i * 1.5;
    }

    fscl_data_multiply(&dataset1, &dataset2, &result);

    for (size_t i = 0; i < result.size; ++i) {
        double expected_value = i * 2.0 * i * 1.5;
        TEST_ASSERT_DOUBLE_EQUAL(expected_value, result.data[i]);
    }

    fscl_data_erase(&dataset1);
    fscl_data_erase(&dataset2);
    fscl_data_erase(&result);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(test_dataset_group) {
    XTEST_RUN_UNIT(test_fscl_data_create_and_erase);
    XTEST_RUN_UNIT(test_fscl_data_fill_random);
    XTEST_RUN_UNIT(test_fscl_data_mean);
    XTEST_RUN_UNIT(test_fscl_data_add);
    XTEST_RUN_UNIT(test_fscl_data_multiply);
} // end of fixture