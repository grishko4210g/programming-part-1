#include <stdio.h>
#include "lib.h"

// print matrix
void print_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int rows = 4;
    int cols = 4;

    int matrix[4][4] = {
        { 5,  2, -3,  7},
        { 1, -8,  6,  4},
        { 9,  3, -2,  0},
        {-5, 11,  1,  2}
    };

    printf("Initial matrix:\n");
    print_matrix((int*)matrix, rows, cols);

    // Find the minimum element in the upper triangle
    int min_val = find_min((int*)matrix, rows, cols);
    printf("Minimum element in the upper triangle: %d\n\n", min_val);

    // Swap the row with the maximum sum and the row with the minimum sum
    int swapped = swap_the_lines((int*)matrix, rows, cols);
    if (swapped == 0) {
        printf("After swapping the row with the largest and smallestamounts:\n");
        print_matrix((int*)matrix, rows, cols);
    } else {
        printf("Error: swap_the_lines повернув %d\n\n", swapped);
    }

    // Count the number of negative elements
    int neg_count = negative_elements((int*)matrix, rows, cols);
    printf("Number of negative element: %d\n\n", neg_count);

    // Remove duplicates in 1D array
    int new_size = remove_duplicates((int*)matrix, rows, cols);
    printf("After removing duplicates:\n");

    for (int i = 0; i < new_size; i++) {
        printf("%d ", ((int*)matrix)[i]);
    }
    printf("Total number of elements after deletion: %d\n", new_size);

    return 0;
}
