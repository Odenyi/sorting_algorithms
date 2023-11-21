#include "sort.h"

/**
 * selection_sort - A function that use selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int auxom = 0;
	size_t iom = 0, jom = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; iom < size - 1; iom++)
	{
		pos = iom;
		for (jom = iom + 1; jom < size; jom++)
		{
			if (array[jom] < array[pos])
				pos = jom;
		}
		if (pos != iom)
		{
			auxom = array[iom];
			array[iom] = array[pos];
			array[pos] = auxom;
			print_array(array, size);
		}
	}
}
