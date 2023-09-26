#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* counting_sort - Sorts array of integers in ascending
* order using Counting Sort
* @array: array to be sorted
* @size: size of the array
* Return: Nothing (SUCCESS)
*/
void counting_sort(int *array, size_t size)
{
	int max = 0;
	int *count_array, *output_array;
	size_t i;

	if (!array || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	count_array = malloc(sizeof(int) * (max + 1));
	output_array = malloc(sizeof(int) * size);
	if (!count_array || !output_array)
	{
		free(count_array);
		free(output_array);
		return;
	}
	for (i = 0; i <= (size_t)max; i++)
	count_array[i] = 0;
	for (i = 0; i < size; i++)
	count_array[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
	count_array[i] += count_array[i - 1];
	/*Addition;
	print_array(count_array, max + 1);
	for (i = size - 1; i < size; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
	array[i] = output_array[i];
	free(count_array);
	free(output_array);
}
