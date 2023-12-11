#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - this function searches for a target in a list
 * @array: pointer to first item in array
 * @size: number of elements in array
 * @value: The target value searched for
 * Return: returns an integer
 */

int linear_search(int *array, size_t size, int value)
{
	int i;

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (*(array + i) == value)
		{
			return (i);
		}
	}
	return (-1);
}
