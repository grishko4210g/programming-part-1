#ifndef LIB_H_
#define LIB_H_

#define MAX_ROWS 4
#define MAX_COLS 4

// Find the minimum element in the upper triangle
int find_min(int *matrix, int rows, int cols);

// Swap the row with the maximum sum and the row with the minimum sum
int swap_the_lines(int *matrix, int rows, int cols);

// Count the number of negative elements
int negative_elements(int *matrix, int rows, int cols);

// Remove duplicates in 1D array
int remove_duplicates(int *matrix, int rows, int cols, int *output_1d_array);
#endif