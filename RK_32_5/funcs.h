#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_BUFF 70

typedef struct node node_t;
struct node
{
    char *name;
    char *surname;
    node_t *next;
};

node_t *create_node(char *surname_in, char *name_in);
node_t *load_data(FILE *f);
void print_data(node_t* head);
void gluing(node_t* head);
void print_data_2(node_t* head);
void delete_node(node_t* head, char* surname);
void free_list(node_t* head);