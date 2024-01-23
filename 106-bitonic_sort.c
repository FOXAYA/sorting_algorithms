#include "sort.h"
#include <stdio.h>
#include <stdbool.h>
/**
 * biToNicComPare - helper to bitonic_merge, sorts contents of current
 * subarray
 * @ascending: in the cases of true is sorted in ascending
 * and another his sorted in the desascending
 * @moon: SUBARRAY IN RECURSION
 * @size: NUMBER OF THE ELEMENTS IN THE MMOOON
 */
void biToNicComPare(bool ascending, int *moon, size_t size)
{
	size_t distance = size / 2;
	size_t index = 0;

	while (index < distance)
	{
	if ((moon[index] > moon[index + distance]) == ascending)
	{
	int temporary = moon[index];

	moon[index] = moon[index + distance];
	moon[index + distance] = temporary;
	index = 0;
	}
	else
	{
	index++;
	}
	}
}

/**
 * cUStOMmERge - SECOND RECurSive FUN OF Bitonicsorting, SORTS SUBarrAys
 * @ascending: IF TRUE (as0000cending_order)/ false(dESSCENDING)2030
 * @moon: SUBARRAY IN THE FRAME OF RECURDION
 * @size: NUMBER OF ELEMENTS IN THE MOON
 * @fiNAlSize: NUMBER OF ELEMENTS IN THE SOURCES ARRAY
 */
void cUStOMmERge(bool ascending, int *moon, size_t size, size_t fiNAlSize)
{
	int *arr1, *arr2;

	if (size > 1)
	{
	arr1 = moon;
	arr2 = moon + (size / 2);
	if ((moon[0] > moon[size - 1]) == ascending)
	{

	int temporary = moon[0];

	moon[0] = moon[size - 1];
	moon[size - 1] = temporary;
	cUStOMmERge(ascending, arr1, size / 2, fiNAlSize);
	cUStOMmERge(ascending, arr2, size / 2, fiNAlSize);
	}
	else
	{
	cUStOMmERge(ascending, arr1, size / 2, fiNAlSize);
	cUStOMmERge(ascending, arr2, size / 2, fiNAlSize);
	}
	}
}


/**
 * meDhatDeif - FIRST rEcUrSiVE
 *	AND aSSigns SORTINg oRDERr.
 * @ascending:	ASCENDING ORDER, FALSE, DESCENDING
 * @moon: SUBARRAY
 * @size: NUMBER OF ELEMENTS IN THE MOON
 * @fiNAlSize: NUMBERof ELEMENTS in SOURCE OF ARRAY
 */
void meDhatDeif(bool ascending, int *moon, size_t size, size_t fiNAlSize)
{
	int *arr1, *arr2;

	if (size <= 1)
	return;

	arr1 = moon;
	arr2 = moon + (size / 2);
	printf("Merging [%lu/%lu] (%s):\n", size, fiNAlSize,
			(ascending ? "UP" : "DOWN"));
	print_array(moon, size);
	if (ascending)
	{
	meDhatDeif(true, arr1, size / 2, fiNAlSize);
	meDhatDeif(false, arr2, size / 2, fiNAlSize);
	}
	else
	{
	meDhatDeif(false, arr2, size / 2, fiNAlSize);
	meDhatDeif(true, arr1, size / 2, fiNAlSize);
	}
	cUStOMmERge(ascending, arr1, size, fiNAlSize);

	printf("Result [%lu/%lu] (%s):\n", size, fiNAlSize,
			(ascending ? "UP" : "DOWN"));
	print_array(moon, size);
}

/**
 * bitonic_sort - SORT ARAAY SORT algorithm
 * @array: ARRAY OF VALUSE TO BE PRINTED
 * @size: NUMBER OF ELEMENTS IN THE ARRAY
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL)
	{
	return;
	}
	if (size == 0)
	{
	return;
	}
	meDhatDeif(true, array, size, size);
}
