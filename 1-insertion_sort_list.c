#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: pointer
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *temp;

	if (list == NULL || (*list) == NULL)
		return;
	head = *list;
	head = head->next;
	while (head != NULL)
	{
		current = head;
		head = head->next;
		temp = current->prev;
		while (current && temp)
		{
			if (current->n < temp->n)
			{
				if (current->prev != NULL)
				{
					current->prev->next = current->next;
				}
				if (current->next != NULL)
				{
					current->next->prev = current->prev;
				}
				current->next = temp;
				if (temp->prev)
					temp->prev->next = current;
				current->prev = temp->prev;
				temp->prev = current;
				if (current->prev == NULL)
				{
					*list = current;
					print_list(*list);
					break;
				}
				temp = current->prev;
				print_list(*list);
			} else
				temp = temp->prev;
		}
	}
}
