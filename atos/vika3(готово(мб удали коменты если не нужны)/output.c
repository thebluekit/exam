#include "output.h"

/**
 * @brief Функция вывода целых чисел из списка в файл
 * @param f - указаталь на файл
 * @param head - указатель на "голову" списка
 */
void out_list(FILE *f, node_t *head)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        fprintf(f, "%d ", *((int*)tmp->data));
}
