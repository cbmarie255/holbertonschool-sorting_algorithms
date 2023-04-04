#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_subarr - Sort a subarr of integers.
 * @subarr: A subarr of an array of integers to sort.
 * @buff: A buffer to store the sorted subarr.
 * @strt: The strt index of the array.
 * @mid: The middle index of the array.
 * @end: The end index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t strt, size_t mid, size_t end)
{
	size_t i = strt, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + strt, mid - strt);

	printf("[right]: ");
	print_array(subarr + mid, end - mid);

	while (i < mid && j < end)
	{
		if (subarr[i] < subarr[j])
			buff[k++] = subarr[i++];
		else
			buff[k++] = subarr[j++];
	}

	while (i < mid)
		buff[k++] = subarr[i++];

	while (j < end)
		buff[k++] = subarr[j++];

	i = strt, k = 0;
	while (i < end)
		subarr[i++] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + strt, end - strt);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarr of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @strt: The strt index of the subarr.
 * @end: The end index of the subarr.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t strt, size_t end)
{
	size_t mid;

	if (end - strt > 1)
	{
		mid = strt + (end - strt) / 2;
		merge_sort_recursive(subarr, buff, strt, mid);
		merge_sort_recursive(subarr, buff, mid, end);
		merge_subarr(subarr, buff, strt, mid, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);

	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
