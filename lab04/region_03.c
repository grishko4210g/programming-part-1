#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    const double EPS = 1e-9;

    double x, y;
    if(scanf("%lf %lf", &x, &y) != 2) {
        puts("Input error");
        return 1;
    }
double y1 = x*x - 0.5;
double y2 = 1.0 - fabs(x);

bool inside = (y >= y1 - EPS) && (y <= y2 + EPS);

if (inside) {
    puts("YES");
} else {
    puts("NO");
}

return 0;

}