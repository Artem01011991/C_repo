#include <stdio.h>
#include <malloc.h>

int main()
{
	int arrsize = 0;
	int negativesum = 0;
	int *minelem = 0;
	int *maxelem = 0;
	int multievenelemen = 0;
	int *pfirstnegaelem = 0, *plastnegaelem = 0;
	int sumbetweenneg = 0;
	puts("Enter an array size.");
	scanf_s("%d", &arrsize);
	int *parr = (int*)malloc (sizeof(int) * arrsize);
	for (int i = 0; i < arrsize; ++i)
	{
		printf_s("Initialize %d element of the array: ", i + 1);
		scanf_s("%d", &parr[i]);
		if (parr[i] < 0)
		{
			if (!negativesum)
			{
				pfirstnegaelem = &parr[i];
			}
			++negativesum;
			plastnegaelem = &parr[i];
		}
		if (i % 2 == 0)
		{
			if (!multievenelemen)
			{
				multievenelemen = parr[i];
				continue;
			}
			multievenelemen *= parr[i];
		}
	}
	maxelem = &parr[0];
	minelem = &parr[0];
	for (int i = 0; i < arrsize; ++i)
	{
		if (*minelem > parr[i])
		{
			minelem = &parr[i];
		}
		if (*maxelem < parr[i])
		{
			maxelem = &parr[i];
		}
	}
	int multiple = 0;
	if (maxelem < minelem)
	{
		multiple = *(maxelem + 1);
		for (; (maxelem + 2) < minelem; ++maxelem)
		{
			multiple *= *(maxelem + 2);
		}
	}
	else
	{
		multiple = *(maxelem - 1);
		for (; (maxelem - 2) > minelem; --maxelem)
		{
			multiple *= *(maxelem - 2);
		}
	}
	for (; (pfirstnegaelem + 1) < plastnegaelem; ++pfirstnegaelem)
	{
		sumbetweenneg += *(pfirstnegaelem + 1);
	}
	printf_s("%d - multiplication the elements between min and max.\n"
			"%d - multiplication the even elements.\n"
			"%d - sum between first and last.\n", multiple, multievenelemen, sumbetweenneg);
	free(parr);
	
	return 0;
}