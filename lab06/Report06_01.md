# Lab 06_01 — User Function Report
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** October 31, 2025  
 **Variant:** 11(eleven)
---
 
## Task Description
 
This lab focuses on implementing and testing two small single-purpose functions as defined in my  variant .
Each function must:
Have a clear signature and correct parameter passing;
Check inputs for validity and handle exceptional cases;
Be declared in include/user_funcs.h and implemented in src/user_funcs.c;
Be demonstrated from main.c with several test cases.

```
Function A: int div_safe(int a, int b, int *ok) - safe division.

Function B: int mod_safe(int a, int b, int *ok) - safe modulo.

```

## Structure
 
```
lab06/
├── include/
    └── user_funcs.h  # function declarations (prototypes)
├── src/
    └── user_funcs.c # function implementations
├── main.c         # demo/driver (calls my functions)
├── Makefile  # build script
└── build/   # all build artifacts (created by make)

```
 
## Lab Instructions
 
```bash
make  # builds build/app
./build/app  # run the program

make asm  # emits *.s files into build/
make preprocess  # emits *i. files into build/
make clean  # removes build/
```
 
### How to Build
 
 **1. How to spell correctly "user_funcs.h":**
```bash
#ifndef USER_FUNCS_H
#define USER_FUNCS_H

int div_safe(int a, int b, int *ok);
int mod_safe(int a, int b, int *ok);

#endif /* USER_FUNCS_H */

```
 **2. How to spell correctly "user_funcs.h":**
```bash
#include "user_funcs.h"

// Safe integer division
int div_safe(int a, int b, int *ok)
{
    if (b == 0) {
        *ok = 0;
        return 0;
    }
    *ok = 1;
    return a / b;
}
int mod_safe(int a, int b, int *ok)
{
    if (b == 0) {
        *ok = 0;
        return 0;
    }
    *ok = 1;
    return a % b;
}

```
 **3. How to spell correctly "main.c":**
```bash
#include <stdio.h>
#include "user_funcs.h"

int main(void)
{
    int a, b;
    int ok;
    int result;

    printf("Enter two integers (a b): ");
    scanf("%d %d", &a, &b);

    // Test safe division
    result = div_safe(a, b, &ok);
    if (ok)
        printf("div_safe(%d, %d) = %d\n", a, b, result);
    else
        printf("div_safe: division by zero!\n");

    // Test safe modulo
    result = mod_safe(a, b, &ok);
    if (ok)
        printf("mod_safe(%d, %d) = %d\n", a, b, result);
    else
        printf("mod_safe: modulo by zero!\n");

    return 0;
}
```
 **4. How to spell correctly "Makefile":**
 ```bash
CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP
LDFLAGS := -lm

BUILD := build
SRC_DIR := src
INC_DIR := include

SRCS := $(wildcard $(SRC_DIR)/*.c) main.c
OBJS := $(patsubst %.c,$(BUILD)/%.o,$(notdir $(SRCS)))
DEPS := $(OBJS:.o=.d)

vpath %.c . $(SRC_DIR)

.PHONY: all exe asm preprocess clean
all: exe

exe: $(BUILD)/app

$(BUILD)/app: $(OBJS) | $(BUILD)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD)/%.o: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

asm: | $(BUILD)
	@for s in $(SRCS); do \
		b=$$(basename $${s##*/}); \
		echo " AS $(BUILD)/$$b.s"; \
		$(CC) $(CFLAGS) -S $$s -o $(BUILD)/$$b.s; \
	done

preprocess: | $(BUILD)
	@for s in $(SRCS); do \
		b=$$(basename $${s##*/}); \
		echo " PP $(BUILD)/$$b.i"; \ // Why is “$${s##*/}” written instead of “(notdir)” in the “asm” and ‘preprocess’ sections? Because it writes an error saying that “notdir” does not exist. //
		$(CC) $(CFLAGS) -E $$s -o $(BUILD)/$$b.i; \
	done

$(BUILD):
	@mkdir -p $(BUILD)

clean:
	@rm -rf $(BUILD)

-include $(DEPS)

 ```
### How to Run Tests
 

```bash
make  # builds build/app
./build/app  # run the program
```
 ### Test Results
 **First part:**
 ```bash
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06$ ./build/app
Enter two integers (a b): 2 4
div_safe(2, 4) = 0
mod_safe(2, 4) = 2
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06$ ./build/app
Enter two integers (a b): 1 7
div_safe(1, 7) = 0
mod_safe(1, 7) = 1
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06$ ./build/app
Enter two integers (a b): 4 5
div_safe(4, 5) = 0
mod_safe(4, 5) = 4

 ```
**Second part:**
```bash
make asm 
AS build/user_funcs.c.s 
AS build/main.c.sm
ain.c: In function ‘main’:m
ain.c:11:5: warning: ignoring return value of ‘scanf’ declared with attribute ‘warn_unused_result’ [-Wunused-result] 
  11 |     scanf("%d %d", &a, &b); 
     |     ^~~~~~~~~~~~~~~~~~~~~~g
rishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06$ make preprocess 
PP build/user_funcs.c.i 
PP build/main.c.ig
rishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06$
// This is a warning that there is no “scanf”, but it's nothing serious, you can ignore this message.
```
 
## Report
 
The goal of this lab is to write small, single-purpose functions and demonstrate them from "main.c". Focus on:clear signatures, correct parameter passing(by value/ via pointer for outputs), and robust control flow (if/else, loops, switch).
 
In this lab, I completed the following tasks:
- Implemented the “div_safe” function for safe division.
- Implemented the “mod_safe” function for safe division remainder.
- Tested their operation in “main.c” with various test values.
TBD
 
---
 
### Runtime Output
| a, b | div_safe | mod_safe |
|------|----------|----------|
| 2  4 |     0    |     2    |
| 1  7 |     0    |     1    |
| 4  5 |     0    |     4    |
 
TBD
 
---
 
### Observations and Conclusion
 
- The program handles invalid input gracefully by using an output flag instead of crashing
- Division and modulo results are correct for valid integer pairs.
- The structure with include/, src/, and Makefile mirrors professional C project organization.
- The compiler warnings are minimal and do not affect correctness.

Conclusion:
I successfully implemented two safe arithmetic functions using proper C function declarations, parameter passing, and defensive programming techniques.
The lab improved my understanding of function interfaces and error handling in C.
 
TBD
 
---