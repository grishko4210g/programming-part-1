# Lab 05_01 — Series Sums and Products Report
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko  
**Date:** Semtember 25, 2025  
 **Variant:** 11(eleven)
---
 
## Task Description

 Formula: S = Σ (n=1 to k) [ x^(2n+1) / (2n+1) ]

**The first part** Integer - based arithmetic using "int__128" to hadle large powers of x and "unsigned long long" for the sum.

**The second part** Floating - point arithmetic using "double" to avoid overflow and simplify calculation.

The program must handle input validation and detect potential overflows in the integer - based implementation.
 
 
## Lab Instructions
 
- Input k (number of terms) and x (base).
- Compute the sum using integer arithmetic with overflow checks.
- Compute the sum using floating-point arithmetic.
- Compare results and observe differences.
- Print the final sum for both methods.

Requirements:
- Validate user input.
- Detect integer overflow.
- Optionally, print intermediate values for debugging


### The first part:

### How to Build
 
```bash
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

int main(void) {
    unsigned long long k = 0;
    long long x = 0;

    printf("Enter k and x separated by space: ");
    if (scanf("%llu %lld", &k, &x) != 2) {
        puts("Input error");
        return 1;
    }


    printf("DEBUG: k = %llu, x = %lld\n", k, x);

    unsigned long long S = 0;         
    __int128 xpow = (__int128)x * x * x;

    for (unsigned long long n = 1; n <= k; ++n) {
        unsigned long long denom = 2 * n + 1;

        if (denom == 0) {
            puts("NaN");
            return 2;
        }

        __int128 tmp = xpow / denom;

        if (tmp < 0 || (__int128)S + tmp > (__int128)ULLONG_MAX) {
            puts("OVERFLOW");
            return 3;
        }
        
        S += (unsigned long long)tmp;
        xpow *= x;
        printf("DEBUG n=%llu, denom=%llu, tmp=%llu, S=%llu, xpow=%llu\n",
               n, denom, (unsigned long long)tmp, S, (unsigned long long)xpow);
    }

    printf("Final sum S = %llu\n", S);
    return 0;
}
```
 
  ### How to Run the GDB test
  
  ```bash
./series_11_int
(gdb) break main
(gdb) run
(gdb) next
(gdb) print k
(gdb) next

```
  ### GDB Result
  ```bash
Breakpoint 1, main () at series_11_int.c:7
7           unsigned long long k = 0;
(gdb) next
12              puts("Input error");
(gdb) next
3 4
17          printf("DEBUG: k = %llu, x = %lld\n", k, x);
(gdb) print k
$18 = 3
(gdb) print x
$19 = 4
(gdb) next
18
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$20 = 64
(gdb) next
21
(gdb) next
23              unsigned long long denom = 2 * n + 1;
(gdb) print denom
$21 = 3
(gdb) next
28              }
(gdb) next
30              __int128 tmp = xpow / denom;
(gdb) print tmp
$22 = 21
(gdb) next
35              }
(gdb) next
36
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$23 = 256
(gdb) next
21
(gdb) next
23              unsigned long long denom = 2 * n + 1;
(gdb) print denom
$24 = 5
(gdb) print S
$25 = 21
(gdb) next
28              }
(gdb) next
30              __int128 tmp = xpow / denom;
(gdb) print tmp
$26 = 51
(gdb) next
35              }
(gdb) next
36
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$27 = 1024
(gdb) next
21
(gdb) next
23              unsigned long long denom = 2 * n + 1;
(gdb) print denom
$28 = 7
(gdb) next
28              }
(gdb) next
30              __int128 tmp = xpow / denom;
(gdb) print tmp
$29 = 146
(gdb) next
35              }
(gdb) next
36
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$30 = 4096
(gdb) next
38
(gdb) print S
$31 = 218
(gdb) next
218
39              // Підготовка x^(n+3) для наступного кроку
(gdb) next
40              xpow *= x;
(gdb) print xpow
$32 = 4096
(gdb) next
Download failed: Invalid argument.  Continuing without source file ./csu/../sysdeps/nptl/libc_start_call_main.h.
__libc_start_call_main (main=main@entry=0x5555555551a9 <main>, argc=argc@entry=1, argv=argv@entry=0x7fffffffdd68)
    at ../sysdeps/nptl/libc_start_call_main.h:74
warning: 74     ../sysdeps/nptl/libc_start_call_main.h: No such file or directory
(gdb) continue
Continuing.
[Inferior 1 (process 138942) exited normally]
(gdb) run
Breakpoint 1, main () at series_11_int.c:7
7           unsigned long long k = 0;
(gdb) next
12              puts("Input error");
(gdb) next
4
7
17          printf("DEBUG: k = %llu, x = %lld\n", k, x);
(gdb) print k
$33 = 4
(gdb) print x
$34 = 7
(gdb) next
18
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$35 = 343
(gdb) next
21
(gdb) next
23              unsigned long long denom = 2 * n + 1;
(gdb) denom
Undefined command: "denom".  Try "help".
(gdb) print denom
$36 = 3
(gdb) next
28              }
(gdb) next
30              __int128 tmp = xpow / denom;
(gdb) print tmp
$37 = 114
(gdb) next
35              }
(gdb) next
36
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$38 = 2401
(gdb) next
21
(gdb) next
23              unsigned long long denom = 2 * n + 1;
(gdb) print denom
$39 = 5
(gdb) next
28              }
(gdb) next
30              __int128 tmp = xpow / denom;
(gdb) print tmp
$40 = 480
(gdb) next
35              }
(gdb) next
36
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$41 = 16807
(gdb) next
21
(gdb) print S
$42 = 594
(gdb) next
23              unsigned long long denom = 2 * n + 1;
(gdb) print denom
$43 = 7
(gdb) next
28              }
(gdb) next
30              __int128 tmp = xpow / denom;
(gdb) print tmp
$44 = 2401
(gdb) next
35              }
(gdb) next
36
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$45 = 117649
(gdb) next
21
(gdb) next
23              unsigned long long denom = 2 * n + 1;
(gdb) print denom
$46 = 9
(gdb) next
28              }
(gdb) next
30              __int128 tmp = xpow / denom;
(gdb) print tmp
$47 = 13072
(gdb) next
35              }
(gdb) next
36
(gdb) next
20          __int128 xpow = (__int128)x * x * x; /* x^3 */
(gdb) print xpow
$48 = 823543
(gdb) print S
$49 = 16067
(gdb) next
38
(gdb) continue
Continuing.
16067
[Inferior 1 (process 140545) exited normally]
(gdb)
```
### Runtime Output 
K=4; x=7
 
 | n | denom |  tmp  |  xpow  |   S   |
 |---|-------|-------|--------|-------|
 | 1 |   3   |  114  |  343   |  114  |
 | 2 |   5   |  480  |  2401  |  594  |
 | 3 |   7   |  2401 | 16807  | 2995  |
 | 4 |   9   | 13072 | 117649 | 16067 |


