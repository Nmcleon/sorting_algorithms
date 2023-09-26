#include "sort.h"

/**
* swap_nodes - swaps two nodes in a doubly linked list
* @list: double pointer to the head of the doubly linked list
* @node1: pointer to the first node
* @node2: pointer to the second node
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
/**
* cocktail_sort_list - sorts a doubly linked list of integers in ascending
*                      order using the Cocktail shaker sort algorithm
* @list: Double pointer to the head of doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *node;

	node = *list;
	while (swapped)
	{
		swapped = 0;
		while (node && node->next)
		{
			if (node->n > node->next->n)
			{
				swap_nodes(list, node, node->next);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
			{
				node = node->next;
			}
		}
		if (!swapped)
		{
			break;
		}
		swapped = 0;
		while (node && node->prev)
		{
			if (node->prev->n > node->n)
			{
				swap_nodes(list, node->prev, node);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
		}
	}
}
