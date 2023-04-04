#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @start: The start index of the array.
 * @mid: The middle index of the array.
 * @end: The end index of the array.
 */
void merge_subarray(int *subarray, int *buff, size_t start, size_t mid, size_t end)
{
    size_t i = start, j = mid, k = 0;

    printf("Merging...\n[left]: ");
    print_array(subarray + start, mid - start);

    printf("[right]: ");
    print_array(subarray + mid, end - mid);

    while (i < mid && j < end) {
        buff[k++] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
    }

    while (i < mid) {
        buff[k++] = subarray[i++];
    }

    while (j < end) {
        buff[k++] = subarray[j++];
    }

    i = start, k = 0;
    while (i < end) {
        subarray[i++] = buff[k++];
    }

    printf("[Done]: ");
    print_array(subarray + start, end - start);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buff, size_t start, size_t end)
{
    size_t mid;

    if (end - start > 1) {
        mid = start + (end - start) / 2;
        merge_sort_recursive(subarray, buff, start, mid);
        merge_sort_recursive(subarray, buff, mid, end);
        merge_subarray(subarray, buff, start, mid, end);
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

    if (array == NULL || size < 2) {
        return;
    }

    buff = malloc(sizeof(int) * size);

    if (buff == NULL) {
        return;
    }

    merge_sort_recursive(array, buff, 0, size);

    free(buff);
}