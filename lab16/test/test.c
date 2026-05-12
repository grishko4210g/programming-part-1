#include "../src/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lamp create_lamp(const char *name, int watt, int color_temp, int switch_count, enum LampType type) {
    struct Lamp lamp;

    strcpy(lamp.manufacturer, name);
    lamp.color_temp = color_temp;
    lamp.switch_count = switch_count;
    lamp.type = type;
    lamp.watt = watt;
    lamp.shape = OGIVE;
    lamp.socket = E40;

    // Smart lamp
    lamp.smart.wireless = false;
    lamp.smart.mc = ESP8266;
    strcpy(lamp.smart.hex_color, "#602222");

    if (type == ETERNAL) {
        lamp.is_on = true;
        lamp.is_burned = false;
    } else {
        if (switch_count > 0) {
            lamp.is_on = true;
            lamp.is_burned = false;
        } else {
            lamp.is_on = false;
            lamp.is_burned = true;
        }
    }

    return lamp;
}

void test_add() {
    printf("\n Test add \n");
    struct Node *head = NULL;

    add_lamp(&head, create_lamp("Xiaomi", 120, 2600, 1, BASIC));
    add_lamp(&head, create_lamp("Ikero", 140, 3200, 1, BASIC));
    
    if (head != NULL && head->data.watt == 120 && head->next->data.watt == 140) {
        printf("Test add: PASSED!\n");
    } else {
        printf("Test add: FAILED!\n");
    }
    free_list(head);
    }

    // Remove
    void test_remove() {

    printf("\n Remove test \n");

    struct Node *head = NULL;

    add_lamp(&head, create_lamp("Xiaomi", 160, 2000, 1, BASIC));
    add_lamp(&head, create_lamp("Ikero", 200, 2000, 1, BASIC));
    add_lamp(&head, create_lamp("CChio", 365, 2000, 1, BASIC));

    remove_lamp(&head, 1);

    if (head != NULL &&
        head->next != NULL &&
        head->next->data.watt == 300) {
        printf("Test Remove: PASSED!\n");
    } else {
        printf("Test Remove: FAILED!\n");
    }
    free_list(head);
}

// Sorted
void test_sort() {

    printf("\n Sorted Test \n");

    struct Node *head = NULL;

    add_lamp(&head, create_lamp("Xiaomi", 1200, 2000, 1, BASIC));
    add_lamp(&head, create_lamp("Ikero", 100, 2000, 1, BASIC));
    add_lamp(&head, create_lamp("Cchio", 2200, 2000, 1, BASIC));

    sort_by_watt(&head);

    if (head->data.watt == 100 &&
        head->next->data.watt == 200 &&
        head->next->next->data.watt == 300) {
        printf("Test Sorted: PASSED!\n");
    } else {
        printf("Test Sorted: FAILED!\n");
    }
    free_list(head);
}

// Total watt
void test_total_watt() {

    printf("\n Total watt Test \n");

    struct Node *head = NULL;

    add_lamp(&head, create_lamp("Xiaomi", 190, 2000, 1, BASIC));
    add_lamp(&head, create_lamp("Ikero", 1800, 2000, 0, BASIC)); // burned

    int sum = total_watt(head);

    if (sum == 100) {
        printf("Tets Total Watt: PASSED!\n");
    } else {
        printf("Tets Total Watt: FAILED\n" );
    }
    free_list(head);
}

// Test save
void test_save_load() {

    printf("\n Save Test \n");

    struct Node *head = NULL;

    add_lamp(&head, create_lamp("Hihi", 150, 2500, 2, BASIC));
    save_file(head, "lab16_test.txt");

    free_list(head);
    head = NULL;

    read_from_file(&head, "lab16_test.txt");

    if (head != NULL &&
        strcmp(head->data.manufacturer, "Hihi") == 0 &&
        head->data.watt == 150) {
        printf("Test Save: PASSED!\n");
    } else {
        printf("Test Save: FAILED!\n");
    }
    free_list(head);
}

// main
int main() {

    printf("\n~=~=~=~=~=| Start Test |~=~=~=~=~=\n");

    test_add();
    test_remove();
    test_sort();
    test_total_watt();
    test_save_load();
    
    printf("\n~=~=~=~=~=| Tests finished |~=~=~=~=~=\n");

    return 0;
}