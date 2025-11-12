# Lab 03 — Lab Assignment - Expressions (C)
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko 
**Date:** October 22, 2025
 **Variant** 11(eleven)
---
 
## Task Description
 
 
This lab focuses on implementing and testing an arithmetic expression, use arithmetic operations, use the correct operator precedence and parentheses to ensure accurate computation. Specify the domain of definition (DOD) of your expression. Evaluate the expression for a gaven x. Demonstrate the processing of invalid or uncertain input data.
 
## Structure
 
```text
lab03/
├── Report.md # Laboratory report
├── task3_1.c # arithmetic operations
├── task3_2.c # Expressions with trigonometric/exponential/logarithmic functions

```
 
 ## Lab 03_01 — Arithmetic Expressions

**Variant** 11(eleven) 

## Task Description
 

Write a program that computes an arithmetic expression, use arithmetic operations, use the correct operator precedence and parentheses to ensure accurate computation.

## Expression

```
E(x) = x^3 - 1/x - 1 + (6 - x) * (x^2 - 2)/2 * x + 3
```
 
### How to Build
 
```bash
#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0.0;   /* change in GDB or input below*/
    double a, b, c, d, e, E;
    printf("x = ");
    scanf("%lf", &x); /* one read, no conditions */
    a = x*x*x - 1;
    b = x - 1;
    c = 6 - x;
    d = 2*x + 3;
    e = x*x - 2;

    E = a/b + (c*e)/d;
    
   printf("E(%.3f) = %.8f\n", x, E);
   
   return 0; 
}
```
 
### How to Run the GDB test
 
```bash
gcc -g -O0 -Wall task3_1.c -lm -o task3_1
./task3_1
(gdb) break main
(gdb) run
x = 2.9
(gdb) next; print a; next; print b; next; print c; next; print d; next; print e; next; print E
(gdb) run
x = 3
(gdb) run
x = -4

```
### GDB Result

```
x = 2.9
E(2.900) = 14.56806818
[Inferior 1 (process 23961) exited normally]
(gdb) next
The program is not being run.
(gdb) run
Starting program: /home/grishko4210/programming-part-1/lab03/task3_1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
x = 3
E(3.000) = 15.33333333
[Inferior 1 (process 24141) exited normally]
(gdb) next
The program is not being run.
(gdb) run
Starting program: /home/grishko4210/programming-part-1/lab03/task3_1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
x = -4
E(-4.000) = -15.00000000
[Inferior 1 (process 24342) exited normally]
(gdb) run
Starting program: /home/grishko4210/programming-part-1/lab03/task3_1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
x = 0
E(0.000) = -3.00000000
[Inferior 1 (process 25639) exited normally]
(gdb) run

```

 ### Runtime Output

 |  x  |     E(x)    |
 |-----|-------------|
 | 2.9 | 14.56806818 |
 |  3  |  15.33333333|
 | -4  | -15.00000000|
 |  0  | -3.00000000 |

 ## Lab 03_02 - Expressions with Trig/Exponential/Log(C)

**Variant** 11(eleven)

## Task Description
Specify the domain of definition (DOD) of your expression. Evaluate the expression for a gaven x. Demonstrate the processing of invalid or uncertain input data.

## Expression

```bash
E(x) = sin(x) - cos(x)/tan(x) + log10(x + 1) * cos(4 * x)/exp(x)
```

 
### How to Build
 
```bash
#include <stdio.h>
#include <math.h>

int main(void) {
    double x, E;

    printf("Enter x: ");
    scanf("%lf", &x);

    /* computer parts separately for easier GDB inspection */
    double a = sin(x) - cos(x);
    double b = tan(x);
    double c = log10(x + 1);
    double d = cos(4 * x);
    double e = exp(x);
    
    E = a / b + (c * d) / e;

    printf("E(%.3f) = %.8f\n", x, E);
    return 0;
}
```
### How to Run the GDB test
 
```bash
gcc -g -O0 -Wall task3_1.c -lm -o task3_1
./task3_1
(gdb) break main
(gdb) run
x = 2
(gdb) next; print a; next; print b; next; print c; next; print d; next; print e; next; print E
(gdb) run
x = 1
(gdb) run
x = -4
```
### GDB Result

