#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Array of integers printed
 *
 * @array: Array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t a;

	a = 0;
	while (array && a < size)
	{
		if (a > 0)
			printf(", ");
		printf("%d", array[a]);
		++a;
	}
	printf("\n");
}
