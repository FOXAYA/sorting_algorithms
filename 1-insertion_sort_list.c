#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *node = (*list)->next;

if (list == NULL || (*list)->next == NULL)
return;
do {
while ((node->prev) && (node->prev->n > node->n))
{
node = swap_node(node, list);
print_list(*list);
}
node = node->next;
} while (node);
}

/**
 * swap_node - Swaps a node with its previous node in a doubly linked list.
 * @node: Pointer to the node to be swapped.
 * @list: Pointer to the head of the linked list.
 * Return: Pointer to the node that was entered.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
listint_t *back = node->prev, *current = node;
/*NULL, 19, 48, 9, 71, 13, NULL*/

back->next = current->next;
if (current->next)
current->next->prev = back;
current->next = back;
current->prev = back->prev;
back->prev = current;
if (current->prev)
current->prev->next = current;
else
*list = current;
return (current);
}