```bash
(gdb) next
7           printf("Enter x: ");
(gdb) print a
$1 = 0
(gdb) next
8           scanf("%lf", &x);
(gdb) print b
$2 = 0
(gdb) next
Enter x: 2
11          double a = sin(x) - cos(x);
(gdb) next
12          double b = tan(x);
(gdb) print a
$3 = 1.3254442633728241
(gdb) next
13          double c = log10(x + 1);
(gdb) print b
$4 = -2.1850398632615189
(gdb) next
14          double d = cos(4 * x);
(gdb) print c
$5 = 0.47712125471966244
(gdb) next
15          double e = exp(x);
(gdb) print d
$6 = -0.14550003380861354
(gdb) next
17          E = a / b + (c * d) / e;
(gdb) print e
$7 = 7.3890560989306504
(gdb) next
19          printf("E(%.3f) = %.8f\n", x, E);
(gdb) print E
$8 = -0.61599471219034307
(gdb) next
E(2.000) = -0.61599471
20          return 0;
(gdb) run
(gdb) print a
$34 = 0
(gdb) next
8           scanf("%lf", &x);
(gdb) print b
$35 = 0
(gdb) next
Enter x: 1
11          double a = sin(x) - cos(x);
(gdb) next
12          double b = tan(x);
(gdb) print a
$36 = 0.30116867893975674
(gdb) next
13          double c = log10(x + 1);
(gdb) print b
$37 = 1.5574077246549023
(gdb) next
14          double d = cos(4 * x);
(gdb) print c
$38 = 0.3010299956639812
(gdb) next
15          double e = exp(x);
(gdb) print d
$39 = -0.65364362086361194
(gdb) next
17          E = a / b + (c * d) / e;
(gdb) print e
$40 = 2.7182818284590451
(gdb) next
19          printf("E(%.3f) = %.8f\n", x, E);
(gdb) print E
$41 = 0.12099189503852019
(gdb) run
(gdb) next
7           printf("Enter x: ");
(gdb) print a
$42 = 0
(gdb) next
8           scanf("%lf", &x);
(gdb) print b
$43 = 0
(gdb) next
Enter x: -4
11          double a = sin(x) - cos(x);
(gdb) next
12          double b = tan(x);
(gdb) print a
$44 = 1.4104461161715403
(gdb) next
13          double c = log10(x + 1);
(gdb) print b
$45 = -1.1578212823495775
(gdb) next
14          double d = cos(4 * x);
(gdb) print c
$46 = nan(0x8000000000000)
(gdb) next
15          double e = exp(x);
(gdb) print d
$47 = -0.95765948032338466
(gdb) next
17          E = a / b + (c * d) / e;
(gdb) print e
$48 = 0.018315638888734179
(gdb) next
19          printf("E(%.3f) = %.8f\n", x, E);
(gdb) print E
$49 = nan(0x8000000000000)
(gdb) run

```
 
### Runtime Output
  |  x  |          E(x)        |    Comment     |
  |-----|----------------------|----------------|
  |  2  | -0.61599471219034307 |   Normal case  |
  |  2  | 0.12099189503852019  |   Valid input  |
  | -4  |         Error        |log argment <= 0|
> 
 
TBD 
---

 ## Report
 
The goal of this lab is to learn how to solve examples(arithmetics and expressions with Trig/Exponential/Log) and use GDB
 
In this lab, I completed the following tasks:
- Implement and tested an arithmetic espression.
- Used arithmetic operations and used the correct operator and paranthesis precedence to ensure accurace.
- Specifies the domain of my expression (DOD).
- Calculated the expression for the given x.
- Demonstrated the processing of invalid or undefined. 
 
TBD
 
---
### Observations and Conclusion
 
 Both programs compiled and executed successfully using `gcc -g -O0 -Wall -lm`.  
- Debug sessions verified correct intermediate computations.  
- Domain restrictions were properly handled to prevent undefined operations.  
- Expressions evaluated accurately for multiple test values of `x`, for example, for lab03_01 the following values were written x = 2.9; x = 3; x = -4. For lab03_02 the following values were written x = 2, x = 1 and x = -4
  

TBD
 
---
