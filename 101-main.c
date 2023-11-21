#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list_om;
	listint_t *node_om;
	int *tmp_om;

	list_om = NULL;
	while (size--)
	{
		node_om = malloc(sizeof(*node_om));
		if (!node_om)
			return (NULL);
		tmp_om = (int *)&node_om->n;
		*tmp_om = array[size];
		node_om->next = list_om;
		node_om->prev = NULL;
		list_om = node_om;
		if (list_om->next)
			list_om->next->prev = list_om;
	}
	return (list_om);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list_om;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t nom = sizeof(array) / sizeof(array[0]);

	list_om = create_listint(array, nom);
	if (!list_om)
		return (1);
	print_list(list_om);
	printf("\n");
	cocktail_sort_list(&list_om);
	printf("\n");
	print_list(list_om);
	return (0);
}
