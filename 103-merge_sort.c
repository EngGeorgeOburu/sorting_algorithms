#include "sort.h"
/**
 * merge - Merges two subarrays into one sorted array
 * array: Pointer to array
 * @size: Size of the array
 * @left: Pointer to the left sub array
 * @right: Pointer to the regh subarray
 * @temp: Temporary storage
 */
void merge(int *array, int *temp, size_t left, size_t right, size_t mid)
{
	size_t i, j, k;

	printf("Merging....\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid, k = left; i < mid && j < right; k++)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	while (i < mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j < right)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	for (k = left; k < right; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array + left, right - left);
}
/**
 * merge_sort_recursive - Merge sort algorithm
 * @array: Array to be sorted
 * @temp: Temporary array
 * @left: Index of the left boundary
 * @right: Index of the right boundary
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;
	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);

}
/**
 * merge_sort - Sorts the array using Merge sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	if (!array || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}

