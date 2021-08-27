#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * swap - change values
 * @a: integer
 * @b: points to the next node
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * maxHeapify - binary
 * @maxHeap: integer
 * @idx: points to the next node
 *
 * Return: void
 */
void maxHeapify(struct MaxHeap *maxHeap, size_t idx)
{
	size_t largest = idx;
	size_t left = (idx << 1) + 1;
	size_t right = (idx + 1) << 1;

	if (left < maxHeap->size &&
			maxHeap->array[left] > maxHeap->array[largest])
		largest = left;

	if (right < maxHeap->size &&
			maxHeap->array[right] > maxHeap->array[largest])
		largest = right;

	if (largest != idx)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}

/**
 * createAndBuildHeap - change values
 * @array: integer
 * @size: points to the next node
 *
 * Return: void
 */
struct MaxHeap *createAndBuildHeap(int *array, size_t size)
{
	int i;
	struct MaxHeap *maxHeap;

	maxHeap =
			(struct MaxHeap *)malloc(sizeof(struct MaxHeap));
	maxHeap->size = size;
	maxHeap->array = array;

	for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
		maxHeapify(maxHeap, i);
	return (maxHeap);
}

/**
 * heap_sort - change values
 * @array: integer
 * @size: points to the next node
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	struct MaxHeap *maxHeap = createAndBuildHeap(array, size);

	if (size < 2)
		return;
	while (maxHeap->size > 1)
	{

		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
		--maxHeap->size;

		maxHeapify(maxHeap, 0);
		print_array(array, size);
	}
}
