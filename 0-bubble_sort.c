#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: an array
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap_occured;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swap_occured = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_occured = 1;
				print_array(array, size);
			}
		}
		if (swap_occured == 0)
			return;
	}

}
