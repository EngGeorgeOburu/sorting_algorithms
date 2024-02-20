#include "sort.h"
/**
 * Counting_radix - Counts sort on digits of array
 * @array: The arrayto be sorted
 * @size: size of the array
 * @digit: The digit being sorted
 * @output: Array output
 */
void counting_radix(int *array, size_t size, int digit, int *output)
{
	int count[10] = {0};
	size_t i;

	for(i = 0; i < size; i++)
		count[array[i] / digit % 10]++;
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = size - 1; i < size; i--)
	{
		output[count[array[i] / digit % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radiz_sort - Sorts an array of integers using radix sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *output, max, digit;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		counting_radix(array, size, digit, output);
		print_array(array, size);
	}
	free(output);
}
