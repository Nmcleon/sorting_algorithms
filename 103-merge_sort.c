#include "sort.h"
#include <math.h>

/**
 * copyArray - copy the content of A to B
 * @array: array
 * @ibegin: beginning of the array
 * @iend: end of the array
 * @merge_array: work array
 */
void copyArray(int *array, int ibegin, int iend, int *merge_array)
{
	int i;

	for (i = ibegin; i < iend; i++)
		merge_array[i] = array[i];
}

/**
 * TopDownMerge - merge the sorted arrays
 * @mergeArray: resulting arrays sorted and merged
 * @ibegin: beginning index of the array
 * @imiddle: middle index of the array
 * @iend: the end of the array
 * @array: the array sorted
 */
void TopDownMerge(int *mergeArray, int ibegin, int imiddle,
				  int iend, int *array)
{
	int i = ibegin, j = imiddle, k;

	printf("Merging...\n");

	for (k = ibegin; k < iend; k++)
	{
		if (i < imiddle && (j >= iend || array[i] <= array[j]))
		{
			mergeArray[k] = array[i];
			i++;
		}
		else
		{
			mergeArray[k] = array[j];
			j++;
		}
	}
	printf("[left]: ");
	for (k = ibegin; k < imiddle - 1; k++)
		printf("%d, ", array[k]);
	printf("%d\n", array[imiddle - 1]);
	printf("[right]: ");
	for (k = imiddle; k < iend - 1; k++)
		printf("%d, ", array[k]);
	printf("%d\n", array[iend - 1]);
	printf("[Done]: ");
	for (k = ibegin; k < iend - 1; k++)
		printf("%d, ", mergeArray[k]);
	printf("%d\n", mergeArray[iend - 1]);
}

/**
 * TopDownSplitMerge - recusive function that split the array and sort it
 * @mergeArray: array to sort the the
 * @ibegin: beginning index of the array to sort
 * @iend: end index
 * @array: array sorted
 */

void TopDownSplitMerge(int *mergeArray, int ibegin, int iend, int *array)
{
	int imiddle;

	if (iend - ibegin <= 1)
		return;
	imiddle = round((iend + ibegin) / 2);

	TopDownSplitMerge(array, ibegin, imiddle, mergeArray);

	TopDownSplitMerge(array, imiddle, iend, mergeArray);

	TopDownMerge(mergeArray, ibegin, imiddle, iend, array);
}

/**
 * merge_sort - function that sorts an array of integer in ascending order
 * @array: array list
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *merge_array;

	if (!array || size <= 1)
		return;
	merge_array = malloc(size * sizeof(int));
	if (merge_array == NULL)
		return;
	copyArray(array, 0, size, merge_array);
	TopDownSplitMerge(array, 0, size, merge_array);
	free(merge_array);
}
