#include <stdio.h>
#include "lib.h"

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: ./program input.txt output.txt\n");
        return 1;
    }

    FILE *file_in = fopen(argv[1], "r");
    FILE *file_out = fopen(argv[2], "w");

    // Checking open file!
    if (file_in == NULL || file_out == NULL) {
        printf("The file cannot be opened!\n");
        return 1;
    }

    int task;
// Check file
    while (fscanf(file_in, "%d", &task) == 1) {  // Read task
        if (task == 1) {
            int h;
            int w;
            char sym;
            fscanf(file_in, "%d %d %c", &h, &w, &sym);

            fprintf(file_out, "--- TASK 1: TRIANGLE ---\n");
            fprintf(stdout, "--- TASK 1: TRIANGLE ---\n");

            write_triangle(file_out, h, sym);
            write_triangle(stdout, h, sym);
        }
        else if (task == 2) {
            int **a;
            int h;
            int w;

            fprintf(file_out, "--- TASK 2: MATRIX ---\n");
            fprintf(stdout, "--- TASK 2: MATRIX ---\n");

            read_matrix(file_in, &a, &h, &w);

            fprintf(file_out, "Max number: %d\n", find_max(a, h, w));
            fprintf(stdout, "Max number: %d\n", find_max(a, h, w));

            fprintf(file_out, "Sum above main diagonal: %d\n", sum_above_main(a, h, w));
            fprintf(stdout, "Sum above main diagonal: %d\n", sum_above_main(a, h, w));

            fprintf(file_out, "Sum below secondary diagonal: %d\n", sum_below_secondary(a, h, w));
            fprintf(stdout, "Sum below secondary diagonal: %d\n", sum_below_secondary(a, h, w));

            fprintf(file_out, "Primes on diagonal: ");
            fprintf(stdout, "Primes on diagonal: ");

            print_simple_on_diag(file_out, a, h, w);
            print_simple_on_diag(stdout, a, h, w);

            free_matrix(a, h);
        }
        else {
            fprintf(stderr, "UNKNOWN TASK!\n");
            break;  // That the code doesn't break
        }
    }

    fclose(file_in);
    fclose(file_out);

    return 0;
}