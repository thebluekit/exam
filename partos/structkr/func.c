#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define SUCCESS 0
#define ERROR -1

city_t *create_list(city_t *head, FILE *f_in)
{	
	city_t *prev = NULL;
	
	while (!feof(f_in))
	{
		city_t *element = malloc(sizeof(city_t));
		if (!element)
			return NULL;
		
		element->city = malloc(128 * sizeof(char));
		element->region = malloc(128 * sizeof(char));
		element->area = malloc(128 * sizeof(char));
		fscanf(f_in, "%s", element->city);
		fscanf(f_in, "%s", element->region);
		fscanf(f_in, "%s", element->area);
		fscanf(f_in, "%d", &(element->population));
		fscanf(f_in, "%d", &(element->year));
		element->next = NULL;
		
		if (!prev)
		{
			head = element;
			prev = head;
		}
		else
		{
			prev->next = element;
			prev = element;
		}
	}
	
	return head;
}

void print_years(city_t *head, FILE *f_out)
{
	for(; head; head = head->next)
	{
		int age = 2018 - head->year;
		fprintf(f_out, "%s\n", head->city);
		fprintf(f_out, "%d\n", age);
	}
}

void free_list(city_t *head)
{
	city_t *next;
	for (; head; head = next)
	{
		next = head->next;
		free(head->city);
		free(head->region);
		free(head->area);
		free(head);
		
	}
}