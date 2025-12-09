#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0.0;   /* change in GDB or input below*/
    double a, b, c, d, e, E;
    printf("x = ");
    scanf("%lf", &x); /* one read, no conditions */
    a = x*x*x - 1;
    b = x - 1;
    c = 6 - x;
    d = 2*x + 3;
    e = x*x - 2;

    E = a/b + (c*e)/d;
    
   printf("E(%.3f) = %.8f\n", x, E);
   
   return 0; 
}