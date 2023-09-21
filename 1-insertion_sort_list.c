#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *prev_node, *temp;

    if (!list || !(*list))
        return;

    current = (*list)->next;
    while (current)
    {
        next_node = current->next;
        prev_node = current->prev;
        
        while (prev_node && prev_node->n > current->n)
        {
            temp = current->next;

            if (prev_node->prev)
                prev_node->prev->next = current;
            else
                *list = current;

            current->prev = prev_node->prev;
            prev_node->next = temp;

            if (temp)
                temp->prev = prev_node;

            current->next = prev_node;
            prev_node->prev = current;

            print_list(*list);
        }
        current = next_node;
    }
}
