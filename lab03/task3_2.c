#include <stdio.h>
#include <math.h>

int main(void) {
    double x, E;

    printf("Enter x: ");
    scanf("%lf", &x);

    /* computer parts separately for easier GDB inspection */
    double a = sin(x) - cos(x);
    double b = tan(x);
    double c = log10(x + 1);
    double d = cos(4 * x);
    double e = exp(x);
    
    E = a / b + (c * d) / e;

    printf("E(%.3f) = %.8f\n", x, E);
    return 0;
}