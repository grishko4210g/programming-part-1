/**
 * @file entity.h
 * @brief Description of lamp entities
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>

/**
 * @brief Lamp types
 */
enum LampType {
    BASIC = 0,
    SMART = 1,
    ETERNAL = 2
};

/**
 * @brief Lamp shape types
*/

enum LampShape {
    CANDLE,
    TUBULAR,
    GLOBE,
    PEAR,
    OGIVE
};
/**
 * @brief Socket types
 */
enum LampSocket {
    E14,
    E27,
    E40
};
/**
 * @brief Microcontroller types
 */
enum Microcontroller {
    STM32F103,
    ESP8266
};
/**
 * @brief Smart lamp additional data
 */
struct SmartLamp {
    bool wireless;
    enum Microcontroller mc;
    char hex_color[8];
};
/**
 * @brief Main lamp structure
 */
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

void lamp_switch(struct Lamp *lamp);

#endif