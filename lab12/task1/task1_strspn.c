#include <stdio.h>

size_t my_file(const char *str, const char *accept) {
    const char *s = str;
    const char *a;

    size_t count = 0;

    while (*s) {
        a = accept;
        int match = 0;

        while (*a) {
            if(*s == *a) {
                match = 1;
                break;
            }
            a++;
        }
        if(!match)
        break;
        count++;
        s++;
    }
    return count;
}

// main
int main () {
    const char *str = "exchange";
    const char *acc = "change782";

    size_t b = my_file(str, acc);
    printf("Results: %zu \n", b);
    return 0;
}