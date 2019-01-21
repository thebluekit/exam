//3. В текстовом файле строки, не превышающие 80 символов. 
//Вывести все строки, которые начинаются с определенной подстроки
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define SIZE 80

int main(int argc, char **argv)
{
	FILE *f = fopen(argv[1],"r");
	if (f == NULL)
		return -1;

	FILE *fo = fopen(argv[2],"w");
	if (fo == NULL)
		return -1;

	char *stroka = (char *)malloc(SIZE * sizeof(char));
	fgets(stroka, SIZE, f);
	int n = strlen(stroka) - 1;
	int kol = 0;
	char *str = (char *)malloc(SIZE * sizeof(char));
	printf("%s", stroka);
	while (!feof(f))
	{
		fgets(str, SIZE, f);
		printf("%s", str);
		if (!strncmp(str, stroka, n))
		{
			fputs(str, fo);
			printf("%s", "OK");
		}
	}
	printf("\n%d", n);


	return 0;
}