#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *node, *next_node, *prev_node, *temp;

    if (!list || !(*list))
        return;

    node = (*list)->next;
    while (node)
    {
        next_node = node->next;
        prev_node = node->prev;

        while (prev_node && prev_node->n > node->n)
        {
            temp = node->next;

            if (prev_node->prev)
                prev_node->prev->next = node;
            else
                *list = node;

            node->prev = prev_node->prev;
            prev_node->next = temp;

            if (temp)
                temp->prev = prev_node;

            node->next = prev_node;
            prev_node->prev = node;

            prev_node = node->prev;

            /* Print the list after each swap */
            listint_t *current = *list;
            while (current)
            {
                if (current->next)
                    printf("%d, ", current->n);
                else
                    printf("%d\n", current->n);
                current = current->next;
            }
        }
        node = next_node;
    }
}
