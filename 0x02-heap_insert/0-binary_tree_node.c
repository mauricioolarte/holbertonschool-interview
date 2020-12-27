#include <stdlib.h>
#include "binary_trees.h"

/**
**binary_tree_node - set binary tree node
*@parent: pointer;
*@value: value to set in pointer.
*Return: pointer.
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = NULL;

	if (parent == NULL)
	{
		newnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
		if (newnode == NULL)
			return (NULL);
		newnode->n = value;

		return (newnode);
	}
	if (parent->left == NULL)
	{
		newnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
		if (newnode == NULL)
			return (NULL);
		parent->left = newnode;
		newnode->n = value;
		newnode->parent = parent;

		return (newnode);
	} else if (parent->right == NULL)
	{
		newnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
		if (newnode == NULL)
			return (NULL);
		parent->right = newnode->parent;
		newnode->n = value;

		return (newnode);
	}
	return (NULL);
}
