#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct node
{
    void *data;
    struct node *next;
};
typedef struct node node_t;

node_t *addnode(node_t *head, void *data);
void free_list(node_t *head);

#endif // LIST_H
