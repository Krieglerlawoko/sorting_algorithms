#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints array of int
 *
 * @array: array to print
 * @size: Number of elements array has
 */
void print_array(const int *array, size_t size)
{
	size_t a;

	a = 0;
	while (a < size && array)
	{
		if (a > 0)
			printf(", ");
		printf("%d", array[a]);
		++a;
	}
	printf("\n");
}
