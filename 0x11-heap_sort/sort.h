#ifndef SORT_H
#define SORT_H

/**
 * struct MaxHeap - struct
 * @size: integer
 * @array: points to the next node
 *
 * Description: binary tree
 */
struct MaxHeap
{
	size_t size;
	int *array;
};

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
#endif
