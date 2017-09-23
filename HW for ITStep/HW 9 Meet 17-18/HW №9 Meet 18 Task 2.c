#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void reverse_part_arr(int[], int);
void sortfunc(int[], int, int);

int main()
{
	int radius[SIZE];
	int minrad = 0;
	int maxrad = 0;
	int indexmaxrad = 0;
	int indexminrad = 0;
	
	srand((unsigned)time(NULL));
	
	for (size_t i = 0; i < SIZE; ++i) 
	{								  
		radius[i] = rand();
		
		if (!minrad)
		{
			minrad = radius[i];
			maxrad = radius[i];
			continue;
		}
		else if (minrad > radius[i])
		{
			minrad = radius[i];
			indexminrad = i;
		}
		if (maxrad < radius[i])
		{
			maxrad = radius[i];
			indexmaxrad = i;
		}
	}

	if (radius[SIZE - 1] != minrad)
	{
		radius[indexmaxrad] = radius[SIZE - 1];
		radius[SIZE - 1] = maxrad;
	}
	else
	{
		indexminrad = indexmaxrad;
		radius[indexmaxrad] = radius[SIZE - 1];
		radius[SIZE - 1] = maxrad;
	}
	
	reverse_part_arr(radius, indexminrad);
	
	int sorted_elements = 1;

	while (sorted_elements != SIZE)
	{
		minrad = 0;
		
		for (size_t i = sorted_elements; i < SIZE; ++i)
		{
			if (!minrad)
			{
				minrad = radius[i];
				continue;
			}
			else if (minrad > radius[i])
			{
				minrad = radius[i];
				indexminrad = i;
			}
		}
		
		++sorted_elements;

		sortfunc(radius, indexminrad, sorted_elements);
	}
	int temp = 0;
	if (radius[SIZE - 2] > radius[SIZE - 1])
	{
		temp = radius[SIZE - 1];
		radius[SIZE - 1] = radius[SIZE - 2];
		radius[SIZE - 2] = temp;
	}
	for (size_t i = 0; i < SIZE; ++i)
	{
		printf_s("%d\n", radius[i]);
	}
	return 0;
}

void reverse_part_arr(int arr[], int indexminrad)
{
	int leftpart = 0;
	int rightpart = indexminrad;
	while (leftpart < rightpart)
	{
		int temp = arr[leftpart];
		arr[leftpart] = arr[rightpart];
		arr[rightpart] = temp;
		++leftpart;
		--rightpart;
	}
}

void sortfunc(int arr[], int indexminrad, int sorted_elements)
{
	reverse_part_arr(arr, indexminrad - 1);
	reverse_part_arr(arr, indexminrad);
	reverse_part_arr(arr, sorted_elements - 1);
	reverse_part_arr(arr, sorted_elements - 2);
}