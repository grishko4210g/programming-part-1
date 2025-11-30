int main(void) {
    UNITY_BEGIN();
    
    // run test
    RUN_TEST(test_calculate_sum_positive);
    RUN_TEST(test_calculate_sum_mixed);
    
    RUN_TEST(test_find_number_found_middle);
    RUN_TEST(test_find_number_not_found);
    
    RUN_TEST(test_shift_right_standard);
    RUN_TEST(test_shift_right_single_element);
    
    RUN_TEST(test_bubble_sort_unsorted);
    RUN_TEST(test_bubble_sort_already_sorted);

    RUN_TEST(test_find_mode_unique_mode);
    RUN_TEST(test_find_mode_multiple_modes);
    
    return UNITY_END();
}