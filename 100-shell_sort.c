#include "sort.h"

/**
 * swap_ints - Two integers swapd in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Array of integers sorted in ascending
 *              order using the shell sort algorithm.
 * @array: Array of integers.
 * @size: Array size.
 *
 * Description: Knuth interval sequence usd.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; i++)
		{
			b = i;
			while (b >= gap && array[b - gap] > array[b])
			{
				swap_ints(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
