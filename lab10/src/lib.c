#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// task 1(.txt)
int create_text_file(const char *filename) {
    FILE *f = fopen("lab10.txt", "w");
    if(!f) {
        perror("fopen failed"); // cheking problem
        return 0;
    }
    fprintf(f, "%s %s %d %.2f\n", "Apple", "Iphone 15", 128, 40000.00);
    fprintf(f, "%s %s %d %.2f\n", "Xiaomi", "Xiaomi 15T Pro", 256, 28000.00);
    fprintf(f, "%s %s %d %.2f\n", "POCO", "POCO F7", 256, 17000.00);

    fclose(f);
    return 1;
}

// task 2(.bin)
int write_binary_array(const char *filename, Smartphone *arr, size_t count) {
    FILE *f = fopen("lab10.bin", "wb");
    if(!f) {
        perror("fopen failed");
        return 0;
    }
    if(fwrite(arr, sizeof(Smartphone), count, f) != count){
        perror("fwrite failed");
        fclose(f);
        return 0;
    }
    fclose(f);
    return 1;
}