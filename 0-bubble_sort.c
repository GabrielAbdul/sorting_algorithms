#include "sort.h"

/**
 * bubble_sort - simplest sorting algorithm that swaps
 * adjacent elements if they are in the wrong order
 *
 * @array: input array
 * @size: size of input array
 *
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int is_sorted = 0, tmp;

	while (!is_sorted)
	{
		is_sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				is_sorted = 0;
			}
		}
	}
}
