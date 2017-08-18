#include <stdio.h>

int main()
{
	int farr5[5] = {0, -1, 2, -1, 0};
	int sarr5[5] = {1, 0, -1, 2, -2};
	int arr10[10] = { 0 };
	int arr10size = 0;

	enum Mode
	{
		MORE = 1, ZERO, FEWER
	};
	enum Mode choicemode = MORE;
 	for (; choicemode <= FEWER; ++choicemode)
	{
		switch (choicemode)
		{
		case MORE:
			for (int i = 0; i < 5; ++i)
			{
				if (farr5[i] > 0)	
				{
					arr10[arr10size] = farr5[i];
					++arr10size;
				}
				if (sarr5[i] > 0)
				{
					arr10[arr10size] = sarr5[i];
					++arr10size;
				}
			}
			break;
		case ZERO:
			for (int i = 0; i < 5; ++i)
			{
				if (farr5[i] == 0)
				{
					arr10[arr10size] = farr5[i];
					++arr10size;
				}
				if (sarr5[i] == 0)
				{
					arr10[arr10size] = sarr5[i];
					++arr10size;
				}
			}
			break;
		case FEWER:
			for (int i = 0; i < 5; ++i)
			{
				if (farr5[i] < 0)
				{
					arr10[arr10size] = farr5[i];
					++arr10size;
				}
				if (sarr5[i] < 0)
				{
					arr10[arr10size] = sarr5[i];
					++arr10size;
				}
			}
			break;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		printf_s("%d\n", arr10[i]);
	}

	return 0;
}