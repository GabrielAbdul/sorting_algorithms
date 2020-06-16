#include "sort.h"

/**
 * max_num - function that returns max num in an array
 *
 * @array: input array
 *
 * Return: (void)
 */
int max_num(int *array)
{
	int i = 0, max = 0;

	while (array[i])
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * _memset - initialize array elements with value
 *
 * @array: input array
 * @value: value to initialize array to
 * @size: size of input array
 *
 * Return: (void)
 */
void _memset(int *array, int value, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = value;
}

/**
 * count - function that returns the count of an element in the input array
 *
 * @array: input array of positive ints
 * @size: size of input array
 * @value: value to count
 *
 * Return: int, occurences of value in array
 */
int count(int *array, size_t size, int value)
{
	int i, count;

	for (i = 0; i < size; i++)
	{
		if (array[i] == value)
			count++;
	}
	return (count);
}

/**
 * counting_sort - sorts an array of ints in ascending order
 * using the Counting sort algorithm
 *
 * @array: input array
 * @size: size of input array
 *
 * Return: (void)
 */

void counting_sort(int *array, size_t size)
{
	int max, j;
	int *occurrences, *result;
	size_t i;

	if (!array || size < 2)
		return;

	max = max_num(array);
	occurrences = malloc(sizeof(int) * (max + 1));
	if (!occurrences)
		return;
	result = malloc(sizeof(int) * size);
	if (!result)
		return;
	_memset(occurrences, 0, max + 1);

	for (i = 0; i < size; i++)
	{
		occurrences[i] = count(array, size, array[i]);
	}

	print_array(occurrences, max + 1);
 
	
}
