#include <stdio.h>
#include "sort.h"

/**
 * print_list - List of integers printed
 *
 * @list: List to printed
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
