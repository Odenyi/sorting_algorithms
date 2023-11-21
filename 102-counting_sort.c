#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - Afunction that sorts an array using counting algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int iom = 1;
	int *counter = NULL, kom = 0, jom = 0;

	if (array == NULL || size < 2)
		return;

	kom = array[0];
	for (; iom < size; iom++)
	{
		if (array[iom] > kom)
			kom = array[iom];
	}

	counter = malloc(sizeof(int) * (kom + 1));
	if (counter == NULL)
		return;

	for (jom = 0; jom <= kom; jom++)
		counter[jom] = 0;
	for (i = 0; i < size; i++)
		counter[array[i]] += 1;
	for (jom = 0; jom < kom; jom++)
	{
		counter[jom + 1] += counter[jom];
		printf("%d, ", counter[jom]);
	}
	counter[jom + 1] += counter[jom];
	printf("%d\n", counter[jom + 1]);
	for (iom = 0; iom < size; iom++)
	{
		jom = counter[array[iom]] - 1;
		if (array[iom] != array[jom])
		{
			kom = array[iom];
			array[iom] = array[jom];
			array[jom] = kom;
		}
	}
	free(counter);
}
