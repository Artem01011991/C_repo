#include <stdio.h>

int main()
{
	int num1 = 20;
	int num2 = 30;
	int *pnum1 = &num1;
	int *pnum2 = &num2;

	printf_s("Before: %d-num1 %d-num2\n", *pnum1, *pnum2);

	*pnum1 += *pnum2;
	*pnum2 = *pnum1 - *pnum2;
	*pnum1 -= *pnum2;

	printf_s("After: %d-num1 %d-num2\n", *pnum1, *pnum2);

	return 0;
}