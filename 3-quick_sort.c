#include "sort.h"

/**
 * lomuto_partition - function that petitions an array using Lomuto scheme
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

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap = array[i];
                array[i] = array[j];
                array[j] = swap;
                print_array(array, size);
            }
        }
    }

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
 * quick_sort - Recursive function performs quick sort
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: Nothing(SUCCESS)
 */
void quick_sort(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);

        /** 
         * sorting elements separately 
         * before and after partition
         */
        
        quick_sort(array, low, pivot - 1, size);
        quick_sort(array, pivot + 1, high, size);
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

    quick_sort(array, 0, size - 1, size);
}
