#ifndef LIB_H_
#define LIB_H_
#include <stdint.h>

int64_t calculate_sum(int *arr, int n); 
int find_number_index(int *arr, int n, int target);
void shift_right(int *arr, int n);
void bubble_sort (int *arr, int n);
int find_mode(int *arr, int n);

#endif