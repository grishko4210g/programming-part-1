#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <stdio.h>
/**
 * @brief Dynamic array of lamps
 */
struct LampArray {
    struct Lamp *items;
    int size;
};

struct LampArray read_from_file(const char *path);
void print_array(struct LampArray *arr);
void lamp_switch(struct Lamp *lamp);

struct LampArray create_first_array();

//  Add, remove, sorty:
void add_lamp(struct LampArray *arr, struct Lamp lamp);
void remove_lamp(struct LampArray *arr, int index);
void sort_by_watt(struct LampArray *arr);

int total_watt(struct LampArray *arr);
void find_burned(struct LampArray *arr);

//
void print_by_color_temp (struct LampArray *arr);

#endif