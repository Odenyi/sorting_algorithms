#include "sort.h"

/**
 * swap_root - A function that swap the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @hi: The higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void swap_root(int *array, size_t root, size_t hi, size_t size)
{
	size_t lo_om = 0, mi_om = 0, tmp_om = 0;
	int aux_om = 0;

	while ((lo_om = (2 * root + 1)) <= hi)
	{
		tmp_om = root;
		mi_om = lo_om + 1;
		if (array[tmp_om] < array[lo_om])
			tmp_om = lo_om;
		if (mi_om <= hi && array[tmp_om] < array[mi_om])
			tmp_om = mi_om;
		if (tmp_om == root)
			return;
		aux_om = array[root];
		array[root] = array[tmp_om];
		array[tmp_om] = aux_om;
		print_array(array, size);
		root = tmp_om;
	}
}

/**
 * heap_sort - A function that sorts an array using heap algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t hi = 0, gap_om = 0;
	int tmp_om = 0;

		if (array == NULL || size < 2)
			return;

		for (gap_om = (size - 2) / 2; 1; gap_om--)
		{
			swap_root(array, gap_om, size - 1, size);
			if (gap_om == 0)
				break;
		}

		hi = size - 1;
		while (hi > 0)
	{
		tmp_om = array[hi];
		array[hi] = array[0];
		array[0] = tmp_om;
		print_array(array, size);
		hi--;
		swap_root(array, 0, hi, size);
	}
}
