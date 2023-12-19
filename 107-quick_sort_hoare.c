#include "sort.h"

int hoare_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t size, int left, int right);

/**
 * swap_ints - Swap 2 int in an array
 * @a: 1st int to swap
 * @b: 2nd int to swap
 */
void swap_ints(int *a, int *b)
{
	int tmplt;

	tmplt = *a;
	*a = *b;
	*b = tmplt;
}

/**
 * hoare_partition - Order subset of an array of int
 *                   according to hoare partition scheme
 * @array: array of int
 * @size: size of array
 * @left: starting index of subset to order
 * @right: ending index of subset to order
 *
 * Return: final partition index
 *
 * Description: Uses last element of partition as pivot
 * array printed after each swap of 2 elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pvt, abve, below;

	pvt = array[right];
	for (abve = left - 1, blow = right + 1; abve < blow;)
	{
		do {
			abve++;
		} while (array[abve] < pvt);
		do {
			blow--;
		} while (array[blow] > pvt);

		if (abve < blow)
		{
			swap_ints(array + abve, array + blow);
			print_array(array, size);
		}
	}

	return (abve);
}

/**
 * hoare_sort - Implement quicksort algorithm using recursion
 * @array: array of int to sort
 * @size: size of array
 * @left: starting index of array to order from
 * @right: ending index of array to order from
 *
 * Description: Uses Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left < 0)
                return;
        else:
	{
		prt = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort array of int in ascending
 *                    order using quicksort algorithm
 * @array: array of int
 * @size: size of array
 *
 * Description: Uses Hoare partition scheme.
 * array printed after each swap of 2 elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	hoare_sort(array, size, 0, size - 1);
}
