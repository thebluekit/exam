#include "list.h"

/**
 * @brief Функция добавления нового элемента в список
 * @param head - указатель на "голову" списка
 * @param data - бестиповой указатель на данные, которые необходимо записать
 * @return возвращает новую "голову" списка
 */
node_t *addnode(node_t *head, void *data)
{
    node_t *tmp = malloc(sizeof(node_t));
    if (!tmp)
        return NULL;
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

/**
 * @brief Функция освобождения пямяти для списка
 * @param head - указатель на "голову" списка
 */
void free_list(node_t *head)
{
    node_t *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head->data);
        free(head);
    }
}

/**
 * @brief Функция удаляет из списка все элменты, большие 10
 * @param head - указатель на "голову" списка
 * @return возвращает новую "голову" списка
 */
node_t *del_more_than_10(node_t **head)
{
    node_t *prev = NULL;
    int end = 0;
    if (head == NULL)
        return NULL;

    for (node_t *tmp = *head; tmp && !end; prev = tmp, tmp = tmp->next)
        if (*((int*)tmp->data) > 10)
        {
            //Если элемент в начале списка
            if (tmp == *head)
                *head = tmp->next;
            else
            {
                //Если элемент в конце списка
                if (tmp->next == NULL)
                {
                    prev->next = NULL;
                    free(tmp);
                    end = 1;
                }
                //Если элемент в середине списка
                else
                {
                    prev->next = tmp->next;
                    free(tmp);
                    tmp = prev;
                }
            }
        }

    return *head;
}
