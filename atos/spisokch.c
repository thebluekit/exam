#include <stdio.h>
#include <stdlib.h>
 
typedef struct list_elem 
{	
	int index;
    struct list_elem *next; 
} listt;	

listt* add_elem (listt *last);	
void del_elem(void);
void print_list(void);	
listt *list; // начало списка

int main() 
{
	int N;
	scanf("%d",&N);	
	listt *end = NULL;	
	do
	{ // формирование списка
		end = add_elem(end);
		if(end == NULL)	
			break;
		N--;
	} 
	while(N > 0); 	
	printf("\nSpisok do:");
		print_list();		
	printf("\n\nSpisok posle:");
		del_elem();
		print_list(); 
 
	return 0;
} 

listt* add_elem (listt *last)
{
	listt *new;
	static int num = 1;
	new = (listt*)malloc(sizeof(listt));
	scanf("%d", &new->index);
	if(new->index == 0)
	{
		free(new);
		return NULL;
	}
	
	fflush(stdin);
	new->next = NULL;
		
	if(list == NULL)
		list = new;
	else
		last->next = new;
	num++;
	
	return new;
}

void print_list(void)
{
	listt *new = list;	
	
	while(new!=NULL)
	{
		printf("%3d", new->index); // содержимое поля index
		new = new->next;
	}
}

void del_elem(void)
{
	listt *new = list, *prev;
 
    while(new!=NULL)
	{
		if(new->index%2!=0)	
        {
			prev=new;		
			new = new->next;	
		}	
		else
		{
			if(new == list)
			{
				list = list->next;
				free(new);
				new=list;
			}
			else
			{
				prev->next = new->next;
				free(new);
				new = prev->next;
			}
		}
	}
}