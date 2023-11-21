#include "sort.h"

/**
  * shell_sort - A function tat sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int iom = 0, jom = 0, gapom = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	while (gapom < size / 3)
		gapom = gapom * 3 + 1;

	for (; gapom > 0; gapom = (gapom - 1) / 3)
	{
		for (iom = gapom; iom < siomze; iom++)
		{
			aux = array[iom];
			for (jom = iom; jom >= gapom && array[jom - gapom] > aux;
					jom -= gapom)
			{
				if (array[jom] != array[jom - gapom])
					array[jom] = array[jom - gapom];
			}
			if (array[jom] != aux)
				array[jom] = aux;

		}
		print_array(array, size);
	}
}
