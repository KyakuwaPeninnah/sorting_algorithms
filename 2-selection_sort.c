#include "sort.h"

/**
 * selection_sort - sorts an array
 * @array: pointer
 * @size: size of the array
 * Returns: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, k, idx;
	int j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		j = array[i];
		idx = i;
		for (k = i; k < size; k++)
		{
			if (j > array[k])
			{
				idx = k;
				j = array[k];
			}
		}
		if (j == array[i] && idx == i)
			continue;
		array[idx] = array[i];
		array[i] = j;
		print_array(array, size);
	}
}
