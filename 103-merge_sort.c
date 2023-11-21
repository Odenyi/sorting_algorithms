#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t iom = 0;
	int *base_om = NULL;

	if (array == NULL || size < 2)
		return;
	base_om = malloc(sizeof(int) * size);
	if (base_om == NULL)
		return;
	for (; iom < size; iom++)
		base_om[iom] = array[iom];
	merge_partition(0, size, array, base_om);
	free(base_om);
}

/**
 * merge - A function that sorts the subarrays.
 * @lo: Lower index.
 * @mi: Middle index.
 * @hi: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src)
{
	size_t iom = 0, jom = 0, kom = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lo, mi - lo);
	printf("[right]: ");
	print_array(src + mi, hi - mi);
	iom = lo;
	jom = mi;
	kom = lo;
		for (; kom < hi; kom++)
		{
			if (iom < mi && (jom >= hi || src[iom] <= src[jom]))
			{
				dest[kom] = src[iom];
				iom++;
			}
			else
			{
				dest[kom] = src[jom];
				jom++;
			}
		}
	printf("[Done]: ");
	print_array(dest + lo, hi - lo);
}

/**
 * merge_partition - A funtion that splits the array recursively.
 * @lo: Lower index.
 * @hi: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * Return: Nothing.
 */
void merge_partition(size_t lo, size_t hi, int *array, int *base)
{
	size_t mi_om = 0;

	if (hi - lo < 2)
		return;
	mi_om = (lo + hi) / 2;
	merge_partition(lo, mi_om, array, base);
	merge_partition(mi_om, hi, array, base);
	merge(lo, mi_om, hi, array, base);
	for (mi_om = lo; mi_om < hi; mi_om++)
		base[mi_om] = array[mi_om];
}
