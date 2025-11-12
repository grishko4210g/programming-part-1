#include <stdio.h>
#include "include/user_macros.h"

int main(void) {
    int a, b, result;

    printf("Enter two integers (a b): ");
    scanf("%d %d", &a, &b);

    /* Demonstrate MOD_SAFE */
    MOD_SAFE(result, a, b);
    printf("MOD_SAFE(%d, %d) = %d\n", a, b, result);

    /* Demonstrate NONNEG */
    int neg = -5, pos = 7;
    printf("NONNEG(%d) = %d\n", neg, NONNEG(neg));
    printf("NONNEG(%d) = %d\n", pos, NONNEG(pos));

    return 0;
}
