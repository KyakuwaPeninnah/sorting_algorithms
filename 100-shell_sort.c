#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort
 * @array: array pointer
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int k = 1, in, out, temp;

	if (array == NULL || size < 2)
		return;
	while (k <= ((int)size / 3))
		k = (k * 3) + 1;

	while (k > 0)
	{
		for (out = k; out < (int)size; out++)
		{
			temp = array[out];
			in = out;
			while (in >= k && array[in - k] > temp)
			{
				array[in] = array[in - k];
				in = in - k;
			}
			array[in] = temp;
		}
		k = (k - 1) / 3;
		print_array(array, size);
	}
}
