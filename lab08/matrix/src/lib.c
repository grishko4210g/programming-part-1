#include "lib.h"
#include <stdio.h>
#include <limits.h>
#define ACCESS_ELEM(matrix, a, b, cols) ((matrix)[(a) * (cols) + (b)])

void print_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", ACCESS_ELEM(matrix, i, j, cols));

        }
        printf("\n");
    }
}
// Find the minimum element in the upper triangle
int find_min(int *matrix, int rows, int cols) {
    if (rows != cols) {
    printf("Error: the matrix has a size of 4x4. \n" );
        return -1;
    }

    int min = INT_MAX;

    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++) { // верхній трикутник
            int val = ACCESS_ELEM(matrix, i, j, cols);
            if (val < min) {
                min = val;
            }
        }
    }

    return min;
}


// Swap the row with the maximum sum and the row with the minimum sum
int swap_the_lines(int *matrix, int rows, int cols) {
    int maxRow = 0, minRow = 0;
    int maxSum = -1000000, minSum = 1000000;

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += ACCESS_ELEM(matrix,  i, j, cols);
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
        if (sum < minSum) {
            minSum = sum;
            minRow = i;
        }
    }
    // Exchange rows
    for (int j = 0; j < cols; j++) {
        int temp = ACCESS_ELEM(matrix, maxRow, j, cols);
        ACCESS_ELEM(matrix, maxRow, j, cols) = ACCESS_ELEM(matrix, minRow, j, cols);

        ACCESS_ELEM(matrix, minRow, j, cols) = temp;
    }
    return 0;
}
// Count the number of negative elements
int negative_elements(int *matrix, int rows, int cols) {
    int negative_count = 0;

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (ACCESS_ELEM(matrix, i, j, cols) < 0) {
                negative_count++;
            }
        }
    }
    return negative_count;
}
// Remove duplicates in 1D array
int remove_duplicates(int *matrix, int rows, int cols, int *output_1d_array) {
    int unique_count = 0;
    int total_elem = rows * cols;

    for (int k = 0; k < total_elem; k++) { 
        int current_elem = matrix[k];
        int is_duplicate = 0;

        // Сhecking if an element is in an array
        for( int u = 0; u < unique_count; u++) {
            if (output_1d_array[u] == current_elem) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            output_1d_array[unique_count] = current_elem;
            unique_count++;
        }
    }
    return unique_count;
}
