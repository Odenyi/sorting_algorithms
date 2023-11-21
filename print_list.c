#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int iom;

	iom = 0;
	while (list)
	{
		if (iom > 0)
			printf(", ");
		printf("%d", list->n);
		++iom;
		list = list->next;
	}
	printf("\n");
}
