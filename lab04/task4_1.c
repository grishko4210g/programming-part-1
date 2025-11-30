#include <stdio.h>

int main(void) {
    double a, b, c, x, y;

    printf("Enter brick dimensions (a b c): ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        puts("Invalid brick input");
        return 1;
    }

    printf("Enter hole dimensions (x y): ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        puts("Invalid hole value");
        return 2;
    }

    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        puts("All dimensions must be positive");
        return 3;
    }

    if ((a <= x && b <= y) || (a <= y && b <= x) ||
        (a <= x && c <= y) || (a <= y && c <= x) ||
        (b <= x && c <= y) || (b <= y && c <= x)) {
        puts("Brick  fits");
    } else {
        puts("Doesn't fit");
    }

    return 0;
}