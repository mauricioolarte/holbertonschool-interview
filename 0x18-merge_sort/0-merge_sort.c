#include "sort.h"

/**
 * merge - put the temp array into the original
 * @array: array to sort
 * @tempArray: copy of the array to sort
 * @left: left of array;
 * @right: right of array;
 * @mid: middlel point between indexes
 */
void merge(int *array, int *tempArray, int left, int right, int mid)
{
	int start, end, i = left;

	start = left;
	end = mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(tempArray + left, mid - left);
	printf("[right]: ");
	print_array(tempArray + mid, right - mid);
	while (start < mid && end < right)
	{
		if (tempArray[start] < tempArray[end])
		{
			array[i] = tempArray[start];
			start++;
		}
		else
		{
			array[i] = tempArray[end];
			end++;
		}
		i++;
	}
	while (start < mid)
	{
		array[i] = tempArray[start];
		i++;
		start++;
	}
	while (end <= right)
	{
		array[i] = tempArray[end];
		i++;
		end++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_split - splits array calls merge function
 * @array: array to sort
 * @tempArray: tempArray to sort
 * @left: left array
 * @right: right array
 */
void merge_split(int *array, int *tempArray, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (right - left <= 1)
		return;

	merge_split(tempArray, array, left, mid);
	merge_split(tempArray, array, mid, right);
	merge(array, tempArray, left, right, mid);
}

/**
 * merge_sort - sorts an array in ascending order using the MergeSort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tempArray;
	size_t i = 0;

	if (!array || size < 2)
		return;

	tempArray = malloc(size * sizeof(int));
	if (!tempArray)
		return;
	for (; i < size; i++)
		tempArray[i] = array[i];

	merge_split(array, tempArray, 0, size);
	free(tempArray);
}