#ifndef CALLBACKS_H
#define CALLBACKS_H

// type of pointer to the function that accepts int
typedef void (*ActionInt)(int);

void frame_loop(int frames, ActionInt tick);

#endif 
