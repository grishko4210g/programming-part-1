#include <stdio.h>
#include "user_funcs.h"

int main(void)
{
    int a, b;
    int ok;
    int result;

    printf("Enter two integers (a b): ");
    scanf("%d %d", &a, &b);

    // Test safe division
    result = div_safe(a, b, &ok);
    if (ok)
        printf("div_safe(%d, %d) = %d\n", a, b, result);
    else
        printf("div_safe: division by zero!\n");

    // Test safe modulo
    result = mod_safe(a, b, &ok);
    if (ok)
        printf("mod_safe(%d, %d) = %d\n", a, b, result);
    else
        printf("mod_safe: modulo by zero!\n");

    return 0;
}
