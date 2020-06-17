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

	/* check to make sure that the list is not NULL */
	if (list == NULL || *list == NULL)
		return;
	/* loop through the entire list setting current to list */
	/* and temp to list->next every iteration sets current to temp */
	/* or list->next */
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		new = current->prev;
		/* new is set to current->prev, swaps nodes until */
		/* current->n is less than new->n and is put in the correct position */
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
	/* set new->next to number after current */
	(*new)->next = current->next;
	/* set currents->next->prev to new */
	if (current->next != NULL)
		current->next->prev = *new;
	/* sets current-prev to new->prev */
	current->prev = (*new)->prev;
	/* sets current next to new */
	current->next = *new;
	/* sets number in front of new, sets there next to current */
	if ((*new)->prev != NULL)
		(*new)->prev->next = current;
	else
		*head = current;
	(*new)->prev = current;
	/* moves new down for while loop */
	*new = current->prev;
}
