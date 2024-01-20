#include "sort.h"

/**
* swap_fun - Function swap two numbers in an array
* @num_1: The first number
* @num_2 : the second number
*/
void swap_fun(int *num_1, int *num_2)
{
	int temp = *num_1;
	*num_1 = *num_2;
	*num_2 = temp;
}
/**
* selection_sort - Function Sorts an array of numbers using selection sort
* @array : The array will sorted
* @size : The numbers of elements in @array
*/


void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap_fun(&array[i], &array[minIndex]);
			print_array(array, size);
		}
	}
}
