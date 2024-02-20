#include "sort.h"
/**
 * swap - Swaps twointegers in an array
 * @a: Pointer to the forst integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array : The array to be sorted
 * @low: The starting index of the partiton to be sorted
 * @high: The ending of the partiton to be sorted
 * @size: The size of the array
 * Return: Sizeofthe array
 */
int lomuto_partition(int *array,int low, int high, size_t size)
{
	int pivot, temp, i, j;

	pivot = array[high];
	i = low -1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quicksort_recursive - Recursive function to perform quicksort
 * @array: The array to be sorted
 * @low: The starting index of the partion to be sorted;
 * @high: The ending index of the partiton ot be sorted
 * @size: The size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array,low, high, size);

		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array ofintegers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
