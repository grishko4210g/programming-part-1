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
