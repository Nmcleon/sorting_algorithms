#include "sort.h"

/**
 * lomuto_partition - Function to partition the array using Lomuto scheme
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, swap, i, j;

    pivot = array[high];
    i = low - 1;

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
 * quick_sort_recursive - Recursive function to perform quick sort
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Function to perform quick sort on an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
