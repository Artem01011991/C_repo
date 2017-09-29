#include <stdio.h>

int main()
{
	int num1 = 11;
	int num2 = 20;

	int *pnum1 = &num1;
	int *pnum2 = &num2;

	if (*pnum1 > *pnum2)
	{
		printf_s("%d\n", *pnum1);
	}
	else
	{
		printf_s("%d\n", *pnum2);
	}

	return 0;
}