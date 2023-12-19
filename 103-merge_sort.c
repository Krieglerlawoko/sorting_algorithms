#include "sort.h"

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sortsubarray of (int)s
 * @subarr: subarray of array of (int)s to sort
 * @buff: buffer to store sorted subarray
 * @front: front index of array
 * @mid: middle index of array
 * @back: back index of array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t b, c, a = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (b = front, c = mid; b < mid && c < back; a++)
		buff[a] = (subarr[b] < subarr[c]) ? subarr[b++] : subarr[c++];
	for (; b < mid; b++)
		buff[a++] = subarr[b];
	for (; c < back; c++)
		buff[a++] = subarr[c];
	for (b = front, a = 0; b < back; b++)
		subarr[b] = buff[a++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement merge sort algorithm using recursion
 * @subarr: subarray of array of (int)s to sort
 * @buff: buffer to store sorted result
 * @front: front index of subarray
 * @back: back index of subarray
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
 * merge_sort - Sort array of (int)s in ascending
 *              order using merge sort algorithm
 * @array: array of (int)s
 * @size: size of array
 *
 * Description: Implements top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2 || array == NULL )
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
