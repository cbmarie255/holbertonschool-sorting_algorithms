#include "sort.h"

/**
 *selection_sort - will sort an array of ints using selection sorting
 *@array: pointer to the array
 *@size:size of the array
 *Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int test;
	int temp;
	int place;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		test = 0;
		temp = 0;
		for (j = i + 1; j < size; j++)
		{
			if (!test && array[j] < array[i])
			{
				temp = array[j];
				place = j;
				test = 1;
			}
			if (test && array[j] < temp)
			{
				temp = array[j];
				place = j;
			}
		}
		if (test != '\0')
		{
			array[place] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
