#include "sort.h"

/**
 * get_max - Get maximum value in an array of (int)s
 * @array: array of (int)s
 * @size: The size of array
 *
 * Return: maximum (int) in array
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
 * counting_sort - Sort array of (int)s in ascending order
 *                 using counting sort algorithm
 * @array: array of (int)s
 * @size: size of array
 *
 * Description: counting array printed after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *sorted, mx, a;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	mx = get_max(array, size);
	cnt = malloc(sizeof(int) * (mx + 1));
	if (cnt == NULL)
	{
		free(sorted);
		return;
	}

	for (a = 0; a < (mx + 1); a++)
		cnt[a] = 0;
	for (a = 0; a < (int)size; a++)
		cnt[array[a]] += 1;
	for (a = 0; a < (mx + 1); a++)
		cnt[a] += cnt[a - 1];
	print_array(cnt, mx + 1);

	for (a = 0; a < (int)size; a++)
	{
		sorted[cnt[array[a]] - 1] = array[a];
		cnt[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorted[a];

	free(sorted);
	free(cnt);
}
