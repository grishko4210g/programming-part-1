/**
 * @file list.c
 * @brief Implementation of singly linked list for lamps
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// add lamps
void add_lamp(struct Node **head, struct Lamp lamp) {
    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->data = lamp;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// print lamps
void print_lamp(struct Node *head) {

    struct Node *current = head;
    int i = 0;

    printf("\n%-5s | %-10s | %-5s | %-5s | %-5s | %-7s | %-10s | %-40s\n",
        "№", "Name", "ON", "Burn", "Watt", "Temp", "Type", "SMART INFO");

    while (current != NULL) {
        struct Lamp *p = &current->data;
        const char *type;

        if (p->type == BASIC) {
            type = "BASIC";
        } else if (p->type == SMART) {
            type = "SMART";
        } else {
            type = "ETERNAL";
        }

        // Smart information
        char smart_info[120];
        smart_info[0] = '\0';

        if (p->type == SMART) {
            strcat(smart_info, "WiFi: ");
            if (p->smart.wireless == true) {
                strcat(smart_info, "YES");
            } else {
                strcat(smart_info, "NO");
            }
            strcat(smart_info, "; MCU: ");
            if (p->smart.mc == ESP8266) {
                strcat(smart_info, "ESP8266");
            } else {
                strcat(smart_info, "STM32F103");
            }
            strcat(smart_info, "; Color: ");
            strcat(smart_info, p->smart.hex_color);
        } else {
            strcpy(smart_info, "-");
        }

        const char *on_str;
        if (p->is_on == true) {
            on_str = "YES";
        } else {
            on_str = "NO";
        }

        const char *burn_str;
        if (p->is_burned == true) {
            burn_str = "YES";
        } else {
            burn_str = "NO";
        }

        printf("%-3d | %-10s | %-5s | %-5s | %-5d | %-7d | %-10s | %-40s\n",
            i,
            p->manufacturer,
            on_str,
            burn_str,
            p->watt,
            p->color_temp,
            type,
            smart_info
        );

        current = current->next;
        i++;
    }
}

// Remove lamps
void remove_lamp(struct Node **head, int index) {

    if (*head == NULL || index < 0) {
        return;
    }
    struct Node *temp = *head;

    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

// Sorted
void sort_by_watt(struct Node **head) {

    if (*head == NULL) {
        return;
    }
    int swapped;
    do {
        swapped = 0;
        struct Node *cur = *head;
        while (cur->next != NULL) {
            if (cur->data.watt > cur->next->data.watt) {
                struct Lamp tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                swapped = 1;
            }
            cur = cur->next;
        }

    } while (swapped);
}
// print by color
void print_by_color_temp(struct Node *head) {
    printf("Lamp діапазон from 3000 to 6000: \n");

    while (head != NULL) {
        if (head->data.color_temp >= 3000 && head->data.color_temp <= 6000) {
            printf("\n Manufacturer: %s\n", head->data.color_temp);
        }
        head = head->next;
    }
}


// Total watt
int total_watt(struct Node *head) {
    int sum = 0;
    while (head != NULL) {
        if (head->data.is_burned == false) {
            sum += head->data.watt;
        }
        head = head->next;
    }
    return sum;
}

// Find Burned
void find_burned(struct Node *head) {
    printf("\nBurned lamps:\n");
    while (head != NULL) {
        if (head->data.is_burned == true) {
            printf("- %s\n", head->data.manufacturer);
        }
        head = head->next;
    }
}

// Save file
void save_file(struct Node *head, const char *filename) {

    FILE *f = fopen(filename, "w");

    if (f == NULL) {
        printf("File error!\n");
        return;
    }

    while (head != NULL) {
        fprintf(f, "%s %d %d %d %d\n",
            head->data.manufacturer,
            head->data.watt,
            head->data.color_temp,
            head->data.switch_count,
            head->data.type
        );
        head = head->next;
    }

    fclose(f);
}

// Read file
void read_from_file(struct Node **head, const char *filename) {

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File open error!\n");
        return;
    }
    struct Lamp lamp;

    while (fscanf(file, "%s %d %d %d %d",
        lamp.manufacturer,
        &lamp.watt,
        &lamp.color_temp,
        &lamp.switch_count,
        (int*)&lamp.type) == 5) {
//  Checking
        if (lamp.type == ETERNAL) {
            lamp.is_on = true;
            lamp.is_burned = false;
        } else {
            if (lamp.switch_count > 0) {
                lamp.is_on = true;
                lamp.is_burned = false;
            } else {
                lamp.is_on = false;
                lamp.is_burned = true;
            }
        }

        add_lamp(head, lamp);
    }

    fclose(file);
}

// Free
void free_list(struct Node *head) {

    struct Node *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}