#include "sort.h"

/**
 * swap - Swaps the positions of two elements into an array
 * @array: Array to be arragned
 * @a: One array element
 * @b: The second array element
 */
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * Shell_sort - Sorts an array of integers in ascending order uisng
 * 		the shell sort algorithm with the Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;

	while (gap < size /3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i <size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1)/3;
		print_array(array, size);
	}
}
