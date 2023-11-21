#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array1om[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array2om[] = {2};
	size_t n = sizeof(array1om) / sizeof(array1om[0]);

	print_array(array1om, n);
	printf("\n");
	selection_sort(array1om, n);
	printf("\n");
	print_array(array1om, n);

	selection_sort(array2om, 1);
	printf("\n");
	print_array(array2om, 1);
	return (0);
}
