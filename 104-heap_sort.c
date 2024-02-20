#include "sort.h"
/**
 * heap_arrange - Rearranges heap to satisfy the heap property
 * @array:Array to be sorted
 * @size: Size of the heap
 * @i: Index of the root of the subtree
 * @n: Size of the array
 */
void heap_arrange(int *array, size_t size, size_t i, size_t n)
{
	size_t max, left, right;
	int temp;

	max = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < size && array[left] > array[max])
		max = left;
	if (right < size && array[right] > array[max])
		max = right;
	if (max != i)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;

		print_array(array, n);
		heap_arrange(array, size, max, n);
	}
}
/**
 * heap_sort - Sorts an array in ascending order using
 * 		the Heap sort algorithm
 * @array: Array to be sorted.
 * @size: size of the array to be sorted
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	for (i = size / 2; i > 0; i--)
		heap_arrange(array, size, i - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heap_arrange(array, i, 0, size);
	}
}
