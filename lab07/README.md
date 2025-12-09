# Lab 07 — Implementing a Function Library with Unit Testing
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** November 22, 2025  
**Variant:** 11(eleven)

---
 
## Task Description
 
1. Implement the mathematical expressions as functions in a library.
2. Create a unit test for eachfunction using the Unity framework.
3. Configure the project structure and Makefile to build tle library, main application, and test suite.

## Mathematical Expression

```
No. 11 (11, 15, 20, 5)

Func.1: x + ln(y + 1) - √z * cos(w);
Func.2: x - √y * (exp(z) + sin(w));
Func.3: x + exp(y) * √z - sin(w);
Func.4: x*sin(y)/cos(z)+w - √v;

```
## Structure

```
lab07/
├── include/
|  └── lib.h           # Header file for library function
├── src/               # Implementation files
|  └── lib.c           #Implementation of library functions
├── test/
|  └── test_lib.c      # Unit tests for library functions
├── Unity/             # Unity testing framework 
|  └── src/
|  |  └──   unity.c    #Unity source file
|  └── include/
|     └──   unity.h    #Unity header file 
├── main.c             #Main application file
├── Makefile           #Build file
└── README.md          #Project documentation
```
 
## Lab Instructions
 
1. Unity Framework Setup: git clone git@github.com:ThrowTheSwitch/Unity.git
2. Use the function table and select the functions according to the option(in my case option 11)
 
### How to Build include/lin.h
 
```bash
#ifndef LIB_H_
#define LIB_H_

double f11(double x, double y, double z, double w); // x + log(y+1) - √z * cos(w)
double f15(double x, double y, double z, double w); // x - √y * (exp(z) + sin(w))
double f20(double x, double y, double z, double w); // x + exp(y) * √z - sin(w)
double f5(double x, double y, double z, double w, double v); // x * sin(y) / cos(z) + w -√v

#endif // LIB_H_
```
 ### How to Build src/lin.c

 ```bash

 #include "lib.h"
#include <math.h>

double f11(double x, double y, double z, double w)
{
    if ( z < 0.0 || y <= -1.0 ) {
        return NAN;
    }
    return x + log(y+1.0) - sqrt(z) * cos(w);
}

// func.15 x - √y * (exp(z) + sin(w))

double f15(double x, double y, double z, double w)
{
    if ( y < 0.0 ) {
        return NAN;
    }
    return x - sqrt(y) * (exp(z) + sin(w));

}

// funct.20 x  +exp(y) * √z - sin(w)

double f20(double x, double y, double z, double w)
{
    if( z < 0.0 ) {
        return NAN;
    }
    return x + exp(y) * sqrt(z) - sin(w);
}

// func.5 x * sin(y) / cos(z) + w -√v
double f5(double x, double y, double z, double w, double v)
{
    if (v < 0.0 || cos(z) == 0.0) {
        return NAN;
    }
    return x * sin(y) / cos(z) + w - sqrt(v);
}

```
### How to Build test/test_lib.c

```bash

#include "unity.h"

#include <limits.h>
#include "lib.h"

void setUp() {}

void tearDown () {}

// func.11:  x + log(y+1) - √z * cos(w)
void test_f11 (void) {
    double x = 2.0, y = 3.0, z = 4.0, w = 0.0;
    double result = f11(2.0, 3.0, 4.0, 0.0);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, 2.0 + log(3.0 + 1.0) - sqrt(4.0) * cos(0.0),
    result
    );
}
// func.15: x - √y * (exp(z) + sin(w))
void test_f15 (void) {
    double x = 5.0, y = 4.0, z = 1.0, w = 0.0;
    double result = f15(5.0, 4.0, 1.0, 0.0);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, 5.0 - sqrt(4.0) * (exp(1.0) + sin(0.0)), 
    result
);
}
// func.20: x + exp(y) * √z - sin(w)
void test_f20 (void) {
    double x = 1.0, y = 0.0, z = 9.0, w = 0.0;
    double result = f20(1.0, 0.0, 9.0, 0.0);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, 1.0 + exp(0.0) * sqrt(9.0) - sin(0.0),
    result 
);
}
// func.5: x * sin(y) / cos(z) + w -√v
void test_f5 (void) {
    double x = 2.0, y = 1.0, z = 0.0, w = 1.0, v = 4.0;
    double result = f5(2.0, 1.0, 0.0, 1.0, 4.0);
    double expected = (x * sin(y)) / cos(z) + w - sqrt(v);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, expected, result);

}

// main
int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_f11);
    RUN_TEST(test_f15);
    RUN_TEST(test_f20);
    RUN_TEST(test_f5);

    return UNITY_END();
    }
```
### How to Build main.c

```bash
#include <stdio.h>
#include "lib.h"

int main ()
{
    UNITY_BEGIN ();
    RUN_TEST (test_mul);
    return UNITY_END ();
}
```
### How to Build Makefile

```bash
CC = gcc
CFLAGS = -Wall -Iinclude -IUnity/include -fprofile-arcs -ftest-coverage
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

$(EXECUTABLE) : main.o libpoject.a
	$(CC) $(CFLAGS) -o $@ $^

libpoject.a: $(OBJ_FILES)
	ar rcs $@ $^

main.o: mainc.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES) libpoject.a
	$(CC) $(CFLAGS) -DUNITY_INCLUDE_DOUBLE -DUNITY_DOUBLE_TYPE=double \
	-o $@ $(UNITY_SRC) $^ -lm

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_EXECUTABLE) *.o libpoject.a *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report

```
### How to Run Tests
 
 
```bash
make test
./run_test
make clean
```
 ### Test Results

 ```bash
test/test_lib.c:46:test_f11:PASS
test/test_lib.c:47:test_f15:PASS
test/test_lib.c:48:test_f20:PASS
test/test_lib.c:49:test_f5:PASS

-----------------------
4 Tests 0 Failures 0 Ignored 
OK
 ```
## Report
 
The goal of this lab is to Implement four functions according to the expressions given in the table. These functions will be included in the library and unit tests will be developed using Unity to verify the correctness of each function.
 
In this lab, I completed the following tasks: 
1. Implement the mathematical expressions as functions in a library.
2. Create a unit test for eachfunction using the Unity framework.
3. Configure the project structure and Makefile to build tle library, main application, and test suite.
 
TBD
 
---
 
### Observations and Conclusion
 
Observations:
1. All four mathematical functions (f11, f15, f20, f5) were successfully implemented in the library.
2. Unit tests using the Unity framework verified the correctness of each function. All tests passed successfully, confirming that the library functions produce the expected results.
3. The project structure with separate directories for source code, headers, and tests allows for clear organization and easy maintenance.
4. The Makefile automates compilation, testing, and cleanup, reducing the chance of manual errors.

Conclusion:
1. The lab successfully demonstrates the creation of a reusable function library with automated unit testing.
2. Writing unit tests early helps to identify and correct errors in the mathematical functions.
3. Organizing code into a library and using a testing framework improves code reliability and maintainability.
4. The experience reinforced the importance of test-driven development and proper project structure in C programming.
 
TBD
 
---