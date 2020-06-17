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
		/* petition our array using lomuto style */
		pos = lomuto_partition(array, size, low, high);
		/* Recursive call to quick sort on each partitioned array */
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

	pivot = array[high]; /* make our pivot the last element in the array */
	index = low - 1; /* our index starts at -1, 1 less than the size of array */
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot) /* if the element we're at is lower than our pivot */
		{
			index++; /* increment index to be to be the first element in the array */
			if (index < j)
			{
				swap(&array[index], &array[j]); /* swap the two elements */
				print_array(array, size);
			}
		}
	}
	/* if the element we're at is not the last one */
	if (array[index + 1] != array[high])
	{
		/* swap em */
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

	/* Used pointers because we're dealing with an array */
	tmp = *num_one, *num_one = *num_two, *num_two = tmp;
}
