#include "sort.h"
/**
 * selection_sort - sort via selection
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, current, min;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (current = i + 1; current < size; current++)
		{
			if (array[current] < array[min])
				min = current;
		}
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
