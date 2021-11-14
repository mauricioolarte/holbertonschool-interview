#include "list.h"

/**
 * add_node_end - add a new node to circular linked list.
 * @list: Lst.
 * @str: String.
 *
 * Return: Address .
 */

List *add_node_end(List **list, char *str)
{
	List *new, *last;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	last->next = new;
	new->next = *list;
	new->prev = last;
	(*list)->prev = new;
	return (new);
}

/**
 * add_node_begin - Add a new node.
 * @list: List.
 * @str: String.
 *
 * Return: Address.
 */

List *add_node_begin(List **list, char *str)
{
	List *new, *last;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->next = (*list);
	new->prev = last;
	(*list)->prev = last->next = new;
	*list = new;
	return (new);
}
