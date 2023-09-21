#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *next_node;

	*node = NULL;
	*next_node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	node = node->next;
	while (node)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			next_node = node;
			if (node->next)
				(node->next)->prev = next_node->prev;
			(node->prev)->next = next_node->next;
			node = node->prev;
			next_node->prev = node->prev;
			next_node->next = node;
			if (node->prev)
				(node->prev)->next = next_node;
			node->prev = next_node;
			if (next_node->prev == NULL)
				*list = next_node;
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}

}
