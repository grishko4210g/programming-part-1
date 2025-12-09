#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Smartphone {
    char brand[10];
    char model[80];
    int memory;
    double price;
} Smartphone;

// task 1(.txt)
int create_text_file(const char *filename) {
    FILE *f = fopen("lab10.txt", "w");
    if(!f) {
        perror("fopen failed"); // cheking problem
        return 0;
    }
    fprintf(f, "%s %s %d %.2f\n", "Apple", "Iphone 15", 128, 40000.00),
    fprintf(f, "%s %s %d %.2f\n", "Xiaomi", "Xiaomi 15T Pro", 256, 28000.00),
    fprintf(f, "%s %s %d %.2f\n", "POCO", "POCO F7", 256, 17000.00),

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

//main
int main () {
    if(!create_text_file("lab10.txt")) {
        printf("Error: in writing the text\n");
        return 1;
    }
    printf("text file 'lab10.txt' written successful\n");

    // .bin file
    Smartphone phones[3] = {
        {"Apple", "Iphone 15", 128, 40000.00},
        {"Xiaomi", "Xiaomi 15T Pro", 256, 28000.00},
        {"POCO", "POCO F7", 256, 17000.00},
    };
    if(!write_binary_array("lab10.bin", phones, 3)) {
        printf("Error: writing binary file\n");
        return 1;
    }
    printf("Binary file 'lab10.bin' writtet successful\n");
    return 0;
}