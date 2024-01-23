#ifndef SORT_H
#define SORT_H
#include <sys/types.h>
#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *swap_node(listint_t *node, listint_t **list);
void insertion_sort_list(listint_t **list);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
int lomutoPartition(int *array, int start, int end, size_t size);
void quickSort(int *array, int start, int end, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swappingAdjacentNode(listint_t **list, listint_t *firstNode,
		listint_t *secondNode);
void counting_sort(int *array, size_t size);
void pRint_Array(int *array, int start_index, int end_index);
void customCopyFunction(int *found, int start_index, int end_index,
		int *destination);
void mergeArrays(int *found, int start_index, int middle_index,
		int end_index, int *destination);
void mergeSortRecursive(int *found, int start_index,
		int end_index, int *destination);
void merge_sort(int *array, size_t size);
int modifiedParent(int y);
int adjustedLeftChild(int y);
void vert_to_H(int *array, size_t size);
void heapify_Do_win(int *array, size_t size, int begin, int finish);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void meDhatDeif(bool ascending, int *moon, size_t size, size_t fiNAlSize);
void cUStOMmERge(bool ascending, int *moon, size_t size, size_t fiNAlSize);
void biToNicComPare(bool ascending, int *moon, size_t size);



#endif
