#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_elem(int, int, int[], int, int[], int);
void assign_elem(int*, int[], int, int, int[], int, int[]);

int main()
{
	srand((unsigned)time(NULL));

	int N;
	int M;

	puts("Enter count of elements for arrays:");
	scanf_s("%d", &N);
	M = N;

	int *pBN = (int*)calloc(N, sizeof(int));
	int *pAM = (int*)calloc(M, sizeof(int));

	printf_s("\nArray B: ");
	for (int i = 0; i < N; ++i) {
		pBN[i] = (rand() + i) % 10 + 1;
		printf_s("%d ", pBN[i]);
	}
	printf_s("\n\nArray A: ");
	for (int i = 0; i < M; ++i) {
		pAM[i] = (rand() + i) % 10 + 1;
		printf_s("%d ", pAM[i]);
	}

	int elem_count = 0;
	for (int i = 0, j = 0; i < M && j < N; ++i, ++j)
	{
		if (pAM[i] != pBN[j])
			elem_count += check_elem(pAM[i], pBN[j], pAM, i, pBN, j);
	}
	puts("\n");

	printf_s("Result: ");
	int *pthird = (int*)calloc(elem_count, sizeof(int));
	for (int i = 0, j = 0; i < M && j < N; ++i, ++j)
	{
		if (pAM[i] != pBN[j])
			assign_elem(&elem_count, pthird, pAM[i], pBN[j], pAM, i, pBN);
	}
	puts("\n");

	return 0;
}

int check_elem(int elem1, int elem2, int arr1[], int size1, int arr2[], int size2)
{
	int ret_elem = 2;

	for (int i = 0; i < size1; ++i)
	{
		if (arr1[i] == elem1 || arr2[i] == elem1)
		{
			--ret_elem;
			break;
		}
	}
	for (int i = 0; i < size2; ++i)
	{
		if (arr1[i] == elem2 || arr2[i] == elem2)
		{
			--ret_elem;
			break;
		}
	}

	return ret_elem;
}

void assign_elem(int *size_init_arr, int initialization_arr[], int elem1, int elem2, int arr1[], int size1, int arr2[])
{
	for (int i = 0; i < size1 + 1; ++i)
	{
		if (size1 == i)
		{
			printf_s("%d ", initialization_arr[*size_init_arr] = elem1);
			--(*size_init_arr);
			break;
		}
		else if (arr1[i] == elem1 || arr2[i] == elem1)
		{
			break;
		}
	}
	for (int i = 0; i < size1 + 1; ++i)
	{
		if (size1 == i)
		{
			printf_s("%d ", initialization_arr[*size_init_arr] = elem2);
			--(*size_init_arr);
			break;
		}
		else if (arr1[i] == elem2 || arr2[i] == elem2)
		{
			break;
		}
	}
}