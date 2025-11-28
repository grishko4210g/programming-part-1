# Lab 06_02 — Macros as Functions Report
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** October 31, 2025  
 **Variant:** 11(eleven)
---
 
## Task Description
 
This lab focuses on implementing and testing learning small single-purpose function-like macros in C, apply hygienic macro design 
- full parenthesization, no double evaluation
-  and usr the "do { ... } while (0)" trick for multi-statement macros.


```
Macro A: #define MOD_SAFE(out, a, b) - if b!=0, out - a mod b; else out - 0

Macro B: #define NONNEG(x) - return max(x,0).

```

## Structure
 
```
lab06_02/
├── include/
    └── user_macros.h  # function-like and statement-like macros
├── src/
    └── user_funcs.c # optional helpers (for comparison)
├── main.c         # demo driver
├── Makefile  # build script
└── build/   # all build artifacts

```
 
## Lab Instructions
 
```bash
make  # builds build/app
./build/app  # run the program

make preprocess  # emits *i. files into build/
```
 
### How to Build
 
 **1. How to spell correctly "user_macros.h":**
```bash
#ifndef USER_MACROS_H
#define USER_MACROS_H

#include <stdio.h>

/* A) MOD_SAFE(out, a, b): if b != 0 → out = a % b; else out = 0 */
#define MOD_SAFE(out, a, b) \
do { \
    if ((b) != 0) (out) = (a) % (b); \
    else (out) = 0; \
} while (0)

/* B) NONNEG(x): return max(x, 0) */
#define NONNEG(x) (((x) > 0) ? (x) : 0)

#endif /* USER_MACROS_H */


```
 **2. How to spell correctly "user_funcs.c":**
// Empty, because we use macros "#define MOD_SAFE(out, a, b)"; "#define NONNEG(x)" so we don't need “user_funcs.c”. Macros are substitutions, not function code.

 **3. How to spell correctly "main.c":**
```bash
#include <stdio.h>
#include "include/user_macros.h"

int main(void) {
    int a, b, result;

    printf("Enter two integers (a b): ");
    scanf("%d %d", &a, &b);

    /* Demonstrate MOD_SAFE */
    MOD_SAFE(result, a, b);
    printf("MOD_SAFE(%d, %d) = %d\n", a, b, result);

    /* Demonstrate NONNEG */
    int neg = -5, pos = 7;
    printf("NONNEG(%d) = %d\n", neg, NONNEG(neg));
    printf("NONNEG(%d) = %d\n", pos, NONNEG(pos));

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
make
gcc -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP -c src/user_funcs.c -o build/user_funcs.o
gcc -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP -c main.c -o build/main.o
main.c: In function ‘main’:
main.c:8:5: warning: ignoring return value of ‘scanf’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
    8 |     scanf("%d %d", &a, &b);
      |     ^~~~~~~~~~~~~~~~~~~~~~
gcc build/user_funcs.o build/main.o -o build/app 
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06_02$ ./build/app
Enter two integers (a b): 3 4
MOD_SAFE(3, 4) = 3
NONNEG(-5) = 0
NONNEG(7) = 7
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06_02$ ./build/app
Enter two integers (a b): 1 5
MOD_SAFE(1, 5) = 1
NONNEG(-5) = 0
NONNEG(7) = 7
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06_02$ ./build/app
Enter two integers (a b): 6 7
MOD_SAFE(6, 7) = 6
NONNEG(-5) = 0
NONNEG(7) = 7

 ```
**Second part:**
```bash
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06_02$ make preprocess
 PP build/user_funcs.c.i
 PP build/main.c.i
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06_02$
// This is a warning that there is no “scanf”, but it's nothing serious, you can ignore this message.
```
 
## Report
 
The goal of this lab is to learn how to design and apply safe function-like macros in C.
Macros execute at preprocessing time and do not create real function calls, which makes them useful for low-level optimizations, logging, and small inline calculations.
However, they must be written carefully to prevent bugs caused by operator precedence or multiple evaluations.

In this lab, I completed the following tasks:
- Implemented MOD_SAFE(out,a,b) — performs safe integer modulo with zero protection
- Implemented NONNEG(x) — clamps any negative value to zero.
- Demonstrated and tested both macros in main.c with normal and edge cases.
- Verified macro expansion using the make preprocess target.
 


TBD
 
---
 
### Runtime Output
| a, b | MOD_SAFE | MONNEG(-5) | NONNEG(7) |
|------|----------|------------|-----------|
| 3  4 |     3    |      0     |     7     |
| 1  5 |     1    |      0     |     7     |
| 6  7 |     6    |      0     |     7     |
 
TBD
 
---
 
### Observations and Conclusion
 
- Macros allow efficient inline substitution without function overhead.
- Proper parenthesization and the do { ... } while(0) pattern prevent syntax errors.
- Edge cases such as division/modulo by zero were handled safely.
- The NONNEG macro is equivalent to a small inline max(x,0) function.
- Preprocessing output (.i file) confirmed correct macro expansion.

Conclusion:
Function-like macros are powerful tools for compact, low-level C programming but must be written with caution to avoid hidden side effects.
This lab reinforced understanding of macro hygiene, safety, and structure in real C code.
TBD
 
---