#include <stdio.h>
#include "lib.h"

int main() {
    int n;

    // Task 1
    printf("Enter number: \n");
    scanf("%d", &n);

    int r1 = max_number(n); 
    int r2 = max_number_iterative(n);

    printf("Recursive max digit: %d\n", r1);
    printf("Iterative max digit: %d\n", r2);

    // Task 2
    printf("Enter tree height: \n");
    scanf("%d", &n);

    draw_tree(n);

    return 0;
}
