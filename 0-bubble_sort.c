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

	if (size > 1 && array)
	{
		while (!is_sorted) /* while our array is not sorted */
		{
			is_sorted = 1; /* assume our array is sorted */
			for (i = 0; i < size - 1; i++)
			{
				/* if our array is not sorted */
				if (array[i] > array[i + 1])
				{
					tmp = array[i]; /* Perform a basic swap */
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					print_array(array, size);
					/* array isnt sorted as we just performed a swap*/
					is_sorted = 0;
				}
			}
		}
	}
}
