#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *node, *next_node, *ptr;

    if (!list || !(*list))
        return;

    node = (*list)->next;
    while (node)
    {
        next_node = node->next;
        while (node->prev && node->prev->n > node->n)
        {
            if (node->next)
                node->next->prev = node->prev;
            if (node->prev)
                node->prev->next = node->next;
            node->next = node->prev;
            node->prev = node->prev->prev;

            if (node->prev == NULL)
                *list = node;
            else
                node->prev->next = node;

            ptr = (*list);
            while (ptr->next)
            {
                ptr = ptr->next;
            }
        }
        node = next_node;
    }
}
