#include <stdio.h>
#include "search_algos.h"
#include <math.h>

/**
* jump_search - search for a number with increment by sqrt(size)
* @array: pointer to first element in array
* @size: size of the array
* @value: target value
* Return: returns an integer
*/

int jump_search(int *array, size_t size, int value)
{
	int i = 0, temp = 0, count = 0, increment = (int)(floor(sqrt(size)));

	if (!array)
		return (-1);
	while (array[i] < value && i < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		temp = i;
		i += increment;
	}
	printf("Value found between indexes [%d] and [%d]\n", temp, i);
	for (count = temp; count <= i && count < (int) size; count++)
	{
		printf("Value checked array[%d] = [%d]\n", count, array[count]);
		if (array[count] == value)
		{
			return (count);
		}
	}

	return (-1);
}
