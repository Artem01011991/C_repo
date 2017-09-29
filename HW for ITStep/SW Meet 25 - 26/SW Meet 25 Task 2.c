#include <stdio.h>

int main()
{
	int num;
	int *pnum = &num;

	scanf_s("%d", pnum);
	if (*pnum > 0)
	{
		printf_s("number sign is +\n");
	}
	else
	{
		printf_s("number sign is -\n");
	}


	return 0;
}