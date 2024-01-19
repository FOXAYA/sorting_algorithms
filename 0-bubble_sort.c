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
* bubble_sort - Function sorts an array of number ascending
* @array : The array will sorted
* @size : The numbers of elements in @array
*/
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    if (array == NULL || size < 2)
    {
        return;
    }

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap_fun(&array[j], &array[j + 1]);
            }
        }
    }
}
