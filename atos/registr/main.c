#include "funcs.h"

int main()
{
	FILE *file = fopen("test.txt", "r");
	node_t *head = NULL;
	char word[40];
	
	//создание списка
	int result = fscanf(file, "%s ", word); //заполнение головы 
	
 	while (result != EOF)
	{		
		node_t *node = init(word, sizeof(word));
		head = add(head, node);
		
		result = fscanf(file, "%s ", word);
	}
	fclose(file);

//Вывод
//---------------------------------
	printf("Before: ");
	show_list(head);
	
	head = do_task(head);
	
	printf("\nAfter: ");
	show_list(head); 
//---------------------------------
}
