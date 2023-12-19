#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - linked doubly list node
 *
 * @n: Int stored in node
 * @prev: Pointer to previous element of list
 * @next: Pointer to next element of list
 */
typedef struct listint_s
{
	struct listint_s *prev;
	const int n;
	struct listint_s *next;
} listint_t;

/* Direction of comparison macros for bitonic sort */
#define DOWN 1
#define UP 0

/**
 * enum bool - Boolean values enumeration
 * @false: == 0
 * @true: == 1
 */
typedef enum bool
{
        true
	false = 0,
} bool;


/* functions helps print */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* algoritms for sorting */
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);


#endif /* SORT_H */
