#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#define SIZE 10

void func_sort(int[], int, int[], int);

int main()
{
	int icq_list[SIZE] = { 9,7,4,5,3,7,2,4,6,10 };
	int phone_list[SIZE] = { 7,8,3,1,2,3,5,4,3,2 };
	enum Menu
	{
		SORTICQ = 1, SORTPHONE, DISPLAY, EXIT
	};

	enum Menu choice_menu = SORTICQ;
	while (1)
	{
		system("CLS");
		puts("Choose an option:\n"
			"1.ICQ sort\n"
			"2.Phone sort\n"
			"3.Show the users list\n"
			"4.Exit");
		do
		{
			scanf_s("%d", &choice_menu);
		} while (choice_menu < 1 || choice_menu > 4);
		switch (choice_menu)
		{
		case SORTICQ:
			func_sort(icq_list, SIZE, phone_list, SIZE);
			break;
		case SORTPHONE:
			func_sort(phone_list, SIZE, icq_list, SIZE);
			break;
		case DISPLAY:
			printf_s("ICQ\tPHONE\n");
			for (size_t i = 0; i < SIZE; ++i)
			{
				printf_s("%d\t%d\n", icq_list[i], phone_list[i]);
			}
			puts("\nPress Enter");
			getchar();
			getchar();
			break;
		case EXIT:
			return 0;
		}
	}
	return 0;
}

void func_sort(int arr1[], int size1, int arr2[], int size2)
{
	_Bool end_sort = true;
	while (end_sort)
	{
		end_sort = false;
		for (size_t i = 0; i + 1 < size1; ++i)
		{
			int temp = 0;
			if (arr1[i] > arr1[i + 1])
			{
				temp = arr1[i];
				arr1[i] = arr1[i + 1];
				arr1[i + 1] = temp;
				temp = arr2[i];
				arr2[i] = arr2[i + 1];
				arr2[i + 1] = temp;
				end_sort = true;
			}
		}
	}
}