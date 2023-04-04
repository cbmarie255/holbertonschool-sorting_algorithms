#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of the given array
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @left: Pointer to the left subarray
 * @left_size: Number of elements in the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Number of elements in the right subarray
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
    int *result, *left_end, *right_end;
    size_t i, k;

    result = malloc(sizeof(int) * size);
    if (!result)
        return;

    left_end = left + left_size;
    right_end = right + right_size;

    i = 0, k = 0;
    while (left < left_end && right < right_end)
    {
        if (*left <= *right)
            result[k++] = *left++;
        else
            result[k++] = *right++;
    }
    while (left < left_end)
        result[k++] = *left++;
    while (right < right_end)
        result[k++] = *right++;

    for (i = 0; i < size; ++i)
        array[i] = result[i];

    free(result);
}

/**
 * merge_sort_helper - Helper function for merge sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort_helper(int *array, size_t size)
{
    int *left, *right;
    size_t mid;

    if (size < 2)
        return;

    mid = size / 2;

    left = array;
    right = array + mid;

    merge_sort_helper(left, mid);
    merge_sort_helper(right, size - mid);

    merge(array, size, left, mid, right, size - mid);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
  int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_helper(array, size);

	free(buff);
}