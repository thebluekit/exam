#include "list.h"

node *addnode(node *head, void *data)
{
    node *tmp = malloc(sizeof(node));
    if (!tmp)
        return NULL;
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

float listsum(node *head)
{
    float sum = 0;
    for (node *tmp = head; tmp->next; tmp = tmp->next)
        sum += *((int*)tmp->data);

    return sum;
}

int listcount(node *head)
{
    int count = 0;
    for (node *tmp = head; tmp->next; tmp = tmp->next)
        count ++;

    return count;
}

void freelist(node *head)
{
    node *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head->data);
        free(head);
    }
}
