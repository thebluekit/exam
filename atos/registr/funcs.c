#include "funcs.h"

//создаст узел и вернет его адрес
node_t *init(char *word, int n)
{
	node_t *node = malloc(sizeof(node_t));
	if (node)
	{
		memcpy(node->word, word, sizeof(char) * n);
		node->next = NULL;
	}
	return node;
}

//добавляет узел в начало списка
//вернет новую голову
node_t *add(node_t *head, node_t *node)
{
	node->next = head; 
	return node;
}

//показывает содержимое списка
void show_list(node_t *head)
{
	if (head)
		for (node_t *tmp = head; tmp; tmp = tmp->next)
			printf("%s ", tmp->word);
	else 
		printf("Empty list");
}

//освобождает список
void free_list(node_t **head)
{
	for (node_t *tmp = *head; tmp->next; *head = tmp->next)
		free(tmp);
}

//удаляет узел
node_t *delete_node(node_t *head, node_t *del)
{
	if (head == del)
		head = head->next;
	else 
	{
		node_t *tmp = head;
		for (; tmp->next != del; tmp = tmp->next);
		tmp->next = del->next;	
		//printf("tmp, del %s %s\n", tmp->word, del->word);
	}
	
	free(del);
	del = NULL;
	
	return head;
}

node_t *do_task(node_t *head)
{
	for (node_t *tmp = head; tmp; tmp = tmp->next)
		if (is_val(tmp) == 1)
			head = delete_node(head, tmp);
		
	return head;
}

//проверка на удаление слова
int is_val(node_t *node)
{
	if ((node->word)[0] >= 'A' && (node->word)[0] <= 'Z')
		return 1;
	return 0;
}