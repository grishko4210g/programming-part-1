#include <stdio.h>
#include "lib.h"

int max_number(int n) {
    if(n < 10) return n;  // Base case
    int last = n % 10;
    int best = max_number (n / 10);  // Recursive call
    return (last > best) ? last : best;
}
int max_number_iterative (int n) {
    int max = 0;
    while (n > 0) {
        int d = n % 10;
        if (d > max) max = d;
        n /= 10;
    }
    return max;
}

// task 2
void print_row_recursive(int count, char symbol) {
    if (count <= 0) return;  // Base case
    printf("%c", symbol);
    print_row_recursive(count - 1, symbol);
}

// Recursion tree
void draw_tree_recursion(int n, int level) {
    if (level > n) return;
    int spaces = n - level;
    int stars = level * 2 - 1;
    print_row_recursive(spaces, ' ');
    print_row_recursive(stars, '#');
    printf("\n");
    draw_tree_recursion(n, level + 1);
}

void draw_tree(int n) {
    draw_tree_recursion(n, 1);
}