#include "sort.h"

int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);

void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Subset of an array orderd of integers
 *                   according to the hoare partition scheme.
 * @array: integers Array.
 * @size: Array size.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Last element of the partition used as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int piv, above, below;

	piv = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < piv);
		do {
			below--;
		} while (array[below] > piv);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Quicksort algorithm implemented through recursion.
 * @array: integer array.
 * @size: Array size.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Hoare partition scheme used.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, prt - 1);
		hoare_sort(array, size, prt, right);
	}
}

/**
 * quick_sort_hoare - Array of integers sortd in ascending
 *                    order using the quicksort algorithm.
 * @array: int array.
 * @size: Array size.
 *
 * Description: Hoare partition scheme used. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	hoare_sort(array, size, 0, size - 1);
}
