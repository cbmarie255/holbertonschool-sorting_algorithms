#include "sort.h"

/**
 * sift_down - Sift down the node at index @idx in @heap
 *
 * @heap: The heap to be sifted down
 * @size: The size of the heap
 * @idx: The index of the node to be sifted down
 */
void sift_down(int *heap, size_t size, size_t idx)
{
	size_t root = idx;

	while ((2 * root) + 1 < size)
	{
		size_t child = 2 * root + 1;
		if (child + 1 < size && heap[child] < heap[child + 1])
		++child;
		if (heap[root] < heap[child])
		{
			int tmp = heap[root];
			heap[root] = heap[child];
			heap[child] = tmp;
			print_array(heap, size);
			root = child;
		}	
		else
			break;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	/* Build max-heap */
	for (size_t i = size / 2; i > 0; --i)
	sift_down(array, size, i - 1);

	/* Sort the heap */
	for (size_t i = size - 1; i > 0; --i)
	{
		int tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, i, 0);
	}
}
