#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t a = sizeof(array) / sizeof(array[0]);

	print_array(array, a);
	printf("\n");
	counting_sort(array, a);
	printf("\n");
	print_array(array, a);
	return (0);
}
