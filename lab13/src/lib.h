#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
// Task
int read_task(FILE *file);

// Triangle
void write_triangle(FILE *file, int h, char sym);

// Matrix
void read_matrix(FILE *file, int ***a, int *h, int *w);
void free_matrix(int **a, int h);

// Options
int find_max(int **a, int h, int w);
int sum_above_main(int **a, int h, int w);
int sum_below_secondary(int **a, int h, int w);

// Simple Number
int is_simple(int a);
void print_simple_on_diag(FILE *file, int **a, int h, int w);

#endif