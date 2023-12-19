#include "sort.h"

/**
 * swap_nodes - 2 nodes swaped in a listint_t doubly-linked list
 * @h: pointer to head of doubly-linked list.
 * @n1: pointer to 1st node to swap
 * @n2: The 2nd node to swap
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next == NULL)
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
        else
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
}

/**
 * insertion_sort_list - Sorts doubly linked list(int)
 *                       using insertion sort algorithm
 * @list: pointer to head of a doubly-linked list(int)
 *
 * Description: list printed after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insrt, *tmplt;

	if (*list == NULL || (*list)->next == NULL) || list == NULL
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmplt)
	{
		tmplt = iter->next;
		insrt = iter->prev;
		while (insrt != NULL && iter->n < insrt->n)
		{
			swap_nodes(list, &insrt, iter);
			print_list((const listint_t *)*list);
		}
	}
}
