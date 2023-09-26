#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *first, listint_t *second)
{
    listint_t *i = first->prev;
    listint_t *j = second->next;

    if (i)
        i->next = second;
    else
        *list = second;

    if (j)
        j->prev = first;

    first->prev = second;
    second->next = first;
    first->next = j;
    second->prev = i;
    if (j == NULL)
        return;
    j->prev = first;

    print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                     using the Cocktail Shaker Sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped;

    if (!list || !(*list) || !(*list)->next)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        current = current->prev;

        while (current->prev != NULL)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
            }
            else
            {
                current = current->prev;
            }
        }
    } while (swapped);
}
