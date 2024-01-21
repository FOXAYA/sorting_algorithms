#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Applies counting sort algorithm to arrange an array
 *	of integers in ascending order.
 * @array: Array of integers to be arranged.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int current_element, total_count, maximum_value;
	int *element_count, *sorted_array;

	if (!array || size < 2)
		return;
	maximum_value = array[0];
	for (current_element = 0; current_element < (int)size; current_element++)
	{
		if (array[current_element] > maximum_value)
			maximum_value = array[current_element];
	}
	element_count = calloc((maximum_value + 1), sizeof(int));
	if (!element_count)
		return;
	for (current_element = 0; current_element < (int)size; current_element++)
		element_count[array[current_element]]++;
	for (current_element = 0, total_count = 0; current_element <
			maximum_value + 1; current_element++)
	{
		total_count = element_count[current_element] + total_count;
		element_count[current_element] = total_count;
	}
	print_array(element_count, maximum_value + 1);
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
		return;
	for (current_element = 0; current_element < (int)size; current_element++)
	{
		sorted_array[element_count[array[current_element]] - 1]
			= array[current_element];
		element_count[array[current_element]]--;
	}
	for (current_element = 0; current_element < (int)size; current_element++)
		array[current_element] = sorted_array[current_element];
	free(element_count);
	free(sorted_array);
}
