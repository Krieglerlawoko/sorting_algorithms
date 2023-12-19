nclude "sort.h"

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
 * shell_sort - Sort array of (ints) in ascending
 *              order using shell sort algorithm
 * @array: array of (int)s
 * @size: size of array
 *
 * Description: Uses Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gp, a, b;

	if (array == NULL || size < 2)
		return;

	for (gp = 1; gp < (size / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (a = gp; a < size; a++)
		{
			b = a;
			while (b >= gp && array[b - gp] > array[b])
			{
				swap_ints(array + b, array + (b - gp));
				b -= gp;
			}
		}
		print_array(array, size);
	}
}
