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
