#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * count_sort - Uses count sort to sort an array by LSD
 *
 * @array: Array to sort, contains only numbers >= 0
 * @size: Number of items in array
 * @digit: significant digit to sort by
 */
void count_sort(int *array, size_t size, size_t digit)
{
	int key_arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int index_arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *buffer = malloc(sizeof(*array) * size);
	size_t i, key;

	i = 0;
	while (i < size)
	{
		key = array[i] % (digit * 10) / digit;
		key_arr[key]++;
		i++;
	}

	i = 0;
	while (i < 9)
	{
		index_arr[i + 1] = index_arr[i] + key_arr[i];
		i++;
	}

	i = 0;
	while (i < size)
	{
		key = array[i] % (digit * 10) / digit;
		buffer[index_arr[key]] = array[i];
		index_arr[key]++;
		i++;
	}

	i = 0;
	while (i < size)
	{
		array[i] = buffer[i];
		i++;
	}
	free(buffer);
}

/**
 * find_max - gets max value in array
 *
 * @array: array of ints
 * @size: length of array
 * Return: max int
 */
size_t find_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	i = 0;
	while (i < size)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		i++;
	}
	return (max);
}

/**
 * radix_sort - Uses LSD Radix to sort an array of integers in ascending order
 *
 * @array: Array to sort, contains only numbers >= 0
 * @size: Number of items in array
 */
void radix_sort(int *array, size_t size)
{
	size_t digit;
	int max;

	if (array && size > 1)
	{
		max = find_max(array, size);
		digit = 1;
		while (max / digit > 0)
		{
			count_sort(array, size, digit);
			print_array(array, size);
			digit *= 10;
		}
	}
}
