#include "sort.h"

/**
 * lomuto_partition - function that partitions an array using Lomuto scheme
 * @array: array to be sorted
 * @low: first index
 * @high: last index
 * @size: size of the array
 *
 * Return: index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, swap, i, j;

    pivot = array[high]; /* pivot */
    i = low - 1; /* index of smaller element */

    for (j = low; j <= high - 1; j++) /* loop throught elements for patition */
    {
        if (array[j] < pivot) /* if current element < pivot */
        {
            i++;
            if (i != j) /* swap smaller with current element */
            {
                swap = array[i];
                array[i] = array[j];
                array[j] = swap;
                print_array(array, size);
            }
        }
    }

    /* swap pivot element with the element with the element (i+1) */
    if (i + 1 != high) 
    {
        swap = array[i + 1];
        array[i + 1] = array[high];
        array[high] = swap;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quickSort - Recursive function performs quick sort
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: Nothing(SUCCESS)
 */
void quickSort(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size); /* patition array using Lomuto */

        /** 
         * sorting elements separately 
         * before and after partition
         */
        
        quickSort(array, low, pivot - 1, size);
        quickSort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Function that sort on an array of integers
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing (SUCCESS)
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quickSort(array, 0, size - 1, size);
}
