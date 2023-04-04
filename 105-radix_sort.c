#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max_num, exp;
	int *count, *output;
	size_t i;

	if (!array || size < 2)
		return;

	max_num = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
   	}

   	count = malloc(sizeof(int) * 10);
   	output = malloc(sizeof(int) * size);

	for (exp = 1; max_num / exp > 0; exp *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;

		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);
	}

	free(count);
	free(output);
}
