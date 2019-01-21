#include "input.h"

/**
 * @brief Функция заполняет список целыми числамии из файла
 * @param f - указатель на файл
 * @param head - указатель на "голову" списка
 */
void get_list(FILE *f, node_t **head)
{
    int num = 0;
    while (fscanf(f, "%d", &num) == 1)
    {
        int *tmp = malloc(sizeof(int));
        *tmp = num;
        *head = addnode(*head, tmp);
    }
}
