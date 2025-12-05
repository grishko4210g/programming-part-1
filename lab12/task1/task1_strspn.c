#include <stdio.h>

size_t my_file_copy(const char *str, const char *accept) {
    const char *current = str;
    const char *acc_ptr = accept;

    size_t count = 0;

    while (*current) {
        acc_ptr = accept;
        int match = 0;

        while(*acc_ptr) {
            if (*current == *acc_ptr) {
                match = 1;
                break;
            }
            acc_ptr++;
        }
        if (!match) {
            break;
        }
        count++;
        current++;
    }
    return count;
}

// main
int main () {
    const char *str = "exchange";
    const char *acc = "change782";

    size_t result = my_file_copy(str, acc);
    printf("Results: %zu \n", result);
    return 0;
}