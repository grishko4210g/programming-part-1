#include "unity.h"
#include "lib.h"
#define TEST_ARRAY_SIZE 5

void setUp(void) {

}
void tearDown(void) {

}
// sum elements
void test_calculate_sum_positive(void) {
    int arr[] = {1, 2, 3, 4, 5};
    long long expected = 15;
    TEST_ASSERT_EQUAL_INT64(expected, calculate_sum(arr, TEST_ARRAY_SIZE));
}
void test_calculate_sum_mixed(void) {
    int arr[] = {-5, 10, 0, 1};
    long long expected = 6;
    TEST_ASSERT_EQUAL_INT64(expected, calculate_sum(arr, 4));
}
// search for a specific number
void test_find_number_found_middle(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int target = 30;
    TEST_ASSERT_EQUAL_INT(2, find_number_index(arr, 5, target));
}
// shift elements to the right
void test_shift_right_standard(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 1, 2, 3, 4};
    shift_right(arr, TEST_ARRAY_SIZE);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, TEST_ARRAY_SIZE);
}
void test_shift_right_singe_element(void) {
    int arr[] = {42};
    int expected[] = {42};
    shift_right(arr, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 1);
}
// Bubble Sort
void test_bubble_sort_unsorted(void) {
    int arr[] = {5, 1, 4, 2, 8};
    int expected[] = {1, 2, 4, 5, 8};
    bubble_sort(arr, TEST_ARRAY_SIZE);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, TEST_ARRAY_SIZE);
}
void test_bubble_sort_already_sorted(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    bubble_sort(arr, TEST_ARRAY_SIZE);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, TEST_ARRAY_SIZE);
}
// Mode of the array
void test_find_mode_unique_mode(void) {
    int arr[] = {1, 2, 7, 7, 7, 10}; 
    TEST_ASSERT_EQUAL_INT(7, find_mode(arr, 6));
}

void test_find_mode_multiple_modes(void) {
    int arr[] = {2, 2, 4, 5, 5, 8}; 
    TEST_ASSERT_EQUAL_INT(2, find_mode(arr, 6)); 
}
// main
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_calculate_sum_positive);
    RUN_TEST(test_calculate_sum_mixed);
    RUN_TEST(test_find_number_found_middle);
    RUN_TEST(test_shift_right_standard);
    RUN_TEST(test_shift_right_singe_element);
    RUN_TEST(test_bubble_sort_unsorted);
    RUN_TEST(test_bubble_sort_already_sorted);
    RUN_TEST(test_find_mode_unique_mode);
    RUN_TEST(test_find_mode_multiple_modes);
    return UNITY_END();
}

