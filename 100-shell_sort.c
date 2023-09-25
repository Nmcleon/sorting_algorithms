#include "sort.h"

/**
  * shell_sort - Sorts array of integers in ascending order using Shell
  * sort algorithm with Knuth sequence.
  * @array: array to be sorted.
  * @size: size of the array.
  * Return: Nothing (SUCCESS)
  */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, gap = 1;
	int temp;

	if (!array || size < 2)
		return;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap; j -= gap)
			{
				if (array[j - gap] < temp)
					break;
				/*if (array[j] != array[j - gap])*/
				array[j] = array[j - gap];
			}
			/*if (array[j] != temp)*/
			array[j] = temp;

		}
		print_array(array, size);
	}
}
