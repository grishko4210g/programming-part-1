#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int read_task(FILE *file) {
    int task;
    fscanf(file, "%d", &task);
    return task;  //  Return number task
}
// Triangle
void write_triangle(FILE *file, int h, char sym) {
    for(int i = 1; i <= h; i++) {
        for (int j = 1; j <= h - i; j++) {  // Spaces
            fprintf(file, " ");  // That it's centered
        }
        for (int j = 1; j <= 2 * i - 1; j++) {  // Symbols
            fprintf(file, "%c", sym);
        }
        fprintf(file, "\n");
    }

}
// Matrix
void read_matrix(FILE *file, int ***a, int *h, int *w) {
    fscanf(file, "%d %d", h, w);

    *a = (int**)malloc((*h) * sizeof(int*));

    for (int i = 0; i < *h; i++) {
        *(*a + i) = (int*)malloc((*w) * sizeof(int));
    }
    for (int i = 0; i < *h; i++) {  // рядки
        for (int j = 0; j < *w; j++) {  // стовпці
            fscanf(file, "%d", (*((*a) + i) + j));  // Or a[i][j]
        }
    }
}
void free_matrix(int **a, int h) {
    for (int i = 0; i < h; i++) {
        free(*(a + i));
    }
    free(a);
}
// Options(matrix)
int find_max(int **a, int h, int w) {
    int max = *(*(a + 0) + 0);  // Max Number

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (*(*(a + i) + j) > max) {
                max = *(*(a + i) + j);
            }
        }
    }
    return max;
}
// Main diagonal
int sum_above_main(int **a, int h, int w) {
    int sum = 0;

    for (int i = 0; i < h; i++) {  // рядки
        for (int j = i + 1; j < w; j++) {  // стовпці
            sum += *(*(a + i) + j);
        }
    }
    return sum;
}
// Secondary diagonal
int sum_below_secondary(int **a, int h, int w) {
    int sum = 0;

    for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i + j > w - 1) {
                sum += *(*(a + i) + j);
            }
        }
    }
    return sum;
}
// Simple numbers
int is_simple(int a) {
    if (a < 2) {
        return 0;
    }
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}
// Simple numbers on diagonal
void print_simple_on_diag(FILE *file, int **a, int h, int w) {
    int n;
    if(h < w) {
        n = h;
    } else {
        n = w;
    }
    for (int i = 0; i < n; i++) {
        int val = *(*(a + i) + i);

        if (is_simple(val)) {
            fprintf(file, "%d ", val);
        }
    }
    fprintf(file, "\n");
}