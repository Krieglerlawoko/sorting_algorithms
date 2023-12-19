#include "sort.h"

void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);

/**
 * get_max - Get maximum value in array of (int)
 * @array: array(int)
 * @size: size of array
 *
 * Return: max int in the array
 */
int get_max(int *array, int size)
{
	int mx, a;

	for (mx = array[0], a = 1; a < size; a++)
	{
		if (array[a] > mx)
			mx = array[a];
	}

	return (mx);
}

/**
 * radix_counting_sort - Sort significant digits of array of int
 *                       in ascending order using counting sort algorithm
 * @array: array of int
 * @size: size of array
 * @sig: significant digit to sort
 * @buff: buffer to store sorted array in
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
		cnt[(array[a] / sig) % 10] += 1;

	for (a = 0; a < 10; a++)
		cnt[a] += cnt[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		buff[cnt[(array[a] / sig) % 10] - 1] = array[a];
		cnt[(array[a] / sig) % 10] -= 1;
	}

	for (a = 0; a < size; a++)
		array[a] = buff[a];
}

/**
 * radix_sort - Sort array of int in ascending
 *              order using radix sort algorithm
 * @array: array of int
 * @size: size of array
 *
 * Description: Implements LSD radix sort algorithm.
 * array printed after each significant digit increase
 */
void radix_sort(int *array, size_t size)
{
	int max, sg, *bff;

	if (size < 2 || array == NULL)
		return;

	bff = malloc(sizeof(int) * size);
	if (bff == NULL)
		return;

	max = get_max(array, size);
	for (sg = 1; max / sg > 0; sg *= 10)
	{
		radix_counting_sort(array, size, sg, bff);
		print_array(array, size);
	}

	free(bff);
}