TBD
 
---

### The second part:

### How to Build

```bash
#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void) {
    int k;
    double x;

    if (scanf("%d %lf", &k, &x) != 2 || k <= 0) {
        puts("Input error");
        return 1;
    }

    double T = 0.0;
    double xpow = x * x * x;
    int n = 1;

    while (n <= k) {
        double denom = 2.0 * n + 1.0;
        double term = xpow / denom;
        T += term;

       
        xpow *= x;
        ++n; 
    }

    printf("%.10g\n", T);

    return 0;
}

```
### How to Run the GDB test
  
  ```bash
./series_11_fp
(gdb) break main
(gdb) run
(gdb) next
(gdb) print k
(gdb) next
(gdb) print x
(gdb) next
(gdb) print n
(gdb) next
(gdb) print xpow
(gdb) next
(gdb) print T
(gdb) continue
```

 ### GDB Result

 ```bash
Breakpoint 1, main () at series_11_fp.c:5
5       int main(void) {
(gdb) next
9           if (scanf("%d %lf", &k, &x) != 2 || k <= 0) {
(gdb) next
4
6
14          double T = 0.0;
(gdb) next
15          double xpow = x * x * x;
(gdb) print k
$47 = 4
(gdb) print x
$48 = 6
(gdb) print xpow
$49 = 0
(gdb) print x
$50 = 6
(gdb) next
16          int n = 1;
(gdb) next
18          while (n <= k) {
(gdb) next
19              double denom = 2.0 * n + 1.0;
(gdb) next
20              double term = xpow / denom;
(gdb) next
21              T += term;
(gdb) next
24              xpow *= x;
(gdb) next
25              ++n; 
(gdb) print n
$51 = 1
(gdb) next
18          while (n <= k) {
(gdb) next
19              double denom = 2.0 * n + 1.0;
(gdb) print denom
$52 = 3
(gdb) next
20              double term = xpow / denom;
(gdb) print term
$53 = 72
(gdb) next
21              T += term;
(gdb) print T
$54 = 72
(gdb) next
24              xpow *= x;
(gdb) print xpow
$55 = 1296
(gdb) next
25              ++n; 
(gdb) print n
$56 = 2
(gdb) next
18          while (n <= k) {
(gdb) next
19              double denom = 2.0 * n + 1.0;
(gdb) print denom
$57 = 5
(gdb) next
20              double term = xpow / denom;
(gdb) print term
$58 = 259.19999999999999
(gdb) next
21              T += term;
(gdb) print T
$59 = 331.19999999999999
(gdb) next
24              xpow *= x;
(gdb) print xpow
$60 = 7776
(gdb) next
25              ++n; 
(gdb) print n
$61 = 3
(gdb) next
18          while (n <= k) {
(gdb) next
19              double denom = 2.0 * n + 1.0;
(gdb) print denom
$62 = 7
(gdb) next
20              double term = xpow / denom;
(gdb) print term
$63 = 1110.8571428571429
(gdb) next
21              T += term;
(gdb) print T
$64 = 1442.0571428571429
(gdb) next
24              xpow *= x;
(gdb) print xpow
$65 = 46656
(gdb) next
25              ++n; 
(gdb) print n
$66 = 4
(gdb) next
18          while (n <= k) {
(gdb) next
28          printf("%.10g\n", T);
(gdb) print T
$67 = 6626.0571428571429
(gdb) print xpow
$68 = 279936
(gdb) print k
$69 = 4
(gdb) print x
$70 = 6
(gdb) print denom
No symbol "denom" in current context.
(gdb) continue
Continuing.
6626.057143
[Inferior 1 (process 150222) exited normally]
(gdb) run

 ```
