#include <stdio.h>
#define SIZE 10

int main()
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		printf_s("Enter %d element of array:", i + 1);
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] == 0)
		{
			for (int n = i; n < SIZE; ++n)
			{
				if (n == SIZE - 1)
				{
					arr[n] = -1;
					break;
				}
				arr[n] = arr[n + 1];
			}
			--i;
		}
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf_s("%d\n", arr[i]);
	}

	return 0;
}