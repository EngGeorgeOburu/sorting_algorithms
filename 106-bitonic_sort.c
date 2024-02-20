#include"sort.h"
/**
 * bitonic_swap - Compares and swap elements based on the direction
 * @array: The array to be sorted
 * @size: size of the array
 * @up: Direction of sorting
 */
void bitonic_swap(int *array,size_t size, int up)
{
	size_t i, step;

	step = size / 2;
	for (i = 0; i < step; i++)
	{
		if ((array[i] > array[i + step]) == up)
		{
			int temp = array[i];
			array[i] = array[i + step];
			array[i + step] = temp;
		}
		}
}
/**
 * bitonic_merge - merges the subarrays
 * @array: The array to be sorted
 * @size: Size of the array
 * @up: Direction of sorting
 */
void bitonic_merge(int *array, size_t size, int up)
{
	if (size > 1)
	{
		bitonic_swap(array, size, up);
		bitonic_merge(array,size / 2, up);
		bitonic_merge(array + size / 2, size / 2, up);
	}
}
/**
 * bitonic_sort - Sorts an array using Bitonic sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size > 1)
	{
		bitonic_sort(array, size / 2);
		bitonic_sort(array + size / 2, size / 2);
		bitonic_merge(array,size, 1);
	}
}
	
	
