//2. В текстовом файле на первой строке размерность матрицы, далее - элементы. 
//Заполнить матрицу и сформировать одномерный массив, который содержит кол-во положительных четных чисел на каждой строке матрицы. 
//Ну и вывести это все
#include <stdio.h>
#include <malloc.h>

int razmer(FILE *f, int *n, int *m)
{
	int x;
	fscanf(f, "%d", n);
	fscanf(f, "%d", m);
	return 0;
}



int main(int argc, char **argv)
{
	int **mas;
	FILE *f = fopen(argv[1], "r");
	if (f == NULL)
		return -1;
	int n, m;
	razmer(f, &n, &m);
	printf("%d %d\n", n, m);

	mas = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		mas[i] = (int *)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++)
		{
			fscanf(f, "%d", &mas[i][j]);
		}
	}


	int *pmas = (int *)malloc(n * sizeof(int));
	int kol = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((mas[i][j] % 2) != 0)
				kol = kol + 1;
		}
		pmas[i] = kol;
		kol = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (j == (m - 1))
				printf("%d\n", mas[i][j]);
			else
				printf("%d ", mas[i][j]);
		}

	for (int i = 0; i < n; i++)
		printf("%d ", pmas[i]);

	FILE *fout = fopen(argv[2], "w");
	if (fout == NULL)
		return -1;
	for (int i = 0; i < n; i++)
	{
		fprintf(fout, "%d ", pmas[i]);
		free(mas[i]);
	}
	free(mas);
	free(pmas);




	return 0;
}