#include <stdio.h>

int main()
{
	int arr10[10] =
	{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	};
	int farr5[5] = { 0 };
	int sarr5[5] = { 0 };

	for (int i = 0; i < 10; ++i)
	{
		if (i == 0 || i % 2 == 0)
		{
			farr5[(int)(i / 2)] = arr10[i];
		}
		else
		{
			sarr5[(int)(i * 0.5)] = arr10[i];
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		printf_s("%d %d\n", farr5[i], sarr5[i]);
	}

	return 0;
}