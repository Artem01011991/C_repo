#include <stdio.h>
#include <stdlib.h>

int even_opt(int[], int);
int odd_opt(int[], int);

int main()
{
	int M = 10;

	/*puts("Type in elements count:");
	scanf_s("%d", &M);*/

	int *pAM = (int*)calloc(M, sizeof(int));

	puts("Type in data for this array:");
	for (int i = 0; i < M; ++i)
	{
		pAM[i] = rand() % 10 + 1;
		printf_s("%d ", pAM[i]);
		/*scanf_s("%d", &pAM[i]);*/
	}

	enum
	{
		EVEN = 1, ODD
	} options;

	puts("Choose which data you would like to delete:\n"
		"1.Even elements\n"
		"2.Odd elements");
	scanf_s("%d", &options);

	switch (options)
	{
	case EVEN:
		int new_size1 = even_opt(pAM, M);
		for (int i = 0; i < new_size1; ++i)
		{
			printf_s("%d", pAM[i]);
		}
		break;
	case ODD:
		int new_size2 = odd_opt(pAM, M);
		for (int i = 0; i < new_size2; ++i)
		{
			printf_s("%d", pAM[i]);
		}
		break;
	}

	free(pAM);

	return 0;
}

int even_opt(int arr[], int size)
{
	int *temp_arr = (int*)calloc(size, sizeof(int));
	int elem_count = 0;

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] % 2 != 0)
		{
			*temp_arr = arr[i];
			++temp_arr;
			++elem_count;
		}
	}
	free(arr);
	arr = (int*)calloc(elem_count, sizeof(int));

	for (int i = 0; i < elem_count; ++i)
	{
		--temp_arr;
		arr[i] = *temp_arr;
	}

	free(temp_arr);

	return elem_count;
}

int odd_opt(int arr[], int size)
{
	int *temp_arr = (int*)calloc(size, sizeof(int));
	int elem_count = 0;

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] % 2 == 0)
		{
			*temp_arr = arr[i];
			++temp_arr;
			++elem_count;
		}
	}
	
	arr = (int*)realloc(arr, sizeof(int));

	for (int i = 0; i < elem_count; ++i)
	{
		--temp_arr;
		arr[i] = *temp_arr;
	}

	free(temp_arr);

	return elem_count;
}