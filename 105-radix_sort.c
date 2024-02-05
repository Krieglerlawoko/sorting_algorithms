#include "sort.h"

int get_max(int *array, int size);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);

/**
 * get_max - Maximum value in an array of integers got.
 * @array: Array of integers.
 * @size: Array size.
 *
 * Return: The maximum integer in the array.
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
 * radix_counting_sort - Significant digits of an array of integers sortd
 *                       in ascending order using the counting sort algorithm.
 * @array: Array of integers.
 * @size: Array size.
 * @sig: Significant digit to sort on.
 * @buff: Buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
		count[(array[a] / sig) % 10] += 1;

	for (a = 0; a < 10; a++)
		count[a] += count[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		buff[count[(array[a] / sig) % 10] - 1] = array[a];
		count[(array[a] / sig) % 10] -= 1;
	}

	for (a = 0; a < size; a++)
		array[a] = buff[a];
}

/**
 * radix_sort - Array of integers sortd in ascending
 *              order using the radix sort algorithm.
 * @array: Array of ints.
 * @size: Array size.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int mx, sig, *buf;

	if (size < 2 || array == NULL)
		return;

	buf = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	mx = get_max(array, size);
	for (sig = 1; mx / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buf);
}
