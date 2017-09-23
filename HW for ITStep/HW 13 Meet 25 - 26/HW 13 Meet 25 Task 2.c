#include <stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int *p = &arr[4];
	
	for (int i = 0; i != 5/2; --p, ++i)
	{
		int temp = *p;
		*p = arr[i];
		arr[i] = temp;
	}
	
	for(int i = 0; i < 5; ++i)
	printf_s("%d ", arr[i]);

	return 0;
}