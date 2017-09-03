#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

void func_sort(int[], int);

int main()
{
	int arr[SIZE] = { 9,7,4,5,3,7,2,4,6,10 };
	func_sort(arr, SIZE);

	for (size_t i = 0; i < SIZE; ++i)
	{
		printf_s("%d\n", arr[i]);
	}

	return 0;
}

void func_sort(int arr1[], int size1)
{
	_Bool end_sort = true;
	while (end_sort)
	{
		end_sort = false;
		for (size_t i = 0; i + 1 < size1; ++i)
		{
			int temp = 0;
			if (arr1[i] > arr1[i + 1])
			{
				temp = arr1[i];
				arr1[i] = arr1[i + 1];
				arr1[i + 1] = temp;
				end_sort = true;
			}
		}
	}
}