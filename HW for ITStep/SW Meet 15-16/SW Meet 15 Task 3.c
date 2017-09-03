#include <stdio.h>

int main()
{
	int sides[5] = { 0 };
	int perimeter = 0;
	for (int i = 0; i < 5; ++i)
	{
		printf_s("Enter %d angle length:", i + 1);
		scanf_s("%d", &sides[i]);
		perimeter += sides[i];
	}
	printf_s("Perimeter of pentagon equal %d\n", perimeter);

	return 0;
}