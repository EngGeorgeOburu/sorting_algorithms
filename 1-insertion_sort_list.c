#include "sort.h"

/**
 * insert_sort_list - Sorts a doubly linked list of intergers in 
 *                      ascedning order using Insertion sort algorithms
 * @list: Pointer to a pointer to the head node of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *temp, *current, *prev_2;
 
    if (list == NULL || *list == NULL)
        return;

    current = *list;

    while ((current = current->next))
    {
        temp = current;

        while (temp->prev && temp->n < temp->prev->n)
        {
            prev_2 = temp->prev;

            if (temp->next)
                temp->next->prev = prev_2;
            if (prev_2->prev)
                prev_2->prev->next = temp;
            else
                *list = temp;
            prev_2->next = temp->next;
            temp->next = prev_2->prev;
            temp->next = prev_2;
            prev_2->prev = temp;

            print_list(*list);
        }
    }
}


