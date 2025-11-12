# Lab 04 — Conditions Report Template 
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** October 23, 2025

**Variant:** 11(eleven) 
 
---
 
## Task Description


This lab focuses on implementing and calculating values for the corresponding option using conditional expressions, reading input variables, and calculating the result. As for selection operators, the implementation of a program that selects and performs operations based on a discrete variable (integer or character). Point in a region, determine whether the point (x, y) is inside or outside a given region.  
 
## Structure
 
```text
lab04/
├── task4_1.c         # Conditional Operators (if / else)
├── task4_2.c       # Selection Statements (switch / case)
├── region_03.c           # Point in Region 
├── Report.md         # Observations and conclusions.

```
 ## Lab 04_01 - Conditional Operators (if / else)
**Variant:** 11(eleven)
 
## Problem conditions
 ```
 Brick-through-hole: given brick edges a, b, c and a rectangular hole x, y; determine if the brick can pass with edges parallel/perpendicular to the hole sides (test all faces).
 ```
### How to Build
 
 
```bash
#include <stdio.h>

int main(void) {
    double a, b, c, x, y;

    printf("Enter brick dimensions (a b c): ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        puts("Invalid brick input");
        return 1;
    }

    printf("Enter hole dimensions (x y): ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        puts("Invalid hole value");
        return 2;
    }

    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        puts("All dimensions must be positive");
        return 3;
    }

    if ((a <= x && b <= y) || (a <= y && b <= x) ||
        (a <= x && c <= y) || (a <= y && c <= x) ||
        (b <= x && c <= y) || (b <= y && c <= x)) {
        puts("Brick  fits");
    } else {
        puts("Doesn't fit");
    }

    return 0;
}
```
 
### How to Run Tests

 
```bash
gcc -g -O0 -Wall -lm task4_1.c -o task4_1
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./task4_1
Enter brick dimensions (a b c): 3 4 5
Enter hole dimensions (x y): 5 6
Brick  fits
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./task4_1
Enter brick dimensions (a b c): 2 5 7
Enter hole dimensions (x y): 2 3
Doesn't fit
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./task4_1
Enter brick dimensions (a b c): 7 4 9
Enter hole dimensions (x y): 9 8
Brick  fits
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$

```
 
 ### How to Run the GDB test
 
 ```bash
gcc -g -O0 -Wall -lm task4_1.c -o task4_1
./task4_1
(gdb) break main
(gdb) run
(gdb) print x, y
 ```

### GDB Result

```bash
(gdb) next
6           printf("Enter brick dimensions (a b c): ");
(gdb) next
7           if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
(gdb) next
Enter brick dimensions (a b c): 5 7 8
12          printf("Enter hole dimensions (x y): ");
(gdb) print x, y
$15 = 6.9533558073939025e-310
(gdb) next
13          if (scanf("%lf %lf", &x, &y) != 2) {
(gdb) next
Enter hole dimensions (x y): 7 8
18          if (a <= 0  b <= 0  c <= 0  x <= 0  y <= 0) {
(gdb) print 
$16 = 6.9533558073939025e-310
(gdb) next
23          if ((a <= x && b <= y)  (a <= y && b <= x) 
(gdb) next
26              puts("Brick  fits");
(gdb) next
Brick  fits
31          return 0;
(gdb) run
(gdb) next
6           printf("Enter brick dimensions (a b c): ");
(gdb) next
7           if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
(gdb) next
Enter brick dimensions (a b c): 3 8 9
12          printf("Enter hole dimensions (x y): ");
(gdb) next
13          if (scanf("%lf %lf", &x, &y) != 2) {
(gdb) print
$18 = 6.9533558073939025e-310
(gdb) next
Enter hole dimensions (x y): 7 8
18          if (a <= 0  b <= 0  c <= 0  x <= 0  y <= 0) {
(gdb) print
$19 = 6.9533558073939025e-310
(gdb) next
23          if ((a <= x && b <= y)  (a <= y && b <= x) 
(gdb) next
26              puts("Brick  fits");
(gdb) next
Brick  fits
31          return 0;
(gdb) run
(gdb) next
6           printf("Enter brick dimensions (a b c): ");
(gdb) print
$23 = 6.9533558073939025e-310
(gdb) next
7           if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
(gdb) next
Enter brick dimensions (a b c): 2 5 7
12          printf("Enter hole dimensions (x y): ");
(gdb) next
13          if (scanf("%lf %lf", &x, &y) != 2) {
(gdb) print
$24 = 6.9533558073939025e-310
(gdb) next
Enter hole dimensions (x y): 2 3
18          if (a <= 0  b <= 0  c <= 0  x <= 0  y <= 0) {
(gdb) next
23          if ((a <= x && b <= y)  (a <= y && b <= x) 
(gdb) print
$25 = 6.9533558073939025e-310
(gdb) next
24              (a <= x && c <= y)  (a <= y && c <= x) 
(gdb) next
23          if ((a <= x && b <= y)  (a <= y && b <= x) 
(gdb) next
24              (a <= x && c <= y)  (a <= y && c <= x) 
(gdb) next
25              (b <= x && c <= y) || (b <= y && c <= x)) {
(gdb) next
24              (a <= x && c <= y)  (a <= y && c <= x) 
(gdb) next
28              puts("Doesn't fit");
(gdb) next
Doesn't fit
31          return 0;
(gdb)
```

 ### Runtime Output

 | a, b, c | x, y  |   Result    |
 |---------|-------|-------------|
 | 5, 7, 8 |  7, 8 | Brick  fits |
 | 3, 8, 9 |  7, 8 | Brick  fits |
 | 2, 5, 7 |  2, 3 | Doesn't fit |

 
