#include <stdio.h>

int main()
{
	int profarr[6] = { 0 };
	int profit = 0;
	for (int i = 0; i < 6; ++i)
	{
		printf_s("Enter profit for %d month:", i + 1);
		scanf_s("%d", &profarr[i]);
		profit += profarr[i];
	}
	printf_s("Profit for 6 months equal %d\n", profit);
	
	return 0;
}