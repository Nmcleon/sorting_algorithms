#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
* counting_sort - Sorts array of integers in ascending order
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
		return;
	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = malloc(sizeof(int) * (max + 1));
	output_array = malloc(sizeof(int) * size);
	if (!count_array || !output_array)
	{
		free(count_array);
		free(output_array);
		return;
	}
	/* Initialize count_array elements to zero */
	for (i = 0; i <= (size_t)max; i++)
		count_array[i] = 0;
	/* Count appearance of each element */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	/* Calculate total counts */
	for (i = 1; i <= (size_t)max; i++)
		count_array[i] += count_array[i - 1];
	/* Prints counting array */
	print_array(count_array, max + 1);
	/* Rearrange the elements */
	for (i = size - 1; i < size; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(count_array);
	free(output_array);
}
