#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 *                       of integers in ascending order using the Insertion
 *                       sort algorithm
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nodeom = NULL, *tmpom = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	nodeom = *list;
	nodeom = nodeom->next;
	while (nodeom)
	{
		while (nodeom->prev && nodeom->n < (nodeom->prev)->n)
		{
			tmpom = nodeom;
			if (nodeom->next)
				(nodeom->next)->prev = tmpom->prev;
			(nodeom->prev)->next = tmpom->next;
			nodeom = nodeom->prev;
			tmpom->prev = nodeom->prev;
			tmpom->next = nodeom;
			if (nodeom->prev)
				(nodeom->prev)->next = tmpom;
			nodeom->prev = tmpom;
			if (tmpom->prev == NULL)
				*list = tmpom;
			print_list(*list);
			nodeom = nodeom->prev;
		}
		nodeom = nodeom->next;
	}

}
