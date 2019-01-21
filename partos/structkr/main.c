//4.	Вывести возраст городов.

#include <stdio.h>
#include "func.h"

#define SUCCESS 0
#define ERROR -1

int main(int argc, char const *argv[])
{
	setbuf(stdout, NULL);
	FILE *in = fopen(argv[1], "r");
	if (!in)
		return ERROR;
	
	FILE *out = fopen(argv[2], "w");
	if (!out)
	{
		fclose(in);
		return ERROR;
	}
	
	city_t *head = NULL;
	head = create_list(head, in);

	print_years(head, out);
	
	free_list(head);
	fclose(in);
	fclose(out);
	
	return SUCCESS;
}