#include <stdio.h>

int main()
{
	int months[12] = { 0 };
	int rangeinitial = 0;
	int rangefinite = 0;
	int profmax = 0;
	int profmin = 0;
	for (int i = 0; i < 12; ++i)
	{
		printf_s("Month number %d - profit equal:", i + 1);
		scanf_s("%d", &months[i]);
	}
		puts("Range begins.");
		scanf_s("%d", &rangeinitial);
		puts("Range ends.");
		scanf_s("%d", &rangefinite); 
	for (; rangeinitial < rangefinite; ++rangeinitial)
	{
		if (!profmax)
		{
			profmax = months[rangeinitial - 1];
			profmin = months[rangeinitial - 1];
		}
		else if (months[rangeinitial] > profmax)
		{
			profmax = months[rangeinitial - 1];
		}
		if (months[rangeinitial - 1] < profmin)
		{
			profmin = rangeinitial;
		}
	}
	printf_s("%d - max profit\n" 
			"%d - min profit.\n", profmax, profmin);

	return 0;
}