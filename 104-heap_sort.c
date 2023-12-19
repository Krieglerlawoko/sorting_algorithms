#include "sort.h"

void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap 2 (int)s in array
 * @a: 1st (int) to swap
 * @b: 2nd (int) to swap
 */
void swap_ints(int *a, int *b)
{
	int tmplt;

	tmplt = *a;
	*a = *b;
	*b = tmplt;
}

/**
 * max_heapify - Turn binary tree into complete binary heap
 * @array: Array of (int)s representing binary tree
 * @size: size of array/tree
 * @base: index of base row of the tree
 * @root: root node of binary tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t lft, rght, lrg;

	lft = 2 * root + 1;
	rght = 2 * root + 2;
	lrg = root;

	if (lft < base && array[lft] > array[lrg])
		lrg = lft;
	if (rght < base && array[rght] > array[lrg])
		lrg = rght;

	if (lrg != root)
	{
		swap_ints(array + root, array + lrg);
		print_array(array, size);
		max_heapify(array, size, base, lrg);
	}
}

/**
 * heap_sort - Sort array(int) in ascending
 *             order using heap sort algorithm.
 * @array: array of (int)
 * @size: size of array
 *
 * Description: Implements sift-down heap sort
 * algorithm. array printed after each swap
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (size < 2 || array == NULL)
		return;

	for (a = (size / 2) - 1; a >= 0; a--)
		max_heapify(array, size, size, a);

	for (a = size - 1; a > 0; a--)
	{
		swap_ints(array, array + a);
		print_array(array, size);
		max_heapify(array, size, a, 0);
	}
}
