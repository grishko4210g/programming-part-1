#include "lib.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: ./program input.txt output.txt\n");
        return 1;
    }

    struct LampArray arr = read_from_file(argv[1]);

    FILE *out = fopen(argv[2], "w");
    if (!out) {
        perror("Error: cannot open file\n");
        return 1;
    }
    print_array(&arr, stdout);
    print_array(&arr, out);

    printf("\n~=~=~=~| Turn on: |~=~=~=~\n");
    fprintf(out,"\n~=~=~=~| Turn on: |~=~=~=~\n");
    struct Lamp *p = arr.items;
    for (int i = 0; i < arr.size; i++, p++) {
        lamp_switch(p);
    }

    print_array(&arr, stdout);
    print_array(&arr, out);

    printf("\nBurned:\n");
    fprintf(out, "\nBurned:\n");
    find_burned(&arr, out);

    int sum = total_watt(&arr);
    printf("\nTotal watte: %d\n", total_watt(&arr));
    fprintf(out, "\nTotal watte: %d\n", sum);


    sort_by_watt(&arr);

    printf("\n~=~=~=~| Sorted |~=~=~=~\n");
    fprintf(out,"\n~=~=~=~| Sorted |~=~=~=~\n");
    print_array(&arr, stdout);
    print_array(&arr, out);

    fclose(out);
    free(arr.items);

    return 0;
}