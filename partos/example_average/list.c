#include "list.h"

node* initlist()
{
    node *tmp = malloc(sizeof(node));
    tmp->data = NULL;
    tmp->next = NULL;
    return tmp;
}

int addnode(node **head, void *data)
{
    node *tmp = malloc(sizeof(node));
    if (!tmp)
        return -1;
    tmp->data = data;
    tmp->next = *head;
    *head = tmp;
    return 0;
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

//void freelist(node **head)
//{
//    for (node *tmp = head; tmp->next; tmp = tmp->next)
//    {
//        free(tmp->data);



//    }



//}
