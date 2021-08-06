#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * print_values - function to print check values
 *
 * @node: Pointer head of linked list
 * @value: value to search
 *
 * Return: pointer to node that have a value
 */
skiplist_t *print_values(skiplist_t *node, int value)
{
	while (node)
	{
		printf("Value checked at index [%li] = [%i]\n",
			   node->index, node->n);
		if (value == node->n)
			return (node);
		node = node->next;
	}

	return (NULL);
}

/**
 * last_node - run a linked list
 *
 * @list: Pointer head of linked list
 *
 * Return: pointer to last node
 */
skiplist_t *last_node(skiplist_t *list)
{
	skiplist_t *node;

	node = list;
	while (node)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (node);
}

/**
 * linear_skip - function that searches for a value in a sorted skip list
 *
 * @list: Pointer head of linked list
 * @value: value to search
 *
 * Return: pointer to node that have a value
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *currennode;
	skiplist_t *temp;

	if (list == NULL)
		return (NULL);

	currennode = malloc(sizeof(*currennode));
	if (!currennode)
	{
		return (NULL);
	}
	currennode = list;
	while (currennode && currennode->express)
	{
		printf("Value checked at index [%li] = [%i]\n",
			   currennode->express->index, currennode->express->n);
		if (value >= currennode->n && value < currennode->express->n)
		{
			printf("Value found between indexes [%li] and [%li]\n",
				   currennode->index, currennode->express->index);

			temp = print_values(currennode, value);
			if (temp)
				return (temp);
		}
		currennode = currennode->express;
	}
	temp = last_node(currennode);

	printf("Value found between indexes [%li] and [%li]\n",
		   currennode->index, temp->index);
	temp = print_values(currennode, value);
	if (temp)
		return (temp);

	return (NULL);
}
