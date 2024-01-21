#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

/**
 * pRint_Array - print_ArrayRange - prints array of integers
 *	for a specified range of indices
 * @array: arrAy of ValuEs to Be Printed
 * @start_index: StarTing IndEx VaLue
 * @end_index: eNdinG iNdeX ValuE
 */
void pRint_Array(int *array, int start_index, int end_index)
{
	int y = start_index;

	while (y < end_index)
	{
	if (y < end_index - 1)
	printf("%i, ", array[y]);
	else
	printf("%i\n", array[y]);

	y++;
	}
}
/**
 * customCopyFunction - copyArrayElements - Copies
 *	elements from input_data[] to destination[]
 * @found: aRrAy Of vAluEs To Be cOpiEd
 * @start_index: stArtiNg iNdeX ValuE
 * @end_index: anDinG iNdeX VAluE
 * @destination: arrAy To Store cOpiEd inTegErs
 */
void customCopyFunction(int *found, int start_index,
		int end_index, int *destination)
{
	int y = start_index;

	while (y < end_index)
	{
	destination[y] = found[y];
	y++;
	}
}

/**
 * mergeSortedSections - MERgEs sOrted
 *	SubSecTiOns	oF inPUt_data[555]
 *	iN AscEndInG orDer
 * @found: Array oFF vAluES To Be Sorted
 * @start_index: StArTinG InDeX Of tHe LeFt Run
 * @middle_index: StArtINg iNdEx Of the Right run
 * @end_index: eNdinG inDeX Of The RigHt Run
 * @destination: arRAy To StoRe sOrtEd iNteGErs
 */
void mergeArrays(int *found, int start_index, int middle_index,
	int end_index, int *destination)
{
	int left_index, right_index, merged_index;

	left_index = start_index;
	right_index = middle_index;

	printf("Merging...\n");
	printf("[left]: ");
	pRint_Array(found, start_index, middle_index);
	printf("[right]: ");
	pRint_Array(found, middle_index, end_index);

	for (merged_index = start_index; merged_index < end_index; merged_index++)
	{
	if (left_index < middle_index && (right_index >= end_index
	|| found[left_index] <= found[right_index]))
	{
	destination[merged_index] = found[left_index];
	left_index++;
	}
	else
	{
	destination[merged_index] = found[right_index];
	right_index++;
	}
	}

	printf("[Done]: ");
	pRint_Array(destination, start_index, end_index);
}
/**
 * mergeSortRecursive - Recursive engine of merge_sort, splits working copy of
 * array into left and right runs, then merges with mergeArrays
 * @found: Array of integers to be sorted
 * @start_index: Starting index value
 * @end_index: Ending index value
 * @destination: Array to store sorted integers
 */

void mergeSortRecursive(int *found, int start_index,
		int end_index, int *destination)
{
	int middle_index;

	if (end_index - start_index < 2)
	return;
	middle_index = (end_index + start_index) / 2;

	mergeSortRecursive(destination, start_index, middle_index, found);
	mergeSortRecursive(destination, middle_index, end_index, found);
	mergeArrays(found, start_index, middle_index, end_index, destination);
}


/**
* merge_sort - sortt aN arrAu oF iNteGers iN asceNdIng Order uSing a
*	t0op-down mErgE sOrT AlgOriTh
* @array: aRrAy oF iNtEgeRs To Be sOrteD
* @size: aMouN TO elEmeNt InN ArraY
*/
void merge_sort(int *array, size_t size)
{
	int *sorted_array;

	if (array == NULL || size < 2)
	{
	return;
	}
	else
	{
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
	return;
	}
	else
	{
	customCopyFunction(array, 0, size, sorted_array);
	mergeSortRecursive(sorted_array, 0, size, array);
	free(sorted_array);
	}
	}
}
