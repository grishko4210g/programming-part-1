# Lab 05_02 — Lab Work Point in Region Report
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko 
**Date:** October 25, 2025
 **Variant:** 11(eleven)
---
 
## Task Description
 
Formula: y=tan(п+х/4)/(п-x/4)^3
 
This lab focuses on implementing the goal of this work is to tabulae a mathematical function over a given interval and practice using loops, arithmetic operations.
 
## Lab Instructions
 
Use the following commands to build, test, and analyze the project.
The lab task was to tabulate the function:

```bash
y=tan(п+х/4)/(п-x/4)^3

x є [ 0; 3 ]
```

The goals were to:
- Compute function values programmatically.
- Divide an interval into n equally spaced points.
- Output results in a clear, formatted table.
 
### How to Build
 
```bash
#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0.0, b = 3.0;  // відрізок [0, 3]
    int n;

    // Ввід кількості точок
    if (scanf("%d", &n) != 1 || n <= 0) {
        puts("Invalid n");
        return 1;
    }

    double step = (b - a) / (n - 1);  // крок між точками
    int i = 0;
    double x, y;

    do {
        x = a + i * step;
        // Обчислення функції y = tan(pi + x/4) / (pi - x/4)^3
        y = tan(M_PI + x / 4.0) / pow(M_PI - x / 4.0, 3);
        printf("%10.5f %12.5f\n", x, y);
        i++;
    } while (i < n);

    return 0;
}

```
 
### How to Run Tests
 
```bash
gcc -Wall -Wextra -O2 tab_11.c -lm -o tab_11
echo 7 | ./tab_11

```
 ## Test results
    echo 7  | ./tab_11 
|      X     |     Y    |
|------------|----------|
|   0.00000  | -0.00000 |
|   0.50000  |  0.00458 |
|   1.00000  |  0.01056 |
|   1.50000  |  0.01859 |
|   2.00000  |  0.02964 |
|   2.50000  |  0.04527 |
|   3.00000  |  0.06810 |
 
 ### How to Run the GDB test

  ```bash
gcc -Wall -Wextra -O2 tab_11.c -lm -o tab_11
gdb ./tab_11
(gdb) break main
(gdb) run
```
 ### GDB Result

 ```bash
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
3
   0.00000     -0.00000
   1.50000      0.01859
   3.00000      0.06810
[Inferior 1 (process 182370) exited normally]
(gdb) continue
The program is not being run.
(gdb) run
Starting program: /home/grishko4210/programming-part-1/lab05/tab_11 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
5
   0.00000     -0.00000
   0.75000      0.00736
   1.50000      0.01859
   2.25000      0.03675
   3.00000      0.06810
[Inferior 1 (process 182491) exited normally]
(gdb) run
Starting program: /home/grishko4210/programming-part-1/lab05/tab_11 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
7
   0.00000     -0.00000
   0.50000      0.00458
   1.00000      0.01056
   1.50000      0.01859
   2.00000      0.02964
   2.50000      0.04527
   3.00000      0.06810
[Inferior 1 (process 182587) exited normally]
(gdb) run

 ```

### Runtime Output
 
|      X     |     Y    |
|------------|----------|
|   0.00000  | -0.00000 |
|   0.50000  |  0.00458 |
|   1.00000  |  0.01056 |
|   1.50000  |  0.01859 |
|   2.00000  |  0.02964 |
|   2.50000  |  0.04527 |
|   3.00000  |  0.06810 |

## Report
 
The goal of this lab is to tabulae a mathematical function over a given interval and practice using loops, arithmetic operations and formatted output in C.

In this lab, I completed the following tasks:
- Implemented a program to evaluate a given expression
- Used a "do while" loop to iterate through the points.
- Printed the results in a clear and formatted table.

TBD
 
---
 

### Observations and Conclusion
 
- The interval [0,3] was successfully divided into equals steps according to the specified number of points.
- Function values increase smoothly as x grows.
- The program correctly calculates y(x) using both trigonometric and fractional - power operations.
- Formatted output ensures the table is readable and aligned.
- Input validation prevents errors with invalid n.

So, the lab task was successfully completed. The program demonstrates correct tabulation of the this function and the approach can be adapted for other functions and intervals. This lab reinforced skills in loops arithmetic calculations and formatted output in C

TBD
 
---