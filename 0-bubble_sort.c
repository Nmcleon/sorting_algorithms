#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - A function for bubble sorting.
 * @array: The array to be sorted
 * @size: number of elements in array
 * Return: Nothing (SUCCESS)
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swap;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swap = 0; /* check if any swaps are made */

        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swap = 1;
                print_array(array, size); /* Print the array after each swap */
            }
        }
        if (swap == 0)
            break;
    }
}
