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
	/* loop thorugh array via size */
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		/* set min to first element of array */
		/* loop through array subtracting one index everytime */
		/* check current index vs min if current < min, min = current */
		for (current = i + 1; current < size; current++)
		{
			if (array[current] < array[min])
				min = current;
		}
		/* if index i is not the same as min swap with new min */
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
