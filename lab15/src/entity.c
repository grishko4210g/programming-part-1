#include "entity.h"
/**
 * @brief Switches lamp state
 *
 * @param lamp pointer to Lamp structure
 */
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