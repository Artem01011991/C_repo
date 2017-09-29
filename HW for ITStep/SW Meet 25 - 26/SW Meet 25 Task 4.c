#include <stdio.h>

int main()
{
	int num1;
	int num2;
	int *pnum1 = &num1;
	int *pnum2 = &num2;

	puts("Enter first number:");
	scanf_s("%d", pnum1);
	puts("Enter second number:");
	scanf_s("%d", pnum2);

	enum 
	{
		INC = 1, DIC, MUL, DIV
	} actions;
	puts("Choose an action:\n"
		"1. For addition.\n"
		"2. For subtration.\n"
		"3. For multiplication.\n"
		"4. For divition.");
	scanf_s("%d", &actions);

	switch (actions)
	{
	case INC:
		printf_s("%d", *pnum1 + *pnum2);
		break;
	case DIC:
		printf_s("%d", *pnum1 - *pnum2);
		break;
	case MUL:
		printf_s("%d", *pnum1 * *pnum2);
		break;
	case DIV:
		printf_s("%.1f\n", (double)*pnum1 / (double)*pnum2);
	}

	return 0;
}