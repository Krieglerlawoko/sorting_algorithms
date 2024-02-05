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
	int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
	size_t a = sizeof(array) / sizeof(array[0]);

	print_array(array, a);
	printf("\n");
	bitonic_sort(array, a);
	printf("\n");
	print_array(array, a);
	return (0);
}
