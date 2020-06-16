#include "sort.h"

/**
 * quick_sort - implements the Quicksort algorithm
 *
 * @array: input array
 * @size: size of input array
 *
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	int int_size = size;

	if (array)
		quick_sorter(array, size, 0, int_size - 1);
}

/**
 * quick_sorter - sorts input array using quick sort method
 *
 * @array: input array
 * @low: index of first element
 * @high: index of last element
 * @size: size of input array
 *
 * Return: Void
 */
void quick_sorter(int *array, size_t size, int low, int high)
{
	int pos;

	if (low < high)
	{
		pos = lomuto_partition(array, size, low, high);
		quick_sorter(array, size, low, pos - 1);
		quick_sorter(array, size, pos + 1, high);
	}
}

/**
 * lomuto_partition - array sorter
 *
 * @array: input array
 * @low: index of first element
 * @high: index of last element
 * @size: size of input array
 *
 * Return: position
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int index, j, pivot;

	pivot = array[high];
	index = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			index++;
			if (index < j)
			{
				swap(&array[index], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[index + 1] != array[high])
	{
		swap(&array[index + 1], &array[high]);
		print_array(array, size);
	}
	return (index + 1);
}
/**
 * swap - function that swaps two integers
 *
 * @num_one: int to swap
 * @num_two: int to swap
 *
 * Return: void
 */
void swap(int *num_one, int *num_two)
{
	int tmp;

	tmp = *num_one, *num_one = *num_two, *num_two = tmp;
}
