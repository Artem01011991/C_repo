#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int *pthird = (int*)calloc(N + M, sizeof(int));

	printf_s("Array1 - ");
	for (int i = 0; i < M; ++i)
	{
		pAM[i] = rand() % 100 + 1;
		printf_s("%d ", pAM[i]);
	}
	puts("");
	printf_s("Array2 - ");
	for (int i = 0; i < N; ++i)
	{
		pBN[i] = rand() % 100 + 1;
		printf_s("%d ", pBN[i]);
	}
	puts("");

	printf_s("Array3 - ");
	for (int i = 0; i < M; ++i, ++pthird)
	{
		*pthird = pAM[i];
		printf_s("%d ", *pthird);
	}
	for (int i = 0; i < N; ++i, ++pthird)
	{
		*pthird = pBN[i];
		printf_s("%d ", *pthird);
	}
	puts("");


	return 0;
}