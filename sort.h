#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*	Print	*/ 
/* Function prototype for print_array */
void print_array(const int *array, size_t size);
/* Function prototype for print_list */
void print_list(const listint_t *list);

/*	Sorting	*/
/* Function prototype for bubble_sort */
void bubble_sort(int *array, size_t size);
/* Function prototype for sorting a doubly linked list in ascending  */
void insertion_sort_list(listint_t **list);
/* Function prototype that sorts an array of integers in ascending order */
void selection_sort(int *array, size_t size);

#endif /* SORT_H */
