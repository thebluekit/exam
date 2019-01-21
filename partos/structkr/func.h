#include <stdio.h>

typedef struct city city_t;

struct city
{
	char *city;
	char *region;
	char *area;
	int population;
	int year;
	
	city_t *next;
};

city_t *create_list(city_t *head, FILE *f_in);

void print_years(city_t *head, FILE *f_out);

void free_list(city_t *head);