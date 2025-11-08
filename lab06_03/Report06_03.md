# Lab 06_03 — Callbacks in C Report
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** October 31, 2025  
 **Variant:** 11(eleven)
---
 
## Task Description
 
This lab focuses on implementing and testing how to define and use "callbacks" (fbnction pointers) in C. I implemented one simple function that receives another function as a parameter and calls it several times
This function emulates a simple game loop — it calls the function tick(frame) for every frame number from 0 to frames − 1.
If the callback pointer is NULL or frames <= 0, the function does nothing.
The program demonstrates different callbacks to show that the same frame_loop function can perform different actions depending on the user-provided function.

```
Function to implement: void frame_loop(int frames, void(*tick)(int)); - emulate game loop: call tick(frame).

```

## Structure
 
```
lab06_03/
├── include/
    └── callbacks.h  # typedef and prototype
├── src/
    └── callbacks.c # implementation
├── main.c         # demonstration
├── Makefile  # build script
└── build/   # build artifacts

```
 
## Lab Instructions
 
```bash
make  # builds build/app
./build/app  # run the program

```
 
### How to Build
 
 **1. How to spell correctly "callbacks.h":**
```bash
#ifndef CALLBACKS_H
#define CALLBACKS_H

// type of pointer to the function that accepts int
typedef void (*ActionInt)(int);

void frame_loop(int frames, ActionInt tick);

#endif 

```
 **2. How to spell correctly "callbacks.c":**
```bash
#include "callbacks.h"

void frame_loop(int frames, ActionInt tick) {
    if (!tick) return;     // if there isn't function
    if (frames <= 0) return; // if the number of frames is incorrect

    for (int frame = 0; frame < frames; ++frame) {
        tick(frame);       // calling callbacks function
    }
}

```

 **3. How to spell correctly "main.c":**
```bash
#include <stdio.h>
#include "include/callbacks.h"

// callback №1 — prints the frame number
void print_frame(int frame) {
    printf("Frame %d\n", frame);
}

// callback №2 —  shows progress as a percentage
void show_progress(int frame) {
    printf("Progress: %d%%\n", frame * 10);
}

// callback №3 — print a message every 2 frames
void notify_special(int frame) {
    if (frame % 2 == 0)
        printf("Even frame %d reached!\n", frame);
}

int main(void) {
    puts("=== Demo 1: print frames ===");
    frame_loop(5, print_frame);

    puts("\n=== Demo 2: progress ===");
    frame_loop(10, show_progress);

    puts("\n=== Demo 3: only even frames ===");
    frame_loop(6, notify_special);

    puts("\n=== Edge cases ===");
    frame_loop(0, print_frame);
    frame_loop(5, NULL);

    return 0;
}

```
 **4. How to spell correctly "Makefile":**
 ```bash
CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP
BUILD := build
SRC_DIR := src

SRCS := $(wildcard $(SRC_DIR)/*.c) main.c
OBJS := $(patsubst %.c,$(BUILD)/%.o,$(notdir $(SRCS)))
DEPS := $(OBJS:.o=.d)

vpath %.c . $(SRC_DIR)

.PHONY: all exe asm preprocess clean
all: exe

exe: $(BUILD)/app
$(BUILD)/app: $(OBJS) | $(BUILD)
	$(CC) $(OBJS) -o $@

$(BUILD)/%.o: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

asm: | $(BUILD)
	@for s in $(SRCS); do \
	b=$$(basename $$(notdir $$s)); \
	echo " AS $(BUILD)/$$b.s"; \
	$(CC) $(CFLAGS) -S $$s -o $(BUILD)/$$b.s; \
	done

preprocess: | $(BUILD)
	@for s in $(SRCS); do \
	b=$$(basename $$(notdir $$s)); \
	echo " PP $(BUILD)/$$b.i"; \
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
 ```bash
make
gcc -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP -c src/callbacks.c -o build/callbacks.o
gcc -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP -c main.c -o build/main.o
gcc build/callbacks.o build/main.o -o build/app
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06_03$ ./build/app
=== Demo 1: print frames ===
Frame 0
Frame 1
Frame 2
Frame 3
Frame 4

=== Demo 2: progress ===
Progress: 0%
Progress: 10%
Progress: 20%
Progress: 30%
Progress: 40%
Progress: 50%
Progress: 60%
Progress: 70%
Progress: 80%
Progress: 90%

=== Demo 3: only even frames ===
Even frame 0 reached!
Even frame 2 reached!
Even frame 4 reached!

=== Edge cases ===
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab06_03$
 ```
 
## Report
 
The goal of this lab is to understand the concept of callbacks in C — how one function can accept another function as a parameter and execute it. This technique enables flexible and reusable code design often used in games, GUI systems, and event-driven programs.

In this lab, I completed the following tasks:
- Implemented frame_loop(int frames, void(*tick)(int)) to repeatedly call a callback function for each frame.
Demonstrated several callback implementations:

- print_frame() — prints frame numbers.
- show_progress() — displays progress in percent.
- notify_special() — reacts only to even frames.
- Added edge-case handling (frames <= 0 or NULL callback → no output).
- Built and tested the project using make and validated correct runtime behavior

TBD
 
---
 
### Runtime Output

| Number |         Description      | Input/Range |    Callback Function  |        Output Example       |
|--------|--------------------------|-------------|-----------------------|-----------------------------|
|        |                          |             |                       |       frame 0; frame 1      |
|    1   |  Print frame numbers     | Frames = 5  | print_frame(int frame)|       frame 2; frame 3      |
|        |                          |             |                       |       frame 4; frame 5      |
|--------|--------------------------|-------------|-----------------------|-----------------------------|
|        |                          |             |                       |        Progress: 0%         |
|    2   | Show progress percentage | Frames = 10 |       show_progress   |        Progress: 10%        |
|        |                          |             |                       |             ...             |
|        |                          |             |                       |        Progress: 90%        |
|--------|--------------------------|-------------|-----------------------|-----------------------------|
|        |                          |             |                       |    Even frame 0 reached!    |
|    3   |  Notify only even frames | Frames = 6  |      notify_special   |    Even frame 2 reached!    |
|        |                          |             |                       |    Even frame 4 reached!    |
|--------|--------------------------|-------------|-----------------------|-----------------------------|
|    4   |        Edhe cases        | Frames = 0  |            ---        | (no output, handled safely) |
 
TBD
 
---
 
### Observations and Conclusion
 
- The callback mechanism allows one general function to perform many different behaviors depending on the callback passed to it.
- Function pointers in C are powerful for implementing customizable loops, event handlers, and modular algorithms.
- Checking input parameters (for NULL and non-positive values) prevents runtime errors.
- The program output correctly demonstrated multiple callbacks working with the same core logic.
- The concept is similar to event systems used in game development (e.g., onFrame() or onTick()).

Conclusion:
A callback is a user-defined function passed to another function to modify its behavior without changing its code.
This lab helped me understand how to use function pointers for flexible and reusable program design in C.
TBD
 
---