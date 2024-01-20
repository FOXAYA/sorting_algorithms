#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selection sort
 * algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
	int y = 0, d, min_index, temp_value, n = (int)size;

	if (!array || size < 2)
	return;

	while (y < n - 1)
	{
	/* scan from that position to the end, */
	min_index = y;
	d = y + 1;

	while (d < n)
	{
	/* determine the minimum value in that range */
	if (array[d] < array[min_index])
	{
	min_index = d;
	}
	d++;
	}

	/* and if it is lower than the value at start of range, */
	/* swap them */
	if (min_index != y)
	{
	temp_value = array[y];
	array[y] = array[min_index];
	array[min_index] = temp_value;
	print_array(array, size);
	}

	y++;
	}
}
