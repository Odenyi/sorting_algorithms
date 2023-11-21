#include "sort.h"

/**
  * bubble_sort - A function for bubble sorting.
  * @array: The array to sort.
  * @size: THe length of the aaray.
  * Return: Nothing.
  */
void bubble_sort(int *array, size_t size)
{
	size_t iom = 0, jom = 0;
	int aux_om = 0;

	if (array == NULL || size == 0)
		return;
	for (; iom < size - 1; iom++)
	{
		for (jom = 0; jom < size - iom - 1; jom++)
		{
			if (array[jom] > array[jom + 1])
			{
				aux_om = array[jom + 1];
				array[jom + 1] = array[jom];
				array[jom] = aux_om;
				print_array(array, size);
			}
		}
	}
}
