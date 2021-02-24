#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*Se dă un tablou de N elemente aleatorii. Să se sorteze tabloul prin algoritmii Bubblesort,
Shellsort și Quicksort și să se compare timpul de execuție pentru cele 3 metode.*/

void afisare(int a[], int N)
{
	int i;
	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void rand_tablou(int a[], int N)
{
	time_t t;
	int i;
	srand((unsigned)time(&t));
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
}

void shell_sort(int a[], int N) 
{
	int h[3] = { 3,2,1 };
	int aux;
	int i, j, k, w;
	for (w = 0; w < 3; w++)
	{
		k = h[w];
		for (i = k; i < N; i++)
		{
			aux = a[i];
			j = i - k;
			while (j >= 0 && aux < a[j])
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = aux;
		}
	}
}
int main()
{
	int N;
	int a[5];
	N = 5;
	int opt;
	do
	{
		printf("1.Afisare tablou random\n");
		printf("2.Shell sort\n");
		printf("introduceti opt: ");
		scanf("%d",&opt);
		switch (opt)
		{

		case 1: 
			rand_tablou(a, N);
			afisare(a, N);
			break;
		case 2:
			rand_tablou(a, N);
			afisare(a, N);
			shell_sort(a, N);
			afisare(a, N);
		}
		
	} while (1);
	return 0;
	
}
