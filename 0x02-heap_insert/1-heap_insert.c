#include <stdlib.h>
#include "binary_trees.h"

/**
**heap_insert - set binary tree node
*@root: pointer;
*@value: value to set in pointer.
*Return: pointer.
*/

heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *newnode = NULL;

	newnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	return (newnode);


}
