#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct LampArray create_first_array () {
    struct LampArray arr;
    arr.size = 5;
    arr.items = malloc(arr.size * sizeof(struct Lamp));

    struct Lamp *p = arr.items;

    // Lamp 1
    *p = (struct Lamp) {
        .type = BASIC,
        .is_on = true,
        .is_burned = false,
        .switch_count = 10,
        .color_temp = 1200,
        .shape = PEAR,
        .socket = E14,
        .watt = 140
    };
    strcpy(p->manufacturer, "Philips");
    p++;

    // Lamp 2
    *p = (struct Lamp) {
        .type = 1,
        .is_on = true,
        .is_burned = false,
        .switch_count = 30,
        .color_temp = 1400,
        .shape = TUBULAR,
        .socket = E27,
        .watt = 10
    };
    strcpy(p->manufacturer, "Xiaomi");
    p++;

    // Lamp 3
    *p = (struct Lamp) {
        .type = SMART,
        .is_on = false,
        .is_burned = true,
        .switch_count = 3,
        .watt = 10,
        .color_temp = 4000,
        .shape = GLOBE,
        .socket = E27,
        .smart = {
            .wireless = true,
            .mc = ESP8266
        }
    };
    strcpy(p->manufacturer, "Ikero");
    strcpy(p->smart.hex_color, "#FFFFFF");
    p++;
    

    //  Lamp 4
        *p = (struct Lamp) {
        .type = SMART,
        .is_on = false,
        .is_burned = true,
        .switch_count = 0,
        .watt = 10,
        .color_temp = 7800,
        .shape = TUBULAR,
        .socket = E27,
        .smart = {
            .wireless = true,
            .mc = ESP8266
        }
    };
    strcpy(p->manufacturer, "CHIO");
    strcpy(p->smart.hex_color, "#ba2020");
    p++;

    // Lamp 5
    *p = (struct Lamp) {
        .type = ETERNAL,
        .is_on = false,
        .is_burned = false,
        .switch_count = 3,
        .watt = 245,
        .color_temp = 4000,
        .shape = GLOBE,
        .socket = E27
    };
    strcpy(p->manufacturer, "FI-FI");

    return arr;
}

//  Print
void print_array(struct LampArray *arr) {

    struct Lamp *p = arr->items;

    printf("\n%-3s | %-10s | %-5s | %-5s | %-5s | %-7s | %-10s | %-10s | %-10s | %-20s\n",
        "№", "Name", "ON", "Burn", "Watt", "Temp", "Shape", "Socket", "Type", "SMART");;

    for (int i = 0; i < arr->size; i++, p++) {
        // Type lamps
        const char *type;
        if (p->type == BASIC) {
            type = "BASIC";
        } else if (p->type == SMART) {
            type = "SMART";
        } else if (p->type == ETERNAL) {
            type = "ETERNAL";
        } else {
            type = "UNKNOWN";
        }

        // Turn on
        const char *on_str;
        if (p->is_on) {
            on_str = "YES";
        } else {
            on_str = "NO";
        }

        // Burned
        const char *burn_str;
        if (p->is_burned) {
            burn_str = "YES";
        } else {
            burn_str = "NO";
        }
        //  Shape
        const char *shape_str;
        if (p->shape == CANDLE) {
            shape_str = "CANDLE";
        } else if (p->shape == TUBULAR) {
            shape_str = "TUBULAR";
        } else if (p->shape == GLOBE) {
            shape_str = "GLOBE";
        } else if (p->shape == PEAR) {
            shape_str = "PEAR";
        } else if (p->shape == OGIVE) {
            shape_str = "OGIVE";
        } else {
            shape_str = "UNKNOWN";
        }

        // Socket
        const char *socket_str;

        if (p->socket == E14) {
            socket_str = "E14";
        } else if (p->socket == E27) {
            socket_str = "E27";
        } else if (p->socket == E40) {
            socket_str = "E40";
        } else {
            socket_str = "UNKNOWN";
        }


        // Smart information
        char smart_info[100];  //  Buffer
        strcpy(smart_info, "-");

        if (p->type == SMART) {

            char wifi[20];
            char mc[30];

            if (p->smart.wireless) {
                strcpy(wifi, "WiFi: YES");
            } else {
                strcpy(wifi, "WiFi: NO");
            }

            if (p->smart.mc == STM32F103) {
                strcpy(mc, "MCU: STM32F103");
            } else {
                strcpy(mc, "MCU: ESP8266");
            }

            strcpy(smart_info, wifi);
            strcat(smart_info, "; ");
            strcat(smart_info, mc);
            strcat(smart_info, "; Color: ");
            strcat(smart_info, p->smart.hex_color);
        }

        printf("%-d | %-10s | %-5s | %-5s | %-5d | %-7d | %-10s | %-10s | %-10s | %-20s\n",
            i,
            p->manufacturer,
            on_str,
            burn_str,
            p->watt,
            p->color_temp,
            shape_str,
            socket_str,
            type,
            smart_info);
    }
}

//  Add lamp
void add_lamp(struct LampArray *arr, struct Lamp lamp) {

    struct Lamp *new_items = malloc((arr->size + 1) * sizeof(struct Lamp));

    struct Lamp *src = arr->items;
    struct Lamp *dst = new_items;

    for (int i = 0; i < arr->size; i++, src++, dst++) {
        *dst = *src;
    }

    *dst = lamp;

    free(arr->items);
    arr->items = new_items;
    arr->size++;
}

//  Remove lamp
void remove_lamp(struct LampArray *arr, int index) {

    if (index < 0 || index >= arr->size) {
        return;
    }

    struct Lamp *new_items = malloc((arr->size - 1) * sizeof(struct Lamp));

    struct Lamp *src = arr->items;
    struct Lamp *dst = new_items;

    for (int i = 0; i < arr->size; i++, src++) {
        if (i == index) {
            continue;
        }

        *dst = *src;
        dst++;
    }

    free(arr->items);
    arr->items = new_items;
    arr->size--;
}
// print діапазон
void print_by_color_temp (struct LampArray *arr) {
    struct Lamp *p = arr->items;
    int min = 3000;
    int max = 6000;
    printf("Lamps with 3000 to 6000: \n", min, max);
        for (int i = 0; i < arr->size; i++, p++) {
            if (p->color_temp >= min && p->color_temp <= max) {
                printf("\nManufacturer: %s\n", p->manufacturer);
            }
        }
    }

//  Sorted
void sort_by_watt(struct LampArray *arr) {

    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            struct Lamp *a = arr->items + j;
            struct Lamp *b = arr->items + j + 1;
            if (a->watt > b->watt) {
                struct Lamp tmp = *a;
                *a = *b;
                *b = tmp;
            }
        }
    }
}

//  Total watt
int total_watt(struct LampArray *arr) {

    int sum = 0;
    struct Lamp *p = arr->items;

    for (int i = 0; i < arr->size; i++, p++) {
        if (!p->is_burned) {
            sum += p->watt;
        }
    }

    return sum;
}

//  Burned
void find_burned(struct LampArray *arr) {

    struct Lamp *p = arr->items;

    printf("\nBurned lamps:\n");

    for (int i = 0; i < arr->size; i++, p++) {
        if (p->is_burned) {
            printf("- %s\n", p->manufacturer);
        }
    }
}
