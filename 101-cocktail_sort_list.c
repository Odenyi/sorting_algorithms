#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int iom = lo - 1, jom = lo;
	int pivot = array[hi], aux = 0;

	for (; jom < hi; jom++)
	{
		if (array[jom] < pivot)
		{
			iom++;
			if (array[iom] != array[jom])
			{
				aux = array[iom];
				array[iom] = array[jom];
				array[jom] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[iom + 1] != array[hi])
	{
		aux = array[iom + 1];
		array[iom + 1] = array[hi];
		array[hi] = aux;
		print_array(array, size);
	}
	return (iom + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lo, int hi, size_t size)
{
	int pivot_om;

	if (lo < hi)
	{
		pivot_om = partition(array, lo, hi, size);
		quick_s(array, lo, pivot_om - 1, size);
		quick_s(array, pivot_om + 1, hi, size);
	}
}
