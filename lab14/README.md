Lab 14 - Structured Data Types

**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** 02 May, 2026

## Description:

```
This project is a laboratory work focused on working with structured data types in C. The main goal is to simulate an application domain(Lamps) using structures, implement file processing, sorting, filtering and modular program design.

The program models different types of lamp, inclusing:
1. Base Lamp;
2. Smart Lamp;
3. Enternal Lamp

and provides operations on collections of these objects.

```

## Input Data

The input file (assets/input.txt) must contain: height, width and symbol.
For Example:
*1*
```
0 BASIC 1 Philips 5 10 3000 3 1
```
*2*
```
1 SMART 0 Osram 3 105 4000 2 2 1 STM32F103 #562d48
```
*3*
```
2 ETERNAL 1 Ikea 0 10 2700 1 0 
```
---
## Structure
 
```text
lab14/
├──Doxyfile/
├── Makefile/
├── README.md
├── assets/
|      └── input.txt
├── doc/
|      └── lab14.md
├── test/
|      └── test.c
├── src/
|     └── lib.c
|     └── lib.h
|     └── main.c
```

## How to Build

```bash
make
./dist/main.bin "./assets/input.txt" "./dist/output.txt"
make clean
```

## How to Test

```bash
make test
make clean
```

## Features:

The program implements:
- Reading an array of structures from a file.
- Writing an array of structures to a file.
- Displauing structures on screen.
- Finding burnt-out lamps.
- Calculating total watts consumption(excluding burn-out lamps).
- Selecting smart lamps.
- Sorting lamps by speified field.
- Simulated lamp behavior (turn on/burnout logic).
- Suppport for "Smart" and "Enternal" lamp types

## Notes
- All data is passed using pointers as required by the lab task.
- The program doesn't require interactive user input.
- Input data is read from "assets/input.txt"