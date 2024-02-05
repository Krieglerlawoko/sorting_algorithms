#include "sort.h"

void max_heapify(int *array, size_t size, size_t base, size_t root);
void swap_ints(int *a, int *b);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Binary tree turnd into a complete binary heap.
 * @array: Array of integers representing a binary tree.
 * @size: Array/tree size.
 * @base: Index of the base row of the tree.
 * @root: Root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t lft, rght, lrge;

	lft = 2 * root + 1;
	rght = 2 * root + 2;
	lrge = root;

	if (lft < base && array[lft] > array[lrge])
		lrge = lft;
	if (rght < base && array[rght] > array[lrge])
		lrge = rght;

	if (lrge != root)
	{
		swap_ints(array + root, array + lrge);
		print_array(array, size);
		max_heapify(array, size, base, lrge);
	}
}

/**
 * heap_sort - Array of integers sortd in ascending
 *             order using the heap sort algorithm.
 * @array: Array of integers.
 * @size: Array size.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
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
