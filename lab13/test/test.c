#include <stdio.h>
#include "../src/lib.h"

int main() {

    printf("=== TEST START ===\n");

    //  TEST 1: is_simple
    printf("is_simple(7) = %d (expected 1)\n", is_simple(7));
    printf("is_simple(8) = %d (expected 0)\n", is_simple(8));

    //  TEST 2: find_max
    int h = 3, w = 3;

    int **a = (int**)malloc(h * sizeof(int*));

    for (int i = 0; i < h; i++) {
        a[i] = (int*)malloc(w * sizeof(int));
    }

    int val = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = val++;
        }
    }

    printf("find_max = %d (expected 9)\n", find_max(a, h, w));

    //  TEST 3: sum_above_main
    printf("sum_above_main = %d\n", sum_above_main(a, h, w));

    //  TEST 4: sum_below_secondary
    printf("sum_below_secondary = %d\n", sum_below_secondary(a, h, w));

    free_matrix(a, h);

    printf("=== TEST END ===\n");

    return 0;
}