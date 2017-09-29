#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_elem(int, int[], int);

int main()
{
	srand((unsigned)time(NULL));

	int M;
	int N;

	puts("Enter amount of elements for first array:");
	scanf_s("%d", &M);
	puts("Enter amount of elements for second array:");
	scanf_s("%d", &N);

	int *pAM = (int*)calloc(M, sizeof(int));
	int *pBN = (int*)calloc(N, sizeof(int));

	printf_s("Array1 - ");
	for (int i = 0; i < M; ++i)
	{
		pAM[i] = rand() % 10 + 1;
		printf_s("%d ", pAM[i]);
	}
	puts("");
	printf_s("Array2 - ");
	for (int i = 0; i < N; ++i)
	{
		pBN[i] = rand() % 10 + 1;
		printf_s("%d ", pBN[i]);
	}
	puts("");

	int count_elem = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (pAM[i] == pBN[j] && check_elem(pAM[i], pAM, i))
			{
				++count_elem;
				break;
			}
		}
	}

	int *pthird = (int*)calloc(count_elem, sizeof(int));

	printf_s("Array3 - ");
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (pAM[i] == pBN[j] && check_elem(pAM[i], pAM, i))
			{
				pthird[count_elem] = pAM[i];
				printf_s("%d ", pthird[count_elem--]);
				break;
			}
		}
	}
	puts("");


	return 0;
}

int check_elem(int elem, int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == elem)
			return 0;
	}
	return 1;
}