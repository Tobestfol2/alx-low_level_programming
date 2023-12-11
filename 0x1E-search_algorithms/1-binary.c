#include <stdio.h>
#include "search_algos.h"

/**
* binary_search - This function uses binary search to find a target
* @array: pointer to array
* @size: size of the array
* @value: the target
* Return: returns an int
*/

int binary_search(int *array, size_t size, int value)
{
	int l = 0;
	int r = (int)size - 1;
	int mid;
	int count;

	while (array && l <= r)
	{
		printf("Searching in array: ");
		for (count = l; count <= r; count++)
		{
			if (count == r)
			{
				printf("%d\n", array[count]);
			}
			else
			{
				printf("%d, ", array[count]);
			}
		}
		mid = (l + r) / 2;
		if (array[mid] > value)
			r = mid - 1;
		else if (array[mid] < value)
			l = mid + 1;
		else
			return (mid);
	}
	return (-1);
}
