#include "sort.h"
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * 			in ascending order using cocktail shaker sort
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swap;
	listint_t *temp;

	if ((!list) || !*list || (*list)->next == NULL)
		return;

	do {
		swap = 0;
		for (; *list  && (*list)->next; list = &(*list)->next)
		{
			if ((*list)->n > (*list)->next->n)
			{
				temp = *list;
				*list = (*list)->next;
				temp->next = (*list)->next;
				(*list)->next = temp;
				
				if (temp->prev)
					temp->prev->next = *list;
				if ((*list)->next)
					(*list)->next->prev = temp;
				temp->prev = (*list)->prev;
				(*list)->prev = temp;

				swap = 1;
				print_list(*list);
			}
		}
		if (!swap)
			break;

		for (; *list && (*list)->prev; list = &(*list)->prev)
		{
			if ((*list)->n < (*list)->prev->n)
			{
				temp = *list;
				*list = (*list)->prev;
				temp->prev = (*list)->prev;
				(*list)->prev = temp;
				temp->next = (*list)->next;
				(*list)->next = temp;

				if (temp->next)
					temp->next->prev = temp;
				if ((*list)->prev)
					(*list)->prev->next = *list;
				swap = 1;
				print_list(*list);
			}
		}
	}
	while (swap);
}

