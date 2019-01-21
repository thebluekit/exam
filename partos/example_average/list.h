#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node
{
    void *data;
    struct node *next;
};
typedef struct node node;

node* initlist();
int addnode(node **head, void *data);
void printlist(node *head);
void freelist(node **head);
float listsum(node *head);
int listcount(node *head);

#endif // LIST_H
