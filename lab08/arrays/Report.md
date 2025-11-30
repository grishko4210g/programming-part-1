# Lab 08_01 — One-Dimensional Array Exercises
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** November 25, 2025  
**Variant:** 11(eleven)
 
---
 
## Task Description
 
You need to implement functions that work with arrays and fulfil the following conditions:
1. Develop an algorithm.
2. Be implemented as separate functions.
3. Use randomly generated values to populate arrays for testing purposes.
 
 ## Table of Tasks by Varian:
 Variant: 11(eleven)

 ```
Group 1: Calculation and Aggregation -> Sum of elements;
Group 2: Element Search -> Search for a specific number;
Group 3: Element Manipulation -> Shift elements to the right;
Group 4: Sorting -> Bubble Sort;
Group 5: Analysis and Statistics -> Mode of the array.

 ```
## Structure
 
```
lab08/arrays
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
 
Fulfil the following conditions:
1. Develop an algorithm.
2. Be implemented as separate functions.
3. Use randomly generated values to populate arrays for testing purposes.
 
### How to Build include/lib.h
 
 
```bash
#ifndef LIB_H_
#define LIB_H_
#include <stdint.h>

int64_t calculate_sum(int *arr, int n); 
int find_number_index(int *arr, int n, int target);
void shift_right(int *arr, int n);
void bubble_sort (int *arr, int n);
int find_mode(int *arr, int n);

#endif
```
 
 ### How to Build test/test_lib.c

 ```bash
#include "lib.h"
#include <stdint.h>

// sum of elements
int64_t calculate_sum(int *arr, int n) {
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// search of a specific number
int find_number_index(int *arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// shift elements to the right
void shift_right(int *arr, int n) {
    if (n <= 1) return;

    int last = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

// Bubble Sort
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

// mode of the array
int find_mode(int *arr, int n) {
    if (n == 0) return 0;

    int maxCount = 0;
    int modeValue = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) count++;
        }

        if (count > maxCount) {
            maxCount = count;
            modeValue = arr[i];
        }
    }
    return modeValue;
}

 ```

 ### How to Build src/lib.c

 ```bash
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

 ```

 ### How to Build test/test_lib.c
Unity Framework Setup:

 ```bash
git clone git@github.com:ThrowTheSwitch/Unity.git
 ```

 ### How to Build main.c
 ```bash
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
 ```

  ### How to Build Makefile

  ```bash
CC = gcc
CFLAGS = -Wall -Iinclude -IUnity/include -IUnity/src -fprofile-arcs -ftest-coverage
LDFLAGS = -L. -fprofile-arcs -ftest-coverage
SRC_DIR = src
TEST_DIR = test
UNITY_SRC = Unity/src/unity.c

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

EXECUTABLE = main
TEST_EXECUTABLE = run_test

.PHONY: all clean test

all: $(EXECUTABLE)

$(EXECUTABLE): main.o libpoject.a
	$(CC) $(CFLAGS) -o $@ $^

libpoject.a: $(OBJ_FILES)
	ar rcs $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES) libpoject.a
	$(CC) $(CFLAGS) -o $@ $(UNITY_SRC) $^ -lm

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_EXECUTABLE) *.o libpoject.a *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report

  ```
### How to Run Tests
 
```bash
make test
make clean
```
 
 ### Test Results
 
```bash
make test
gcc -Wall -Iinclude -IUnity/include -IUnity/src -fprofile-arcs -ftest-coverage -c src/lib.c -o src/lib.o
ar rcs libpoject.a src/lib.o
gcc -Wall -Iinclude -IUnity/include -IUnity/src -fprofile-arcs -ftest-coverage -o run_test Unity/src/unity.c test/test_lib.c libpoject.a -lm
./run_test
test/test_lib.c:67:test_calculate_sum_positive:PASS
test/test_lib.c:68:test_calculate_sum_mixed:PASS
test/test_lib.c:69:test_find_number_found_middle:PASS
test/test_lib.c:70:test_shift_right_standard:PASS
test/test_lib.c:71:test_shift_right_singe_element:PASS
test/test_lib.c:72:test_bubble_sort_unsorted:PASS
test/test_lib.c:73:test_bubble_sort_already_sorted:PASS
test/test_lib.c:74:test_find_mode_unique_mode:PASS
test/test_lib.c:75:test_find_mode_multiple_modes:PASS

-----------------------
9 Tests 0 Failures 0 Ignored 
OK
```
 
---
## Report
 
The goal of this lab is to working with one-dimensional arrays in C; implementing basic algorithms (sum, search, sorting, shifting, mode); separating code into modules(lib.c and lib.c); using unit testing to validate functionality; organizing a structured project with "Makefile"
 
In this lab, I completed the following tasks:
1. Develop an algorithm.
2. Be implemented as separate functions.
3. Use randomly generated values to populate arrays for testing purposes.
4. 
---
 
### Observations and Conclusion
 
The laboratory work was successfully completed. All task according to Variant 11(eleven) were implemented, tested, and validated. The program works correctly, all tests passed and the project fully meets the requirements.
 
---