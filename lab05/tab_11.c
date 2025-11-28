#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0.0, b = 3.0;  // відрізок [0, 3]
    int n;

    // Ввід кількості точок
    if (scanf("%d", &n) != 1 || n <= 0) {
        puts("Invalid n");
        return 1;
    }

    double step = (b - a) / (n - 1);  // крок між точками
    int i = 0;
    double x, y;

    do {
        x = a + i * step;
        // Обчислення функції y = tan(pi + x/4) / (pi - x/4)^3
        y = tan(M_PI + x / 4.0) / pow(M_PI - x / 4.0, 3);
        printf("%10.5f %12.5f\n", x, y);
        i++;
    } while (i < n);

    return 0;
}
