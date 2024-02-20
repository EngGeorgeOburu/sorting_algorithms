#include "sort.h"
/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL;
	int *output = NULL;
	int max = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count[i] =0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	printf("Count array: ");
	for (i = 0; i <= (size_t)max; i++)
		printf("%d, ", count[i]);
	printf("\n");

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i ++)
		array[i] = output[i];
	free(count);
	free(output);
}
		


