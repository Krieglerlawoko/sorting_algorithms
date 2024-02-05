#include "sort.h"

void swap_ints(int *a, int *b);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int left, int right);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Subset order of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: Array of integers.
 * @size: Array size.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *piv, above, below;

	piv = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *piv)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Quicksort algorithm implemented through recursion.
 * @array: Array of integers to sort.
 * @size: Array size.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, prt - 1);
		lomuto_sort(array, size, prt + 1, right);
	}
}

/**
 * quick_sort - Array of integers sortd in ascending
 *              order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Array size.
 *
 * Description: Lomuto partition scheme used.Array
 *              printd after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
