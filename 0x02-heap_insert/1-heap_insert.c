#include <stdlib.h>
#include <stdio.h>
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
	binary_tree_t *currentnode = NULL;

	if (*root == NULL)
	{
		newnode = binary_tree_node(NULL, value);
		*root = newnode;
		return (newnode);
	}
	currentnode = *root;
	while (currentnode != NULL)
	{
		if (value > currentnode->n)
		{
			newnode = binary_tree_node(currentnode->parent, value);
			if (currentnode->parent == NULL)
			{
				*root = newnode;
			}
			currentnode->parent = newnode;
			newnode->left = currentnode;
			return (newnode);
		}
		else if (currentnode->left == NULL)
		{
			newnode = binary_tree_node(currentnode->left, value);
			currentnode->left = newnode;
			newnode->parent = currentnode;
			return (newnode);
		}
		else if (currentnode->right == NULL)
		{
			newnode = binary_tree_node(currentnode->right, value);
			currentnode->right = newnode;
			newnode->parent = currentnode;
			return (newnode);
		}
		currentnode = currentnode->left;
	}
	return (*root);
}
