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
	listint_t *listom;
	listint_t *nodeom;
	int *tmpom;

	listom = NULL;
	while (size--)
	{
		nodeom = malloc(sizeof(*nodeom));
		if (!nodeom)
			return (NULL);
		tmpom = (int *)&nodeom->n;
		*tmpom = array[size];
		nodeom->next = listom;
		nodeom->prev = NULL;
		listom = nodeom;
		if (listom->next)
			listom->next->prev = listom;
	}
	return (listom);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *listom;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	listom = create_listint(array, n);
	if (!listom)
		return (1);
	print_list(listom);
	printf("\n");
	insertion_sort_list(&listom);
	printf("\n");
	print_list(listom);
	return (0);
}
