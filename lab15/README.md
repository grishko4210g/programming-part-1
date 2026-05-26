# Lab 15 — Lab Work Dynamic Array
 
---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko 
**Date:** 06 May, 2026 
 
---

## Description:

This project is a laboratory work focused on implementing dynamic arrays in the C programming language.

The program simulates an application domain called *"Lamps"* and demonstrates:
- Dynamic memory allocation;
- Array operations;
- Sorting and filtering;
- Modular program design;
- Unit testing;
- Memory leak checking.

The program models different types of lamps:
1. Base Lamp;
2. Smart Lamp;
3. Everlasting Lamp.


---
## Structure
 
```text
lab15/
├──Doxyfile/
├── Makefile/
├── README.md
├── doc/
|      └── lab15.md
├── test/
|      └── test.c
├── src/
|     └──entity.c
|     └──entity.h
|     └── list.c
|     └── list.h
|     └── main.c
```

## How to Build

```bash
make
./app
make clean
```

## How to Run Test

```bash
make test
./test_bin
make clean
```

## Features:

The program implements:
- Dynamic array of structures;
- Adding lamps to the array;
- Removing lamps by index;
- Displaying lamps in formatted table view;
- Sorting lamps by watt consumption;
- Finding burned-out lamps;
- Calculating total power consumption excluding burned-out lamps;
- Support for smart lamp functionality;
- Pointer dereferencing instead of array indexing;
- Unit testing;
- Memory leak checking with Valgrind;
- Doxygen documentation support.
## Notes
### *BASIC LAMP*

Standard lamp with limited switch count.

### *SMART LAMP*

Lamp with additional smart functionality:
  - Wireless;
  - MCU support:
    - ESP8266
    - STM32F103
  - HEX color

### *ETERNAL Lamp*

Lamp that never burns out.