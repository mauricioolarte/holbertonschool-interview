#include "sort.h"

/**
 * finder_maximum - Finds the maxi integer in an array.
 * @array: Array
 * @size: Size array.
 *
 * Return: max.
 */

int finder_maximum(int *array, int size)
{
	int i, maxi;

	for (maxi = array[0], i = 1; i < size; i++)
		maxi = (array[i] > maxi) ? array[i] : maxi;
	return (maxi);
}

/**
 * counter - Sort the array digit.
 * @array: Array
 * @size: Size array.
 * @tmp: Integer
 *
 * Return:
 */

void counter(int *array, int size, int tmp)
{
	int i, *result, count[10] = {0};

	result = malloc(sizeof(int) * size);
	if (!result)
		return;
	for (i = 0; i < size; i++)
		count[(array[i] / tmp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		result[count[(array[i] / tmp) % 10] - 1] = array[i];
		count[(array[i] / tmp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = result[i];
	free(result);
}

/**
 * radix_sort - Sorts .
 * @array: Array
 * @size: Size
 *
 * Return:
 */

void radix_sort(int *array, size_t size)
{
	int maxi, tmp;

	if (size < 2)
		return;
	for (maxi = finder_maximum(array, size), tmp = 1; maxi / tmp > 0; tmp *= 10)
	{
		counter(array, size, tmp);
		print_array(array, size);
	}
}
