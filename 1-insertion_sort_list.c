#include "sort.h"

/**
 * list_len - Calculates the length of a doubly linked list
 * @list: Pointer to the head of the list
 * Return: Length of the list
 */

size_t list_len(const listint_t *list)
{
	size_t len = 0;
	const listint_t *node = list;

	while (node != NULL)
{
	len++;
	node = node->next;
}

return (len);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			swap_nodes(list, prev, current);
			print_list(*list);
		}
		current = next;
	}
}
