#include <stdio.h>
#include "include/callbacks.h"

// callback №1 — prints the frame number
void print_frame(int frame) {
    printf("Frame %d\n", frame);
}

// callback №2 —  shows progress as a percentage
void show_progress(int frame) {
    printf("Progress: %d%%\n", frame * 10);
}

// callback №3 — print a message every 2 frames
void notify_special(int frame) {
    if (frame % 2 == 0)
        printf("Even frame %d reached!\n", frame);
}

int main(void) {
    puts("=== Demo 1: print frames ===");
    frame_loop(5, print_frame);

    puts("\n=== Demo 2: progress ===");
    frame_loop(10, show_progress);

    puts("\n=== Demo 3: only even frames ===");
    frame_loop(6, notify_special);

    puts("\n=== Edge cases ===");
    frame_loop(0, print_frame);
    frame_loop(5, NULL);

    return 0;
}
