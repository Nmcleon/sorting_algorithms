#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *node, *next_node;

    if (!list || (*list) == NULL)
        return;

    node = (*list)->next;

    while (node != NULL)
    {
        next_node = node->next;
        while (node->prev != (*list) && node->prev->n > node->n)
        {
            if (node->next)
                node->next->prev = node->prev;
            if (node->prev)
                node->prev->next = node->next;
            node->next = node->prev;
            node->prev = node->prev->prev;
            node->next->prev = node;
            if (node->prev == NULL)
                *list = node;
            else
                node->prev->next = node;
            print_list(*list);
            
        }
        node = next_node;
    }
}
