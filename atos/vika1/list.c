#include "list.h"

node_t *addnode(node_t *head, void *data)
{
    node_t *tmp = malloc(sizeof(node_t));
    if (!tmp)
        return NULL;
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

void free_list(node_t *head)
{
    node_t *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head->data);
        free(head);
    }
}
