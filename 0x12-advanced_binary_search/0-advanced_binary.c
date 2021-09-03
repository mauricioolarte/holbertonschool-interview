#include <stdio.h>

#include "search_algos.h"

/**
* print_array - print values array
* @array: pointer to init array
* @start_index: index to init print
* @end_index: index to end print
*/
void print_array(int *array, size_t start_index, size_t end_index)
{
	size_t i = 0;

	printf("Searching in array: ");
	for (i = start_index; i <= end_index; i++)
	{
		if (i == end_index)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
}

/**
* recursiveBinarySearch - print values array
* @array: pointer to init array
* @start_index: index to init print
* @end_index: index to end print
* @element: value to search
* Return: index of value or -1 if no value
*/
int recursiveBinarySearch(int array[], size_t start_index,
													size_t end_index, int element)
{

	print_array(array, start_index, end_index);
	if (array == NULL)
		return (-1);

	if (end_index >= start_index)
	{
		int middle = start_index + (end_index - start_index) / 2;

		if (array[middle] == element)
		{
			if (array[middle - 1] == element)
			{
				return (recursiveBinarySearch(array, start_index, middle, element));
			}
			return (middle);
		}

		if (array[middle] > element)
			return (recursiveBinarySearch(array, start_index, middle - 1, element));
		return (recursiveBinarySearch(array, middle + 1, end_index, element));
	}
	return (-1);
}

/**
* advanced_binary - print values array
* @array: pointer to init array
* @size: size array
* @value: value to search
* Return: index of value or -1 if no value
*/
int advanced_binary(int *array, size_t size, int value)
{
	int res = 0;

	if (array == NULL)
	{
		printf("Searching in array:\n");
		return (-1);
	}

	res = recursiveBinarySearch(array, 0, size - 1, value);

	return (res);
}
