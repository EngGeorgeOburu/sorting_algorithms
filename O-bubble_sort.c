#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    /* Outer loop to traverse throught the entire array*/
    for (i = 0; i < size - 1; i++)
    {
        swapped = 0 /* Flag to track if any swap occurs in the inner loop */
            /* Inner loop comparing adjacent elements and swap if necessary */
            for(j = 0; j < size - i -1; j++)
            {
                /* Check if the current element is greater than the next elelmtn */
                if (array[j] > array[j + 1])
                {
                        /*swap the elements */
                        temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                        swapped = 1; /*set swapped flag to true */
                        print_array(array, size);
                }
            }
        /* If no two elements are swapped in the inner array, then it's sorted */
        if (swapped == 0)
            break;
    }
}
                        

