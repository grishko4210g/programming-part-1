#ifndef LIB_H_
#define LIB_H_

#define MAX_MANUFACTURER_LEN 30
#define MAX_MODEL_LEN 70

typedef struct Smartphone
{
    char manufacturer[MAX_MANUFACTURER_LEN];
    char model[MAX_MODEL_LEN];
    int storage_gb;
    float price;
} Smartphone;

// task 1(.txt)
int create_text_file(const char *filename);
void print_smartphone(const Smartphone *s);
int print_all_text(const char *filename);
int find_text_by_manufacturer(const char *filename, const char *key);
int delete_model(const char *original_file);

// task 2(.bin)

int write_binary_array(const char *filename, Smartphone *arr, size_t count);
int read_binary_array(const char *fileman, Smartphone **arr_ptr, size_t *count_ptr);

#endif //LIB_H