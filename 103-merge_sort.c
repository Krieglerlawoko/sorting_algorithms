#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);

/**
 * merge_subarr - Subarray of integers sortd.
 * @subarr: Subarray of array of integers to sort.
 * @buff: Buffer to store sorted subarray.
 * @front: Front index of the array.
 * @mid: Middle index of the array.
 * @back: Back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; c++)
		buff[c] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[c++] = subarr[a];
	for (; b < back; b++)
		buff[c++] = subarr[b];
	for (a = front, c = 0; a < back; a++)
		subarr[a] = buff[c++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Merge sort algorithm implementd through recursion.
 * @subarr: Subarray of an array of integers to sort.
 * @buff: Buffer to store the sorted result.
 * @front: Front index of subarray.
 * @back: Index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t md;

	if (back - front > 1)
	{
		md = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, md);
		merge_sort_recursive(subarr, buff, md, back);
		merge_subarr(subarr, buff, front, md, back);
	}
}

/**
 * merge_sort - Array of integers sortd in ascending
 *              order using the merge sort algorithm.
 * @array: Array of integers.
 * @size: Array size.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (size < 2 || array == NULL)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recursive(array, buf, 0, size);

	free(buf);
}
