# Lab 16 — Lab Work Dynamic Lists
 
---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina_Hryshko  
**Date:** 08 May, 2026  
 
---
## Description:

```
This project is a laboratory work focused on implementing dynamic singly linked lists in C language. The program simulates an application domain called "Lamps" and demonstrates dynamic memory allocation, linked list operations, file processing, sorting, filtering, and modular program design.

The program models different types of lamp, inclusing:
1. Base Lamp;
2. Smart Lamp;
3. Enternal Lamp

and provides operations on collections of these objects.

```

---
## Structure
 
```text
lab16/
├──Doxyfile/
├── Makefile/
├── README.md
├── doc/
|      └── lab16.md
├── test/
|      └── test.c
├── src/
|     └──entity.c
|     └──entity.h
|     └── list.c
|     └── list.h
|     └── menu.c
|     └── menu.h
|     └── main.c
```

## How to Build

```bash
make
./main
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
- Dynamic singly linked list.
- Adding lamps to the end of the list.
- Removing lamps by index.
- Displaying lamps in formatted table view.
- Sorting lamps by wattage.
- Finding burned-out lamps.
- Calculating total power consumption excluding burned lamps.
- Reading lamp data from a file using fscanf.
- Writing lamp data to a file using fprintf.
- Support for SMART lamp functionality.
- Interactive menu-driven interface.
- Unit testing.
- Memory leak checking with Valgrind.
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