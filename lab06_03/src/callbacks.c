#include "callbacks.h"

void frame_loop(int frames, ActionInt tick) {
    if (!tick) return;     // if there isn't function
    if (frames <= 0) return; // if the number of frames is incorrect

    for (int frame = 0; frame < frames; ++frame) {
        tick(frame);       // calling callbacks function
    }
}
