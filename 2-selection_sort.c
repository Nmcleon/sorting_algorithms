#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * Return: Nothing (SUCCESS)
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			array[i] = array[i] + array[min_index];
			array[min_index] = array[i] - array[min_index];
			array[i] = array[i] - array[min_index];
			print_array(array, size);
		}
	}
}
