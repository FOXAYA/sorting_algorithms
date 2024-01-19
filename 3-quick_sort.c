#include "sort.h"


/**
 * lomutoPartition - Lomuto's partition scheme for quicksort
 * @array: array of integers to be sorted
 * @start: index in array that begins partition
 * @end: index in array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int lomutoPartition(int *array, int start, int end, size_t size)
{
    int index_i, index_j, pivot_element, temporary;

    pivot_element = array[end];
    index_i = start - 1;
    index_j = start;

    while (index_j <= end - 1)
    {
        if (array[index_j] <= pivot_element)
        {
            index_i++;
            temporary = array[index_i];
            array[index_i] = array[index_j];
            array[index_j] = temporary;
            if (array[index_i] != array[index_j])
                print_array(array, size);
        }
        index_j++;
    }

    temporary = array[index_i + 1];
    array[index_i + 1] = array[end];
    array[end] = temporary;
    if (array[index_i + 1] != array[end])
        print_array(array, size);

    return (index_i + 1);
}
/**
 * quickSort - recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: array of integers to be sorted
 * @start: index in array that begins partition
 * @end: index in array that ends partition
 * @size: amount of elements in array
 */
void quickSort(int *array, int start, int end, size_t size)
{
    int pivot;

    if (start < end)
    {
        pivot = lomutoPartition(array, start, end, size);
        quickSort(array, start, pivot - 1, size);
        quickSort(array, pivot + 1, end, size);
    }
}


/**
 * quick_sort - Sorts an array of integers in ascending order using the quick
 * sort algorithm with the Lomuto partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void quick_sort(int *array, size_t size)
{
    if (array == NULL)
        return;

    if (size < 2)
        return;

    quickSort(array, 0, (int)size - 1, size);
}
