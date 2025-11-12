#ifndef USER_MACROS_H
#define USER_MACROS_H

#include <stdio.h>

/* A) MOD_SAFE(out, a, b): if b != 0 → out = a % b; else out = 0 */
#define MOD_SAFE(out, a, b) \
do { \
    if ((b) != 0) (out) = (a) % (b); \
    else (out) = 0; \
} while (0)

/* B) NONNEG(x): return max(x, 0) */
#define NONNEG(x) (((x) > 0) ? (x) : 0)

#endif /* USER_MACROS_H */
