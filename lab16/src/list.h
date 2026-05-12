#ifndef LIST_H
#define LIST_H

#include "entity.h"

struct Node {
    struct Lamp data;
    struct Node *next;
};

void print_lamp(struct Node *head);
void add_lamp(struct Node **head, struct Lamp lamp);
void remove_lamp(struct Node **head, int index);
void sort_by_watt(struct Node **head);
int total_watt(struct Node *head);
void find_burned(struct Node *head);
void free_list(struct Node *head);
void save_file(struct Node *head, const char *filename);
void read_from_file(struct Node **head, const char *filename);


void print_by_color_temp(struct Node *head);

#endif