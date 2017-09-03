#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	int arr[20] = { 0 };
	int arrmax = 0;
	int arrmin = 0;
	for (int i = 0; i < 20; ++i)
	{
		arr[i] = rand();
		if (!arrmax)
		{
			arrmax = arr[i];
			arrmin = arr[i];
		}
		else if (arr[i] > arrmax)
		{
			arrmax = arr[i];
		}
		if (arr[i] < arrmin)
		{
			arrmin = arr[i];
		}
		printf_s("%d\n", arr[i]);
	}
	printf_s("%d - max\n"
		"%d - min\n", arrmax, arrmin);

	return 0;
}