### Runtime Output 
K=4; x=6

 | n | denom |     tmp    |  xpow  |      T     |
 |---|-------|------------|--------|------------|
 | 1 |   3   |      72    |  216   |      72    |
 | 2 |   5   |     259.2  |  1296  |     331.2  |
 | 3 |   7   | 1110.857143|  7776  | 1442.057143|
 | 4 |   9   |     5184   |  46656 | 6626.057143|


## Report
 
In this lab, I completed the following tasks:
- Implemented the series sum using integer arithmetic, handling large powers of x and detecting overflow.
- Implemented the series sum using floating-point arithmetic to simplify calculations and avoid overflow.
- Verified intermediate values (xpow, denom, tmp, S, T) using GDB to ensure correctness of each iteration.
- Compared results of integer and floating-point calculations and observed differences.
- Tested the program with different input value for k and x, ensuring correct final sums.


TBD
 
---
 
### Observations and Conclusion
 
- The program correctly computes the series dum for both integer and floating - point implementations.
- Integer arithmetic works for small K and x, while floating - point arithmetic handles larges larger values without overflow.
- Debugging confirmed that intermediate value (xpow, denom, tmp, S, T) match theoretical calculations.
- The final sums match the expected results for all tested input.
- Using GDB allowed step-by-step verification of calculations and ensured correctness at each iteration.
- The lab task was successfully completed: both integer and floating-point approaches were implemented, validated and compared.
 
TBD
 
---