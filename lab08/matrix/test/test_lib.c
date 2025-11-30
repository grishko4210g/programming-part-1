#include "unity.h"
#include "lib.h"
#define TEST_ARRAY_SIZE 6

void setUp(void) {
}
void tearDown(void) {
}
// Find the minimum element in the upper triangle
void test_find_min(void) {
    int matrix[4][4] = {
        { 7, 5, 8, 10},
        {-2, 12, 6, 5},
        { 4, 3, 6, 1 },
        { 8, 5, -3, 9 }
    };
    int rows = 4;
    int cols = 4;

    int expected = 1;
    int actual = find_min(&matrix[0][0], rows, cols);

    TEST_ASSERT_EQUAL_INT(expected, actual);

}

// Swap the row with the maximum sum and the row with the minimum sum
void test_swap_the_lines(void) {
    int matrix [4][4] = {
        { 7, 5, 8, 10},  //30 -> max sum
        {-2, 12, 6, 5},  //21
        { 4, 3, 6, 1 },  //14 -> min sum
        {8, 5, -3, 9 }   //19
    };
    int rows = 4;
    int cols = 4;

    int expected_matrix[4][4] = {
        { 4, 3, 6, 1 }, // exchange min
        {-2, 12, 6, 5},
        { 7, 5, 8, 10}, // exchange max
        {8, 5, -3, 9 }
    };
    swap_the_lines(&matrix[0][0], rows, cols);

    TEST_ASSERT_EQUAL_INT_ARRAY(&expected_matrix[0][0], &matrix[0][0], rows * cols);
}

// Count the number of negatibe elements
void test_negative_elements(void) {
    int matrix [4][4] = {
        { 7, 5, 8, 10},
        {-2, 12, 6, 5},
        { 4, 3, 6, 1 },
        {8, 5, -3, 9 }
    };
    int rows = 4;
    int cols = 4;

    int expected = 2; // -2, -3
    int actual = negative_elements(&matrix[0][0], rows, cols);

    TEST_ASSERT_EQUAL_INT(expected, actual);

}
// Remove duplicates in 1D array
void test_remove_duplicates (void) {
    int matrix [2][4] = {
        {3, 4, 7, 8},
        {1, 2, 3, 4}
    };
    int rows = 2;
    int cols = 4;

    int output_buffer[rows * cols];
    int expected_array[] = {3, 4, 7, 8, 1, 2};
    int expected_size = 6;

    int actual_size = remove_duplicates(&matrix[0][0], rows, cols, output_buffer);

    TEST_ASSERT_EQUAL_INT(expected_size, actual_size);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, output_buffer, expected_size);

}
// main
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_find_min);
    RUN_TEST(test_swap_the_lines);
    RUN_TEST(test_negative_elements);
    RUN_TEST(test_remove_duplicates);
    
    return UNITY_END();
}