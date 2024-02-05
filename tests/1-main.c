#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * create_listint - Doubly linked list created from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Array size
 *
 * Return: Points to first element of created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *lst;
	listint_t *nde;
	int *tmp;

	lst = NULL;
	while (size--)
	{
		nde = malloc(sizeof(*nde));
		if (!nde)
			return (NULL);
		tmp = (int *)&nde->n;
		*tmp = array[size];
		nde->next = lst;
		nde->prev = NULL;
		lst = nde;
		if (lst->next)
			lst->next->prev = lst;
	}
	return (lst);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
