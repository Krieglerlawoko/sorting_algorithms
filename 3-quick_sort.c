nclude "sort.h"

void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);
void lomuto_sort(int *array, size_t size, int left, int right);

/**
 * swap_ints - Swap 2 ints in an array
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
 * lomuto_partition - Order subset of array of ints according to
 *                    lomuto partition scheme
 * @array: array of (ints)
 * @size: size of array
 * @left: starting index of subset to order
 * @right: ending index of subset to order
 *
 * Return: final partition index
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

	if (array[above] > *piv)
	{
		swap_ints(array + above, piv);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: array of ints to sort
 * @size: The size of array
 * @left: starting index of array partition to order
 * @right: ending index of array partition to order
 *
 * Description: Uses Lomuto partition scheme
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
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
