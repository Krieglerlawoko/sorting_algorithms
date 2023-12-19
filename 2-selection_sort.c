#include "sort.h"

/**
 * swap_ints - Swap 2 ints in an array
 * @a: The 1st int to swap
 * @b: The 2nd int to swap
 */
void swap_ints(int *a, int *b)
{
	int tmplt;

	tmplt = *a;
	*a = *b;
	*b = tmplt;
}

/**
 * selection_sort - Sort array of ints in ascending order
 *                  using selection sort algorithm
 * @array: array of ints
 * @size: size of array
 *
 * Description: array printed after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		for (b = a + 1; b < size; b++)
			min = (array[b] < *min) ? (array + b) : min;

		if ((array + a) != min)
		{
			swap_ints(array + a, min);
			print_array(array, size);
		}
	}
}
