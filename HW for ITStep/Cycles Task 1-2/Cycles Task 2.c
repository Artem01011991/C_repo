#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int purchase(int, char[][5][20], int*, int*);

int main()
{
	int profit = 0, customercost = 0;
	int *pprofit = &profit, *pcustcost = &customercost;
	char product[3][5][20] = {
		[0][0] = "Lollipops", "Icecreams", "Cakes", "Toys", "Alcohol",
		 [1][0] = "2", "4", "6", "10", "8",
		 [2][0] = "100", "100", "100", "100", "100"
	};
	enum Products
	{
		LOLIP = 1, ICECR, CAKE, TOY, ALC
	};
	enum Products choiceprod = LOLIP;
	while (puts("Have we a customer?(y/n)") || getchar() != 'n')
	{
		customercost = 0;
		system("cls");
		getchar();
		while (puts("Display the products list?(y/n)") || getchar() != 'n')
		{
			system("cls");
			puts("If purchase cost equal 100$ or more,customer will\n"
				"get a discount 10% for whole purchase.\n\n"
				"List of products:\n");
			for (int kinds = 0, num = 1; kinds < 5; ++kinds, ++num)
			{
				printf_s("%d. %s - %s$ amount in stock %s\n", num, product[0][kinds], product[1][kinds], product[2][kinds]);
			}
			scanf_s("%d", &choiceprod);
			switch (choiceprod)
			{
			case LOLIP:
				purchase(choiceprod, product, pprofit, pcustcost);
				break;
			case ICECR:
				purchase(choiceprod, product, pprofit, pcustcost);
				break;
			case CAKE:
				purchase(choiceprod, product, pprofit, pcustcost);
				break;
			case TOY:
				purchase(choiceprod, product, pprofit, pcustcost);
				break;
			case ALC:
				purchase(choiceprod, product, pprofit, pcustcost);
				break;
			}
		}
		system("cls");
		if (customercost >= 100)
		{
			printf_s("Cost of purchase with discount equal %d\n", customercost - ((customercost * 10) / 100));
			profit -= ((customercost * 10) / 100);
		}
		else
		{
			printf_s("Cost of purchase is %d\n", customercost);
		}
		getchar();
	}
	system("cls");
	printf_s("Profit for today is %d\n", profit);
	return 0;
}

int purchase(int kindprod, char arr[][5][20], int *prof, int *customcost)
{
	int amountprod = 0;
	do
	{
		puts("Enter products amount:");
		scanf_s("%d", &amountprod);
	} while (amountprod <= 0);
	if (amountprod > atoi(arr[2][kindprod - 1]))
	{
		puts("Store has not enough the products.");
		Sleep(2000);
		system("cls");
		getchar();
		return 0;
	}
	_itoa_s(atoi(arr[2][kindprod - 1]) - amountprod, arr[2][kindprod - 1], 20, 10);
	*customcost += (atoi(arr[1][kindprod - 1]) * amountprod);
	*prof += *customcost;
	system("cls");
	getchar();
	return 1;
}
