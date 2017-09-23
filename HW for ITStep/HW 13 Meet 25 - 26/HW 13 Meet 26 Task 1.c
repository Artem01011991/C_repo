#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_elem(int, int[], int);

int main()
{
	srand((unsigned)time(NULL));

	int N;
	int M;

	puts("Enter count of elements for arr 1:");
	scanf_s("%d", &N);
	puts("Enter count of elements for arr 2:");
	scanf_s("%d", &M);
	puts("");

	int *pBN = (int*)calloc(N, sizeof(int));
	int *pAM = (int*)calloc(M, sizeof(int));

	printf_s("Array B : ");
	for (int i = 0; i < N; ++i) {
		pBN[i] = (rand() + i) % 10 + 1;
		printf_s("%d ", pBN[i]);
	}
	puts("\n");
	printf_s("Array A : ");
	for (int i = 0; i < M; ++i)
	{
		pAM[i] = (rand() + i) % 10 + 1;
		printf_s("%d ", pAM[i]);
	}

	int elem_count = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (pAM[i] == pBN[j])
				break;
			else if (N - 1 == j && check_elem(pAM[i], pAM, i))
				++elem_count;
		}
	}
	puts("\n");

	printf_s("Result : ");
	int *pthird = (int*)calloc(elem_count, sizeof(int));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (pAM[i] == pBN[j])
				break;
			else if (N - 1 == j && elem_count >= 0 && check_elem(pAM[i], pAM, i))
			{
				pthird[elem_count] = pAM[i];
				printf_s("%d ", pthird[elem_count--]);
			}
		}
	}
	puts("\n");

	return 0;
}

int check_elem(int elem, int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == elem)
		{
			return 0;
		}
	}
	return 1;
}