#include "sort.h"

/**
 *insertion_sort_list - sorts a doubly linked list of ints in ascending order
 *@list: pointer to the linked list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *firstcomp;
	listint_t *secondcomp;
	listint_t *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;
	firstcomp = (*list)->next;
	while (firstcomp != NULL)
	{
		temp = firstcomp->prev;
		secondcomp = firstcomp->next;
		while (firstcomp->n < temp->n)
		{
			secondcomp = firstcomp->next;
			if (temp->prev != NULL)
				temp->prev->next = firstcomp;
			firstcomp->prev = temp->prev;
			temp->prev = firstcomp;
			firstcomp->next = temp;
			temp->next = secondcomp;
			if (secondcomp != NULL)
				secondcomp->prev = temp;
			if (firstcomp->prev == NULL)
				(*list) = firstcomp;
			print_list(*list);
			temp = firstcomp->prev;
		}
		firstcomp = secondcomp;
	}
}

