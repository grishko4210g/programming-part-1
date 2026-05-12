/**
 * @file main.c
 * @brief Main file of Lab 15
 *
 * Demonstrates work of dynamic array of lamps,
 * including add, remove, sort and calculations.
 */
#include "list.h"
#include <stdlib.h>
#include <string.h>

int main() {

    struct LampArray arr = create_first_array();
    struct Lamp *p = arr.items;

    for (int i = 0; i < arr.size; i++, p++) {
        lamp_switch(p);
    }

    print_array(&arr);
    printf("\nTotal watt: %d\n", total_watt(&arr));
    find_burned(&arr);

    //  Add Lamp
    struct Lamp new_lamp = {
        .type = BASIC,
        .is_on = true,
        .is_burned = false,
        .switch_count = 10,
        .watt = 90,
        .color_temp = 3500,
        .shape = OGIVE,
        .socket = E27
    };

    strcpy(new_lamp.manufacturer, "Samsung");
    add_lamp(&arr, new_lamp);

    printf("\n=~=~=~=~=~| After add: |=~=~=~=~=~\n");
    print_array(&arr);

    // Remove 
    remove_lamp(&arr, 1);

    printf("\n=~=~=~=~=~| After remove: |=~=~=~=~=~\n");
    print_array(&arr);

    // Sorted
    sort_by_watt(&arr);

    printf("\n=~=~=~=~=~| Sorted |=~=~=~=~=~\n");
    print_array(&arr);

    //
    print_by_color_temp(&arr);
    printf("Color_temp:~~~~~~");

    free(arr.items);

    return 0;
}