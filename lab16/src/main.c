#include "list.h"
#include <stdio.h>
#include <string.h>

void menu();

int main() {
    struct Node *head = NULL;
    int choice;
    
    do { 
        menu();
        printf("\nChoice: \n");
        scanf("%d", &choice);

        if (choice == 1) {  // Print lamp
            print_lamp(head);
        } else if (choice == 2) {  // Add lamp
            struct Lamp lamp;
            char type_str[20];
            char wifi_str[6];
            char mc_str[20];

            printf("Enter manufacturer(brend): \n");
            scanf("%s", lamp.manufacturer);

            printf("Enter watt: \n");
            scanf("%d", &lamp.watt);

            printf("Enter color temperatures: \n");
            scanf("%d", &lamp.color_temp);

            printf("Enter switch count: ");
            scanf("%d", &lamp.switch_count);

            printf("Please, select a lamp type(BASIC, SMART, ETERNAL): ");
            scanf("%s", type_str);

            if (strcmp(type_str, "basic") == 0 || strcmp(type_str, "Basic") == 0 || strcmp(type_str, "BASIC") == 0) {
                lamp.type = BASIC;
            } else if (strcmp(type_str, "smart") == 0 || strcmp(type_str, "Smart") == 0 || strcmp(type_str, "SMART") == 0) {
                lamp.type = SMART;
            } else if (strcmp(type_str, "eternal") == 0 || strcmp(type_str, "Eternal") == 0 || strcmp(type_str, "ETERNAL") == 0) {
                lamp.type = ETERNAL;
            } else {
                printf("Unknown type, setting BASIC by default\n");
                lamp.type = BASIC;
            }

            // Checking switch
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
            lamp.shape = OGIVE;
            lamp.socket = E27;

            // Smart lamp
            if (lamp.type == SMART) {

                printf("Enter WIFI(yes/no): ");
                scanf("%s", wifi_str);

                if (strcmp(wifi_str, "YES") == 0 || strcmp(wifi_str, "Yes") == 0 || strcmp(wifi_str, "yes") == 0) {
                    lamp.smart.wireless = true;
                } else {
                    lamp.smart.wireless = false;
                }

                printf("Enter MCU (ESP8266 or STM32F103): ");
                scanf("%s", mc_str);

                if (strcmp(mc_str, "ESP8266") == 0 || strcmp(mc_str, "esp8266") == 0 || strcmp(mc_str, "Esp8266") == 0) {
                    lamp.smart.mc = ESP8266;
                } else if (strcmp(mc_str, "STM32F103") == 0 || strcmp(mc_str, "stm32f103") == 0 || strcmp(mc_str, "Stm32f103") == 0) {
                    lamp.smart.mc = STM32F103;
                } else {
                    printf("Unknown MCU, setting ESP8266 by default\n");
                    lamp.smart.mc = ESP8266;
                }

                printf("Enter color (For example #ffffff): ");
                scanf("%s", lamp.smart.hex_color);
            }

            add_lamp(&head, lamp);
            print_lamp(head);
        }

        // Remove
        else if (choice == 3) {
            int i;
            print_lamp(head);

            printf("Enter index: ");
            scanf("%d", &i);

            remove_lamp(&head, i);

        } else if (choice == 4) {  // Sorted
            sort_by_watt(&head);
            print_lamp(head);
        } else if (choice == 5) {  // Total watt
            printf("Total watt: %d\n", total_watt(head)); 
        } else if (choice == 6) {  // Burned lamp
            find_burned(head);
        } else if (choice == 7) {
            save_file(head, "lab16.txt");
        } else if (choice == 8) {

            free_list(head);
            head = NULL;
            read_from_file(&head, "lab16.txt");

            print_lamp(head);
        } else if (choice == 9) {
            print_by_color_temp(head);
        }

    } while (choice != 0);

    free_list(head);

    return 0;
}