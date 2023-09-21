#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *ptr;

    if (!list || !(*list))
        return;

    current = (*list)->next;
    while (current)
    {
        next_node = current->next;
        while (current->prev && current->prev->n > current->n)
        {
            if (current->next)
                current->next->prev = current->prev;
            if (current->prev)
                current->prev->next = current->next;
            current->next = current->prev;
            current->prev = current->prev->prev;

            if (current->prev == NULL)
                *list = current;
            else
                current->prev->next = current;

            ptr = (*list);
            while (ptr->prev && ptr->n < ptr->prev->n)
            {
                int temp = ptr->n;
                ptr->n = ptr->prev->n;
                ptr->prev->n = temp;
                ptr = ptr->prev;
            }
        }
        current = next_node;
    }
}
