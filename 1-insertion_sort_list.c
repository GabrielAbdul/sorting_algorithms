#include "sort.h"
/**
 * insertion_sort_list - sort via insertion
 * @list: listint list given
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *new, *temp;

	if (list == NULL || *list == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		new = current->prev;
		while (new != NULL && current->n < new->n)
		{
			node_swap(list, &new, current);
			print_list(*list);
		}
	}
}

/**
 * node_swap - swaps nodes
 * @head: head of list
 * @new: new list to change
 * @current: current node we would like to switch
 *
 * Return: void
 */
void node_swap(listint_t **head, listint_t **new, listint_t *current)
{
	(*new)->next = current->next;
	if (current->next != NULL)
		current->next->prev = *new;
	current->prev = (*new)->prev;
	current->next = *new;
	if ((*new)->prev != NULL)
		(*new)->prev->next = current;
	else
		*head = current;
	(*new)->prev = current;
	*new = current->prev;
}
