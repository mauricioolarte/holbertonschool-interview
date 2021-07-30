#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 *  sorted_array_to_avl - Entry point
 * @array: array
 * @size: lenght array
 * Return: avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t midle;

	int *left_array = NULL;
	int *right_array = NULL;

	avl_t *root;

	if (size % 2 == 1)
		midle = size / 2;
	else
		midle = (size / 2) + 1;

	*left_array = *array;

	*right_array = *(array + midle + 1);

	root = (avl_t *)malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);

	root->n = *(array + midle);
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;

	return (root);
}
