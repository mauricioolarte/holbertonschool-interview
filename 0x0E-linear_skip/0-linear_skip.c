#include <stdio.h>
#include <stdlib.h>

#include "search.h"

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

	currennode = list;

	currennode = malloc(sizeof(*currennode));
	if (!currennode)
	{
		free_skiplist(currennode);
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
			while (currennode)
			{
				printf("Value checked at index [%li] = [%i]\n",
					   currennode->index, currennode->n);
				if (value == currennode->n)
				{
					return (currennode);
				}
				currennode = currennode->next;
			}
		}
		currennode = currennode->express;
		if (currennode == NULL)
		{
			return (NULL);
		}
	}

	return (list);
}
