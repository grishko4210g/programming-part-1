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
