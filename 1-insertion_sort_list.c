#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *sorted, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    sorted = NULL;
    current = *list;

    while (current)
    {
        next = current->next;

        if (sorted == NULL || sorted->n >= current->n)
        {
            current->next = sorted;
            current->prev = NULL;

            if (sorted)
                sorted->prev = current;

            sorted = current;
        }
        else
        {
            listint_t *temp = sorted;

            while (temp->next && temp->next->n < current->n)
                temp = temp->next;

            current->next = temp->next;

            if (temp->next)
                temp->next->prev = current;

            temp->next = current;
            current->prev = temp;
        }

        *list = sorted;
        current = next;
        print_list(*list);
    }
}
