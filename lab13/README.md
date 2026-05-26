Lab 13 - Working with files

**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** 11 April, 2026

## Description:

```
This project demonstrates working with files in C language. The program reads input data from a file, processes it and writes the result to another file.
The task is to build a solid isosceles triangle using a given symbol. The triangle parameters (height, width and symbol) are provided in the input file.
```

## Input Data

The input file (assets/input.txt) must contain: height, width and symbol.
For Example:
*1*
```
4 7 *
```
*2*
```
11 7 *
```
## Structure
 
```
lab13/
├──Doxyfile/
├── Makefile/
├── README.md
├── assets/
|      └── input.txt
├── test/
|      └── test.c
├── doc/
|      └── lab13.md
├── src/
|     └── lib.c
|     └── lib.h
|     └── main.c
```

## How to Run

```bash
./dist/main.bin
```

## How to Test

```bash
make test
./dist/test.bin
make clean
```

## Requirements:
- Use of (fscanf) and (fprintf) for file operations;
- Input/Output files passed as command-line arguments;
- No user input during execution;

## Notes
- The output file shouldn't be added to version control;
- Memory leaks must be checked (valgrind);
- Code documentation should be generated using Doxygen.