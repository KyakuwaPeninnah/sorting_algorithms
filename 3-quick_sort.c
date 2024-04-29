#include "sort.h"

/**
 * quick_sort - sorts an array using quick sort
 * @array: array pointer
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	rs(array, 0, (int)size - 1, size);
}


/**
 * rs - recusion function of the quick sort
 * @arr: an array
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: void
 */

void rs(int *arr, int low, int high, size_t size)
{
	int k;

	if (low >= high)
		return;

	k = partition(arr, low, high, size);

	if (k - low > 1)
		rs(arr, low, k - 1, size);
	if (high - k > 1)
		rs(arr, k + 1, high, size);
}


/**
 * partition - lomuto partition implementation
 * @arr: an array
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: new index of the pivot
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pvt = arr[high], i = low - 1, t, temp;

	for (t = low; t < high; t++)
	{
		if (arr[t] < pvt)
		{
			++i;
			if (t != i)
			{
				temp = arr[t];
				arr[t] = arr[i];
				arr[i] = temp;
				print_array(arr, size);
			}
		}
	}
	if (i < high - 1)
	{
		if (arr[i + 1] != arr[high])
		{
			temp = arr[high];
			arr[high] = arr[i + 1];
			arr[i + 1] = temp;
			print_array(arr, size);
		}
		return (i + 1);
	}

	return (high);
}
