#include "../src/list.h"
#include <stdio.h>
#include <stdlib.h>

//  Add lamp
void test_add_lamp() {
    struct LampArray arr;

    arr.size = 1;
    arr.items = malloc(sizeof(struct Lamp));

    struct Lamp *p = arr.items;
    *p = (struct Lamp){
        .watt = 120
    };

    struct Lamp new_lamp = {
        .watt = 23
    };

    add_lamp(&arr, new_lamp);

    if (arr.size == 2) {
        printf("Add lamp: PASSED!\n");
    } else {
        printf("Add lamp: FAILED!\n");
    }

    free(arr.items);
}

//  Remove lamp
void test_remove_lamp() {
    struct LampArray arr;

    arr.size = 2;
    arr.items = malloc(arr.size * sizeof(struct Lamp));

    struct Lamp *p = arr.items;

    *p = (struct Lamp){
        .watt = 10
    };
    p++;

    *p = (struct Lamp){
        .watt = 15
    };

    remove_lamp(&arr, 0);

    struct Lamp *check = arr.items;

    if (arr.size == 1 && check->watt == 15) {
        printf("Remove lamp: PASSED!\n");
    } else {
        printf("Remove lamp: FAILED!\n");
    }

    free(arr.items);
}

//  Sorted
void test_sort_by_watt() {

    struct LampArray arr;

    arr.size = 3;
    arr.items = malloc(arr.size * sizeof(struct Lamp));

    struct Lamp *p = arr.items;

    *p = (struct Lamp){
        .watt = 200
    };
    p++;

    *p = (struct Lamp){
        .watt = 450
    };
    p++;

    *p = (struct Lamp){
        .watt = 50
    };

    sort_by_watt(&arr);

    struct Lamp *check = arr.items;

    if (check->watt == 50 && (check + 1)->watt == 200 && (check + 2)->watt == 450) {
        printf("Sort test: PASSED!\n");
    } else {
        printf("Sort test: FAILED!\n");
    }

    free(arr.items);
}

//  Total watt
void test_total_watt() {

    struct LampArray arr;

    arr.size = 2;
    arr.items = malloc(arr.size * sizeof(struct Lamp));

    struct Lamp *p = arr.items;

    *p = (struct Lamp){
        .watt = 30,
        .is_burned = false
    };
    p++;

    *p = (struct Lamp){
        .watt = 180,
        .is_burned = true
    };

    int sum_watt = total_watt(&arr);

    if (sum_watt == 30) {
        printf("Total watt: PASSED!\n");
    } else {
        printf("Total watt: FAILED!\n");
    }

    free(arr.items);
}

// Main
int main() {

    test_add_lamp();
    test_remove_lamp();
    test_sort_by_watt();
    test_total_watt();

    return 0;
}