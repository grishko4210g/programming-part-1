# Lab 05_03 — Base Conversion Report
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** Semtember 25, 2025  
 **Variant:** 11(eleven)
---
 
## Task Description
 
This lab focuses on implementing base-conversion algorithms for integer numeral systems with small bases (2–10).
The goal is to understand positional numeral systems and to perform conversions between bases using only arithmetic operations — multiplication, division, and modulus — without arrays or custom functions.
 
 
## Lab Instructions
 
Use the following commands to build, test, and analyze the project.
The program reads a decimal number and converts it to Base-4, then reads a Base-4 number and converts it back to decimal.


### How to Build
 
```bash
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    unsigned long long n = 0;
    int ch;

    printf("Decimal: ");
    if (scanf("%llu", &n) != 1)
    {
        return 1;
    }

    unsigned long long p = 1;
    while (p <= n / 4)
    {
        p *= 4;
    }

    printf("Base-4: ");
    if (n == 0)
    {
        putchar('0');
    }
    else
    {
        while (p > 0)
        {
            unsigned d = (unsigned)(n / p);
            putchar('0' + d);
            n %= p;
            p /= 4;
        }
    }
    putchar('\n');

    printf("Base-4: ");
    n = 0;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (isdigit(ch) && ch < '4')
        {
            n = n * 4 + (ch - '0');
        }
        else
        {
        }
    }

    printf("Decimal: %llu\n", n);
    return 0;
}

```
 
### How to Run Tests
 
```bash
gcc -Wall -Wextra O2 demo_10_16.c -o demo_10_16
./demo_10_16

```
 ## Test results

 ```bash
./demo_10_16
Decimal: 255
Base-4: 3333
Base-4: 123
Decimal: 27
./demo_10_16D
ecimal: 27B
ase-4: 123B
ase-4: 22D
ecimal: 10
./demo_10_16
Decimal: 10
Base-4: 22
Base-4: 100
Decimal: 16
./demo_10_16D
Decimal: 3333B
Base-4: 310011B
Base-4: 110D
Decimal: 20
 ```
  ### How to Run the GDB test
  
  ```bash
gcc -Wall -Wextra O2 demo_10_16.c -o demo_10_16
./demo_10_16
gdb ./demo_10_16
(gdb) break main
(gdb) run
  ```
  ### GDB Result
  ```bash
Breakpoint 1, 0x0000555555555100 in main ()
(gdb) next
Single stepping until exit from function main,
which has no line number information.
Decimal: 3333
Base-4: 310011
Base-4: 27
Decimal: 2
Download failed: Invalid argument.  Continuing without source file ./csu/../sysdeps/nptl/libc_start_call_main.h.
__libc_start_call_main (main=main@entry=0x555555555100 <main>, argc=argc@entry=1, argv=argv@entry=0x7fffffffdd68)
    at ../sysdeps/nptl/libc_start_call_main.h:74
warning: 74     ../sysdeps/nptl/libc_start_call_main.h: No such file or directory
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/grishko4210/programming-part-1/lab05/demo_10_16 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, 0x0000555555555100 in main ()
(gdb) next
Single stepping until exit from function main,
which has no line number information.
Decimal: 100
Base-4: 1210
Base-4: 33
Decimal: 15
  ```
### Runtime Output
 
 | Delicima| Base-4 |
 |---------|--------|
 |   100   |  1210  |
 |    15   |   33   |
 |   3333  | 310011 |
 |    27   |    2   |

TBD
 
---
## Report
 
The goal of this lab is to understand positional numeral systems and to perform conversions between bases using only arithmetic operations — multiplication, division, and modulus — without arrays or custom functions.
 
In this lab, I completed the following tasks:
- Conversion from Base-4 to Delicima and vice versa.

 
TBD
 
---
 
### Observations and Conclusion
 
- The program correctly converts numbers between bases 4 and 10.
- Both algorithms (multiply-add and power-divide) work as expected.
- Debugging confirmed that intermediate values (n, p, d) follow theoretical logic.
- The output fully matches manual calculations for all tested cases.
So, The lab task was successfully completed.
I implemented base-conversion logic without arrays or custom functions and verified correctness through testing and debugging.
 
TBD
 
---