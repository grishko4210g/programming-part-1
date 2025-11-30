# Lab 08_02 — 2D Arrays
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** November 25, 2025  
**Variant:** 11(eleven) 
 
---
 
## Task Description
 
```
This lab focuses on implementing and testing a set of functions for processing matrices and one-dimensional arrays. The task includes creating a header file, implementing the functions in a source file, integrating them into a main program and verifying correctness using automated tests.
```

### Tasks:
Variant: 11(eleven)
```
Task Group 1: Find the minimum element in the upper triagle;
Task Group 2: Swap the row with the maximum sum and the row with the minimum sum;
Task Group 3: Count the number of negative elements.
Task Group 4: Remove duplicates in 1D array
```
 
## Structure
 
```
lab08/matrix
|  └── lib.h        # Header file for library function
├──src/             # Implementation files
|  └── lib          #Implementation of library functions
├──test/
|  └── test_lib.    # Unit tests for library functions
├── Unity/          # Unity testing framework
├── main.c          #Main application file
├── Makefile        #Build file
└── README.md       #Project documentation
```
 
## Lab Instructions
 
1. Each task must be implemented as a separate function with appropriate parameters to handle matrix dimensions. The function should either return the result directly or modify the matrix in place.
2. For tasks the require a specific matrix size (odd or even), ensure that the matrix size is validated before processing.
3. Write unit test for each function using predefined test cases to verify its accuracy under different input scenarios.
 
### How to Build include/lib.h

```bash
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
```
 ### How to Build src/lib.c

 ```bash
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
 ```
 ### How to Build test/test_lib.c

```bash
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
```
 ### How to Build main.c

 ```bash
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
 ```
### How to Run Tests
 
```bash
make test
make clean
```
 
 ### Test Results
 
```bash
./run_test
test/test_lib.c:88:test_find_min:PASS
test/test_lib.c:89:test_swap_the_lines:PASS
test/test_lib.c:90:test_negative_elements:PASS
test/test_lib.c:91:test_remove_duplicates:PASS

-----------------------
4 Tests 0 Failures 0 Ignored 
OK
```
 
---
 
## Report
 
The goal of this lab is to the objective of this lab is to process 2D arrays in C, focusing on index-based operations, matrix manipulation, aggregate functions, and 1D representation of matrices. Each task should be implemented as a separate function and verify functionality using unit test.
 
In this lab, I completed the following tasks:
1. Task Group 1: Implemented a function that scans only the upper triangular part a 4x4 matrix(including the diagonal). The function correctly identifies the smallest number using linear indexing and boundary-controlled loops.
2. Task Group 2: Implemented a function that computes the sum of each row, determines which has the minimum and maximum sums and swaps them in place. Used temporary variables and the "ACCESS_ELEM" macro for correct index resolution.
3. Task Group 3: Implemented an element-by-element scan of the matrix to count negative values. Simple but essential to demonstrate traversal logic.
4. Task Group 4: Implementeed logic that converts the matrix into a 1D array, removes repeated values and stores unique elements in the output buffer.
5. Testing: All functions were tested using Unity. Test covered correctness for expected cases, including know matrix configurations.
 
---
 
  
### Observations and Conclusion
 
 During this laboratory work, I learned:
 1. How 2D arrays are represented in memory as flat 1D arrays.
 2. How to use pointer arithmetic and macros like "ACCESS_ELEM" to access matrix elements.
 3. How to implement matrix algorithms such as triangle-based traversal, computing row sums and array transformations.
 4. How to write and run unit test with the Unity framework to verify correctness automatically.
   The implementation successfully passed all unit tests, confirming that each function behaves as expected under the given conditions. This lab strengthened my understanding of multidimensional data processing, memory layout and software testing practices in C.

 
---