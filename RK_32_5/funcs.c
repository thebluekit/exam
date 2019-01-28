#include "funcs.h"

node_t *create_node(char *surname_in, char *name_in)
{
    node_t *nd = malloc(sizeof(node_t));
    char *name_data = calloc(NAME_BUFF, sizeof(char));
    char *surname_data = calloc(NAME_BUFF, sizeof(char));

    for (int i = 0; name_in[i] != 0; i++)
        name_data[i] = name_in[i];

    for (int i = 0; surname_in[i] != 0; i++)
        surname_data[i] = surname_in[i];

    nd->name = name_data;
    nd->surname = surname_data;
    nd->next = NULL;    
    return nd;
}

void gluing(node_t* head)
{
    for (; head; head=head->next)
    {
        int i, j = 0;
        head->surname = realloc(head->surname, 140*sizeof(char));
        i = strlen(head->surname);
        head->surname[strlen(head->surname)] = '!';

        for (; head->name[j] != 0; i++, j++)
            head->surname[i] = head->name[j];
        head->surname[i] = 0;
        free(head->name);
        head->name = NULL;
    }
}


node_t *load_data(FILE *f)
{
    node_t *head = NULL;
    node_t *last = NULL;
    char name[NAME_BUFF];
    char surname[NAME_BUFF];
    while (fscanf(f, "%s\n%s", surname, name)!= EOF)
    {
        node_t *tmp = create_node(surname, name);
        if (head == NULL)
        {
            head = tmp;
            last = tmp;
        }
        else
        {
            last->next = tmp;
            last = last->next;
        }        
    }
    return head;
}

void delete_node(node_t* head, char* surname)
{
    for (; head->next; head=head->next)
    {
        if (strcmp(surname, head->surname))
        {
            free(head->next);
            head->next = head->next->next;
            break;
        }
    }
}


void print_data(node_t* head)
{
    for (; head; head=head->next)
    {
        printf("%s %s\n", head->name, head->surname);
    }
}

void print_data_2(node_t* head)
{
    for (; head; head=head->next)
    {
        printf("%s\n", head->surname);
    }
}


// void freelist(node_t *head)
// {
//    for (node *tmp = head; tmp->next; tmp = tmp->next)
//    {
//        free(tmp->name);
//        free(tmp->surname);
//    }
// }

void free_list(node_t* head)
{
    for (; head; head=head->next)
    {
        free(head->name);
        free(head->surname);
    }
}