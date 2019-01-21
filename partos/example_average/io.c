#include "io.h"

void printlist(node *head)
{
    for (node *tmp = head; tmp->next; tmp = tmp->next)
        printf("%d ", *((int*)tmp->data));
}

void getlist(FILE *f, node **head)
{
    int num = 0;
    while (fscanf(f, "%d", &num) == 1)
    {
        int *tmp = malloc(sizeof(int));
        *tmp = num;
        addnode(head, tmp);
    }
}

void printlistgreater(node *head, float mean)
{
    for (node *tmp = head; tmp->next; tmp = tmp->next)
    {
        int num = *((int*)tmp->data);
        if ((float)num > mean)
            printf("%d ", num);
    }
}

