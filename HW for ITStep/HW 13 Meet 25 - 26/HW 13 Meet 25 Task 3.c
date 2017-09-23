#include <stdio.h>

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 0 };
	int *p1 = &arr1[4];
	int *p2 = arr2;

	for (;p1 >= &arr1[0]; --p1, ++p2)
		*p2 = *p1;

	for(int i = 0; i < 5; ++i)
		printf_s("%d ", arr2[i]);


	return 0;
}