## Lab 04_02 - Selection Statemens (switch / case)
**Variant:** 11(eleven)

## Problem conditions

 ```
 Log level: 0-ERROR, 1-WARN, 2-INFO, 3-DEBUG
 ```
### How to Build
 
 
```bash
#include <stdio.h>

int main(void) {
    int level;
    printf("Enter level number (0-3): ");
    if (scanf("%d", &level) != 1) {
        puts("Invalid input");
        return 1;
}
switch (level) {
    case 0: puts("ERROR");
    break;
    case 1: puts("WARN");
    break;
    case 2: puts("INFO");
    break;
    case 3: puts("DEBUG");
    break;
    default:
    puts("Invalid level");

return 2;
}
return 0;
}
```
### How to Run Tests

```bash
gcc -g -O0 -Wall -lm task4_1.c -o task4_1
./task4_2
Enter level number (0-3): 2
INFO
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./task4_2
Enter level number (0-3): 5
Invalid level
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./task4_2
Enter level number (0-3): 1
WARN
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./task4_2
Enter level number (0-3): 3
DEBUG
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./task4_2
Enter level number (0-3): 0
ERROR
```
 ### How to Run the GDB test
 
 ```bash
gcc -g -O0 -Wall -lm task4_2.c -o task4_2
./task4_2
(gdb) break main
(gdb) run
Enter level number (0-3): 2
(gdb) print level
(gdb) next
(gdb) run #restart and test invalid case
```

### GDB Result

```bash
next
Enter level number (0-3): 0
10      switch (level) {
(gdb) next
11          case 0: puts("ERROR");
(gdb) print level
$4 = 0
(gdb) next
ERROR
12          break;
(gdb) run
(gdb) next
Enter level number (0-3): 1
10      switch (level) {
(gdb) print level
$2 = 1
(gdb) next
13          case 1: puts("WARN");
(gdb) next
WARN
14          break;
(gdb) run
(gdb) next
Enter level number (0-3): 3
10      switch (level) {
(gdb) next
17          case 3: puts("DEBUG");
(gdb) print level
$6 = 3
(gdb) next
DEBUG
18          break;
(gdb) run
(gdb) next
Enter level number (0-3): 2
10      switch (level) {
(gdb) next
15          case 2: puts("INFO");
(gdb) print level
$5 = 2
(gdb) next
INFO
16          break;
(gdb) run
(gdb) next
Enter level number (0-3): 5
10      switch (level) {
(gdb) print level
$3 = 5
(gdb) next
20          puts("Invalid level");
(gdb)next
Invalid level
18          break;
(gdb) run
```
### Runtime Output

 | Level number |    Result    |
 |--------------|--------------|
 |      0       |    ERROR     |
 |      1       |     WARN     |
 |      3       |    DEBUG     |
 |      2       |     INFO     |
 |      5       |Invalid level |

## Lab 04_03 - Point in Region
**Variant:** 11(eleven)

