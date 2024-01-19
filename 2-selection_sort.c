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
* find_Max - Function to find the index of the maximum element in an array
* @array: The array
* @n: The size of the array
* Return: The index of the maximum element
*/
int find_Max(int array[], size_t  n) {
   size_t maxIndex = n;
   size_t i;
   for(i = 0; i < n; i++) {
       if (array[i] > array[maxIndex])
           maxIndex = i;
   }
   return maxIndex;
}

/**
* selection_sort - Function Sorts an array of numbers using selection sort
* @array : The array will sorted
* @size : The numbers of elements in @array
*/
void selection_sort(int *array, size_t size)
{
    size_t i;
    for (i = 0; i < size - 1; i++)
    {
       int maxIndex = find_Max(array + 1 , size - 1);
       swap_fun(&array[i + maxIndex], &array[i]);
       print_array(array, size);

     
    }
}

