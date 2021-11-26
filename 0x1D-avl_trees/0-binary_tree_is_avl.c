#include "binary_trees.h"

/**
 * height - height of tree.
 * @tree: Pointer.
 * Return: Heigh.
 */

size_t height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree == NULL)
		return (0);
	if (tree->right)
		right += height(tree->right) + 1;
	if (tree->left)
		left += height(tree->left) + 1;
	return (right < left ? left : right);
}

/**
 * is_avl - Checks if is an AVL.
 * @tree: Pointer .
 * @max: Max .
 * @min: Min.
 * Return: 1.
 */

size_t is_avl(const binary_tree_t *tree, int max, int min)
{
	size_t l = height(tree->left);
	size_t r = height(tree->right);

	if (tree == NULL)
		return (0);
	l = l > r ? l - r : r - l;
	if (l > 0)
		return (0);
	l = 1;
	r = 1;
	if (tree->left)
	{
		if ((tree->left->n >= tree->n) || (tree->left->n <= min))
			return (0);
		l = is_avl(tree->left, tree->n, min);
	}
	if (tree->right)
	{
		if ((tree->right->n <= tree->n) || (tree->right->n >= max))
			return (0);
		r = is_avl(tree->right, max, tree->n);
	}
	return (r == 1 && l == 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree .
 * @tree: root node.
 * Return: 1 if is AVL Tree.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MAX, INT_MIN));
}
