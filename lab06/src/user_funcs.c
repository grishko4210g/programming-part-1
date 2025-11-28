#include "user_funcs.h"

// Safe integer division
int div_safe(int a, int b, int *ok)
{
    if (b == 0) {
        *ok = 0;
        return 0;
    }
    *ok = 1;
    return a / b;
}
int mod_safe(int a, int b, int *ok)
{
    if (b == 0) {
        *ok = 0;
        return 0;
    }
    *ok = 1;
    return a % b;
}
