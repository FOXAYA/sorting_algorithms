#include "sort.h"

/**
 * modifiedParent - retu inDeD oF pArent nodE fOr
 * an aRRay aRRangEd As A BInaRY
 * TrE,E For IndEx Y
 * @y: StArtiIG IndEX To dDEtRrmIne Parent node index
 * Return: InDEx OF PArEnt nOdE
 */
int modifiedParent(int y)
{
	return ((y - 1) / 2);
}

/**
 * adjustedLeftChild - RetUrNs iNdEX of leET ChIld BrAncH
 * FoR an ARrAy ARRaNgEd as
 * A BInary TREe, For iNDeX y
 * @y: StArT iNdEX To DETermNE LEFT cHELD BRAUch INDXE
 * Return: IND=Ex of== LEFT CHILD
 */
int adjustedLeftChild(int y)
{
	return ((2 * y) + 1);
}

/**
 * vert_to_H - arranges array of integers in
 * To A HEAB-BINARY TREe SChEmE
 * @array: arRAY OF IntEgGER
 * @size: NUMBER OFf ElEMENTS IN ARRay
 */
void vert_to_H(int *array, size_t size)
{
	int begin = modifiedParent(size - 1);

	do {
	heapify_Do_win(array, size, begin, size - 1);
	begin--;
	} while (begin >= 0);
}

/**
 * heapify_Do_win - ShUFFl HEAPBINARY TREE SORtE ARRAYy
 * array asCEnD VALUE
 * @array: ARRAY OF VALUES TO sd i0from HEAP TO SCOND
 * @size: NUMBER OF ELEMENTSs IN ARRAY
 * @begin: START_INDEX
 * @finish: END_INDEX
 */
void heapify_Do_win(int *array, size_t size, int begin, int finish)
{
	int origin, exchange, temporary, offspring;

	origin = begin;

	do {
	offspring = adjustedLeftChild(origin);
	exchange = origin;

	if (array[exchange] < array[offspring])
	exchange = offspring;
	if (offspring + 1 <= finish && array[exchange] < array[offspring + 1])
	exchange = offspring + 1;

	if (exchange != origin)
	{
	temporary = array[origin];
	array[origin] = array[exchange];
	array[exchange] = temporary;
	print_array(array, size);
	origin = exchange;
	}
	else
	return;

	} while (adjustedLeftChild(origin) <= finish);
}

/**
 * heap_sort - SORT ARR of INTEGER in ascend ORD_er USINGaHEAPSORTED
 * sift-down algorithm
 * @array: Arr VALUEes TO BE SORTED
 * @size: NUMBER OF ELEMENTS IN THE ARRAY
 */
void heap_sort(int *array, size_t size)
{
	int mood, placeholder;

	if (!array || size < 2)
	return;

	vert_to_H(array, size);

	mood = (int)size - 1;
	do {
	placeholder = array[mood];
	array[mood] = array[0];
	array[0] = placeholder;
	print_array(array, size);
	mood--;

	heapify_Do_win(array, size, 0, mood);

	} while (mood > 0);
}
