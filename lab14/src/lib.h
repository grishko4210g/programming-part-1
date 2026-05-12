#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdbool.h>


enum LampType {
    BASIC = 0,
    SMART = 1,
    ETERNAL = 2
};

enum LampShape {
    CANDLE,
    TUBULAR,
    GLOBE,
    PEAR,
    OGIVE
};

enum LampSocket {
    E14,
    E27,
    E40
};

enum Microcontroller {
    STM32F103,
    ESP8266
};

struct SmartLamp {
    bool wireless;
    enum Microcontroller mc;
    char hex_color[8];
};

struct Lamp {
    enum LampType type;

    bool is_on;
    bool is_burned;
    char manufacturer[60];
    int switch_count;
    int watt;
    int color_temp;

    enum LampShape shape;
    enum LampSocket socket;

    struct SmartLamp smart;
};

struct LampArray {
    struct Lamp *items;
    int size;
};

// Function

struct LampArray read_from_file(const char *path);

void print_array(struct LampArray *arr, FILE *out);
void lamp_switch(struct Lamp *lamp);
int total_watt(struct LampArray *arr);
void find_burned(struct LampArray *arr, FILE *out);
void sort_by_watt(struct LampArray *arr);

#endif