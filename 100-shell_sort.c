#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth sequence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
    int current_index, inner_index, current_interval, n, max_interval, temporary_value;

    if (!array || size < 2)
        return;

    n = (int)size;

    /* Find the maximum interval using Knuth sequence*/
    current_interval = 1;
    while (current_interval < n)
    {
        max_interval = current_interval;
        current_interval = (current_interval * 3) + 1;
    }

    /* Start with the largest Knuth seq value less than n as current_interval*/
    /*and work down sequence to an interval of 1*/
    current_interval = max_interval;
    while (current_interval > 0)
    {
        /*Do a gapped insertion sort for this interval size*/
        current_index = current_interval;
        while (current_index < n)
        {
            /* Add array[current_index] to interval-sorted elements*/
            /* Save array[current_index] in temporary_value in preparation to overwrite*/
            temporary_value = array[current_index];

            /* Shift earlier interval-sorted elements up until the*/
            /*correct location for array[current_index] is found*/
            inner_index = current_index;
            while (inner_index >= current_interval && array[inner_index - current_interval] > temporary_value)
            {
                array[inner_index] = array[inner_index - current_interval];
                inner_index -= current_interval;
            }

            /* Place temporary_value (original array[current_index]) to its correct location*/
            array[inner_index] = temporary_value;

            current_index += 1;
        }
        /* Print the array after each iteration*/
        print_array(array, size);

        current_interval = (current_interval - 1) / 3;
    }
}

