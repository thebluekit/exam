#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;
struct node
{
	char word[40];
	
	node_t *next;
};

//работа с узлом 
node_t *init(char *word, int n);
node_t *add(node_t *head, node_t *node);

//показать список
void show_list(node_t *head);

//освобождение 
node_t *delete_node(node_t *head, node_t *del);
void free_list(node_t **head);

//задание 
int is_val(node_t *node);
node_t *do_task(node_t *head);

#endif