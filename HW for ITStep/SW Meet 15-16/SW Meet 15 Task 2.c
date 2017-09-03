#include <stdio.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 9; i > -1; --i)
	{
		printf_s("%d\t%d\n", arr[i], arr[-(i - 9)]);
	}

	return 0;
}