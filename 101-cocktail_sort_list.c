#include "sort.h"
#include <stdbool.h>
/**
 * swappingAdjacentNode - swaps two adjacent nodes of a doubly linked list
 * @list: doubly linked list of integers to be sorted
 * @firstNode: node closer to head, secondNode->prev
 * @secondNode: node closer to tail, firstNode->next
 */
void swappingAdjacentNode(listint_t **list,
	listint_t *firstNode, listint_t *secondNode)
{
	listint_t *swap;

	if (firstNode->prev)
	firstNode->prev->next = secondNode;
	else
	*list = secondNode;

	if (secondNode->next)
	secondNode->next->prev = firstNode;
	secondNode->prev = firstNode->prev;
	firstNode->prev = secondNode;
	swap = secondNode;
	firstNode->next = secondNode->next;
	swap->next = firstNode;
	print_list(*list);
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using a cocktail shaker sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	bool forward, backward;
	int shakeRange = 2000000, iterations;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
	return;

	temp = *list;
	do {
	forward = backward = false;
for (iterations = 0; temp->next && iterations
		< shakeRange; iterations++)
	{
	if (temp->next->n < temp->n)
	{
	swappingAdjacentNode(list, temp, temp->next);
	forward = true;
	}
	else
	temp = temp->next;
	}
	if (!temp->next)	/* first loop, measuring list */
	shakeRange = iterations;
	if (forward)
	temp = temp->prev;
	shakeRange--;
	for (iterations = 0; temp->prev && iterations < shakeRange; iterations++)
	{
	if (temp->n < temp->prev->n)
	{
	swappingAdjacentNode(list, temp->prev, temp);
	backward = true;
	}
	else
	temp = temp->prev;
	}
	if (backward)
	temp = temp->next;
	} while (forward || backward);
}

