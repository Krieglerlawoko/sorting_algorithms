#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints list of int
 *
 * @list: list to print
 */
void print_list(const listint_t *list)
{
	int a;

	a = 0;
	while (list)
	{
		if (a > 0)
			printf(", ");
		printf("%d", list->n);
		++a;
		list = list->next;
	}
	printf("\n");
}
