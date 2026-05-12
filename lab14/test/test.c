#include "../src/lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  First
void assert_int(const char *name, int actual, int expected) {
    if (actual == expected)
        printf("[PASS] %s\n", name);
    else
        printf("[FAIL] %s expected=%d got=%d\n", name, expected, actual);
}

void assert_bool(const char *name, int actual, int expected) {
    if (actual == expected)
        printf("[PASS] %s\n", name);
    else
        printf("[FAIL] %s expected=%d got=%d\n", name, expected, actual);
}

// Test 1
void test_read_and_sum() {

    struct LampArray arr = read_from_file("assets/input.txt");

    int sum = total_watt(&arr);

    printf("[INFO] total consumption = %d\n", sum);

    assert_bool("Total > 0", sum > 0, 1);

    free(arr.items);
}

// Test 2
void test_switch() {

    struct Lamp l;
    memset(&l, 0, sizeof(struct Lamp));

    l.type = BASIC;
    l.switch_count = 2;
    l.is_burned = 0;
    l.is_on = 0;

    lamp_switch(&l);

    assert_bool("Lamp ON after switch", l.is_on, 1);

    lamp_switch(&l);

    //  Checking lamp(burned)
    if (l.switch_count <= 0) {
        assert_bool("Lamp burned state reached", l.is_burned, 1);
    }
}

//  Test 3
void test_sort() {

    struct LampArray arr = read_from_file("assets/input.txt");

    sort_by_watt(&arr);

    for (int i = 0; i < arr.size - 1; i++) {
        if (arr.items[i].watt > arr.items[i + 1].watt) {
            printf("[FAIL] Sort by watts\n");
            free(arr.items);
            return;
        }
    }

    printf("[PASS] Sort by watts\n");

    free(arr.items);
}

//  main
int main() {

    printf("\n Test lab14: \n\n");

    test_read_and_sum();
    test_switch();
    test_sort();

    printf("\n That's all! \n");

    return 0;
}