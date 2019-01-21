#include "output.h"

void out_list(FILE *f, node_t *head)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        fprintf(f, "%d ", *((int*)tmp->data));
}
