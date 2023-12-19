#include "sort.h"

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void swap_ints(int *a, int *b);
void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * swap_ints - Swap 2 ints in an array
 * @a: 1st int to swap.
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
 * bitonic_merge - Sort bitonic sequence inside array of int
 * @array: array of int
 * @size: size of array
 * @start: starting index of sequence in array to sort
 * @seq: size of sequence to sort
 * @flow: direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t a, jmp = seq / 2;

	if (seq > 1)
	{
		for (a = start; a < start + jmp; a++)
		{
			if ((flow == UP && array[a] > array[a + jmp]) ||
			    (flow == DOWN && array[a] < array[a + jmp]))
				swap_ints(array + a, array + a + jmp);
		}
		bitonic_merge(array, size, start, jmp, flow);
		bitonic_merge(array, size, start + jmp, jmp, flow);
	}
}

/**
 * bitonic_seq - Convert array of (int) into bitonic sequence
 * @array: array of int
 * @size: size of array
 * @start: starting index of block of building bitonic sequence
 * @seq: size of block of building bitonic sequence
 * @flow: direction to sort bitonic sequence block in
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t ct = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq < 1)
                return;
        else
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, ct, UP);
		bitonic_seq(array, size, start + ct, ct, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort array of ints in ascending
 *                order using bitonic sort algorithm
 * @array: array of int
 * @size: size of array
 *
 * Description: Prints array after each swap. Only for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
