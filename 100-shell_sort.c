#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth sequence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
	int current_index, inner_index, current_interval = 1,
	n, max_interval, temporary_value;
	if (!array || size < 2)
	return;
	n = (int)size;
	while (current_interval < n)
	{
	max_interval = current_interval;
	current_interval = (current_interval * 3) + 1;
	}
	current_interval = max_interval;
	while (current_interval > 0)
	{
	current_index = current_interval;
	while (current_index < n)
	{
	temporary_value = array[current_index];
	inner_index = current_index;
	while (inner_index >= current_interval &&
	array[inner_index - current_interval] > temporary_value)
	{
	array[inner_index] = array[inner_index - current_interval];
	inner_index -= current_interval;
	}
	array[inner_index] = temporary_value;
	current_index += 1;
	}
	print_array(array, size);
	current_interval = (current_interval - 1) / 3;
	}
}
