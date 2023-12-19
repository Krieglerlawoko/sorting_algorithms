#include "sort.h"

/**
 * swap_ints - Swaps integers (2) in array
 * @a: first integer swaped
 * @b: The second integer swaped
 */
void swap_ints(int *a, int *b)
{
	int tmplt;

	tmplt = *a;
	*a = *b;
	*b = tmplt;
}

/**
 * bubble_sort - Sorts array of integers in ascending order
 * @array: Array of integers to be sorted
 * @size: The size of array to sort
 *
 * Description: array printed after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, len = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (a = 0; a < len - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_ints(array + a, array + a + 1);
				print_array(array, size);
				bub = false;
			}
		}
		len--;
	}
}
