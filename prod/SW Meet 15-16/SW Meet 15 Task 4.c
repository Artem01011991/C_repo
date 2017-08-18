#include <stdio.h>

int main()
{
	int year[12] = { 0 };
	int maxprof = 0;
	int minprof = 0;
	for (int i = 0; i < 12; ++i)
	{
		printf_s("Enter profit for %d month:", i + 1);
		scanf_s("%d", &year[i]);
		if (i && year[maxprof] < year[i])
		{
			maxprof = i;
		}
		if (i && year[minprof] > year[i])
		{
			minprof = i;
		}
	}
	printf_s("%d month - max profit %d month - min profit\n", maxprof + 1, minprof + 1);

	return 0;
}