### How to Build
 
 
```bash
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    const double EPS = 1e-9;

    double x, y;
    if(scanf("%lf %lf", &x, &y) != 2) {
        puts("Input error");
        return 1;
    }
double y1 = x*x - 0.5;
double y2 = 1.0 - fabs(x);

bool inside = (y >= y1 - EPS) && (y <= y2 + EPS);

if (inside) {
    puts("YES");
} else {
    puts("NO");
}

return 0;

}
```
### How to Run Tests

 
```bash
gcc -Wall -Wextra -O0 -g region_03.c -lm -o region_03
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./region_03
3 4
NO
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ 2 1
2: command not found
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./region_03
0.5 0.2
YES
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./region_03
4 5
NO
grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./region_03
0.1 0.4
YES                                                                                                   grishko4210@DESKTOP-VOL6J04:~/programming-part-1/lab04$ ./region_03
1.2 0
NO
```
### How to Run the GDB test
 
 ```bash
 gdb .region_03
 (gdb) break main
 (gdb) run
 (gdb) print x
 (gdb) print y
 (gdb) run
 ```
 ### GDB Result

```bash
(gdb) next
6           const double EPS = 1e-9;
(gdb) next
9           if(scanf("%lf %lf", &x, &y) != 2) {
(gdb) next
0.2 0.4
13      double y1 = x*x - 0.5;
(gdb) next
14      double y2 = 1.0 - fabs(x);
(gdb) next
16      bool inside = (y >= y1 - EPS) && (y <= y2 + EPS);
(gdb) print x
$9 = 0.20000000000000001
(gdb) print y
$10 = 0.40000000000000002
(gdb) next
18      if (inside) {
(gdb) print inside
$11 = true
(gdb) next
19          puts("YES");
(gdb) next
YES
24      return 0;
(gdb) run 
(gdb) next
1 0.5
13      double y1 = x*x - 0.5;
(gdb) next
14      double y2 = 1.0 - fabs(x);
(gdb) next
16      bool inside = (y >= y1 - EPS) && (y <= y2 + EPS);
(gdb) next
18      if (inside) {
(gdb) next
21          puts("NO");
(gdb) next
NO
24      return 0;
(gdb) run
(gdb) next
6           const double EPS = 1e-9;
(gdb) next
9           if(scanf("%lf %lf", &x, &y) != 2) {
(gdb) next
1.2 0.2
13      double y1 = x*x - 0.5;
(gdb) next
14      double y2 = 1.0 - fabs(x);
(gdb) next
16      bool inside = (y >= y1 - EPS) && (y <= y2 + EPS);
(gdb) next
18      if (inside) {
(gdb) next
21          puts("NO");
(gdb) next
NO
24      return 0;
(gdb) run
(gdb) next
0.5 0.2
13      double y1 = x*x - 0.5;
(gdb) next
14      double y2 = 1.0 - fabs(x);
(gdb) next
16      bool inside = (y >= y1 - EPS) && (y <= y2 + EPS);
(gdb) next
18      if (inside) {
(gdb) next
19          puts("YES");
(gdb) next
YES
24      return 0;
(gdb) run
```
### Runtime Output

 |  Points  |  Result(inside or Not?)  |
 |----------|--------------------------|
 | 0.2; 0.4 |            YES           |
 |  1; 0.5  |            NO            |
 | 1.2; 0.2 |            NO            |
 | 0.5; 0.2 |            YES           |

 
## Report
 
The goal of this lab is to pratice using conditional operators (if / else) and selection statements (switch / case), as well as to apply logical conditions to determine whether a point lies inside a defined geometric region.
 
In this lab, I completed the following tasks:
- Implemented a program that checks whether a brick can fit through a rectangular hole using conditional statements.
- Created a program that prints a log level message based on user input using the switch selection operator.
- Developed and tested a program that determines whether a point(x, y) lies inside or outside a region defined by given equations.
- Used GDB to debug all programs, observe variable values and confirm the correctness of logical expressions and conditions.
 
TBD
 
---
 
### Observations and Conclusion
 
During this lab work, I learned how to:
- Use conditional statements (if, else) to implement decision logic in programs.
- Apply switch, case constructs for handling discrete variable selections.
- Work with floating-point comparisons using a small constant (EPS) to account for numerical precision.
- Use the GDB debugger to step through program execution, analyze variable states and verify correctness.
- Properly compine and test programs with the GCC compiler using options -wall, -Wextra and -lm
So, this lab improved my understanding of control flow, debugging and logical reasoning in C programming. Each task was successfully tested and produced the expected results.
 
TBD
 
---