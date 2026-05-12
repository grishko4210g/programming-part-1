#include "lib.h"
#include <stdlib.h>
#include <string.h>

//  Switch
void lamp_switch(struct Lamp *lamp) {

    if (lamp->type == ETERNAL) {
        lamp->is_on = 1;
        return;
    }

    if (lamp->is_burned) {
        lamp->is_on = 0;
        return;
    }

    if (lamp->switch_count > 0) {
        lamp->switch_count--;
        lamp->is_on = 1;
    }

    if (lamp->switch_count == 0) {
        lamp->is_burned = 1;
        lamp->is_on = 0;
    }
}

// Read File
struct LampArray read_from_file(const char *path) {

    FILE *f = fopen(path, "r");

    struct LampArray arr;  //  Reading the number of lamps
    fscanf(f, "%d", &arr.size);

    arr.items = malloc(sizeof(struct Lamp) * arr.size);

    struct Lamp *p = arr.items;  // Start array

    for (int i = 0; i < arr.size; i++, p++) {  // Read array

        int shape; 
        int socket;
        char tmp[100];  // Buffer

        fscanf(f, "%d %s %d %s %d %d %d %d %d",
               (int*)&p->type,
               tmp,
               (int*)&p->is_burned,
               p->manufacturer,
               &p->switch_count,
               &p->watt,
               &p->color_temp,
               &shape,
               &socket);

        p->shape = shape;
        p->socket = socket;
        p->is_on = 0;

        if (p->type == SMART) {

            int wireless;
            char mc_str[32];

            fscanf(f, "%d %s %s", &wireless, mc_str, p->smart.hex_color);

            p->smart.wireless = wireless;
            if (strcmp(mc_str, "STM32F103") == 0) {  // Comparison
                p->smart.mc = STM32F103;
            } else
                p->smart.mc = ESP8266;
        }
        else {  // If It isn't smart(it will space -)
            p->smart.wireless = 0;
            p->smart.mc = STM32F103;
            strcpy(p->smart.hex_color, "-");
        }
    }

    fclose(f);
    return arr;
}

// Print file
void print_array(struct LampArray *arr, FILE *out) {

    fprintf(out, "\n--- All Lamps ---\n");

    fprintf(out, " %-2s | %-8s | %-3s | %-5s | %-5s | %-5s | %-8s | %-7s | %-8s | %20s\n",
        "№ ",  "Name", "ON", "Burn", "Watt", "Color", "Shape", "Socket", "Type", "SMART");

    fprintf(out, "-------------------------------------------------------------------------------------------------------------------\n");

    struct Lamp *p = arr->items;  // Start array

    for (int i = 0; i < arr->size; i++, p++) {

        const char *shape_str;
        const char *socket_str;
        const char *type_str;

        // Forms lamps
        if (p->shape == CANDLE) {
            shape_str = "CANDLE";
        }
        else if (p->shape == TUBULAR) {
            shape_str = "TUBULAR";
        } else if (p->shape == GLOBE) {
            shape_str = "GLOBE";
        } else if (p->shape == PEAR) {
            shape_str = "PEAR";
        }else if (p->shape == OGIVE) {
            shape_str = "OGIVE";
        } else shape_str = "UNKNOWN";


        // Socket lamps
        if (p->socket == E14) {
            socket_str = "E14";
        } else if (p->socket == E27) {
            socket_str = "E27";
        } else if(p->socket == E40) {
            socket_str = "E40";
        }
        else socket_str = "UNKNOWN";

        //  Type lamps
        if (p->type == BASIC) {
            type_str = "BASIC";
        } else if (p->type == SMART) {
            type_str = "SMART";
        } else type_str = "ETERNAL";

        //  Turn on lamps
        const char *on_off;
        if (p->is_on) {
            on_off = "ON";
        } else on_off = "OFF";

        char smart_info[64] = "-";

        if (p->type == SMART) {

            const char *mc_str;
            const char *wireless_str;

            if (p->smart.wireless) {
                wireless_str = "WIFI: Yes;";
            } else 
                wireless_str = "WIFI: No;";

            if (p->smart.mc == STM32F103) {
                mc_str = "MCU: STM32F103;";
            } else
                mc_str = "MCU: ESP8266;";

        strcpy(smart_info, wireless_str);
        strcat(smart_info, " ");
        strcat(smart_info, mc_str);
        strcat(smart_info, " ");
        strcat(smart_info, p->smart.hex_color);
        }

        fprintf(out,
            " %-2d | %-8s | %-3s | %-5d | %-5d | %-5d | %-8s | %-7s | %-8s | %-20s\n", 
            i,
            p->manufacturer,
            on_off,
            p->is_burned,
            p->watt,
            p->color_temp,
            shape_str,
            socket_str,
            type_str,
            smart_info);
    }
}

// Sum watte
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

void find_burned(struct LampArray *arr, FILE *out) {

    struct Lamp *p = arr->items;

    for (int i = 0; i < arr->size; i++, p++) {
        if (p->is_burned) {
            printf("%s\n", p->manufacturer);
            fprintf(out, "%s\n", p->manufacturer);
        }
    }
}

void sort_by_watt(struct LampArray *arr) {

    for (int i = 0; i < arr->size - 1; i++) {  // For example bubble sort
        for (int j = 0; j < arr->size - i - 1; j++) {

            struct Lamp *a = arr->items + j;
            struct Lamp *b = arr->items + j + 1;  // Next element

            if (a->watt > b->watt) {  //  if a > b, change place
                struct Lamp tmp = *a;
                *a = *b;
                *b = tmp;
            }
        }
    }
}
