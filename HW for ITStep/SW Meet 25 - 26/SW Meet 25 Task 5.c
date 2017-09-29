#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *parr = arr;
	int count = 0;

	for (; parr <= &arr[4]; ++parr)
	{
		++count;
	}

	printf_s("Array -");
	for (int i = 0; i < 5; ++i)
	{
		printf_s(" %d", arr[i]);
	}
	printf_s("\nAmount of elements - %d\n", count);
	
	return 0;
}