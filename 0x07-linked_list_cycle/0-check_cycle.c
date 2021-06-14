#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - list
 * @list: linked list
 * Return: int
 * Description: singly linked list node structure
 *
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (list == NULL)
		return (0);

	fast = list;
	slow = list;

	while (slow != NULL || fast)
	{
		while (fast != NULL && fast != list)
		{
			if (fast->next && fast->next == slow)
			{
				return (1);
			}
			fast = fast->next;
		}
		if (slow->next)
		{
			slow = slow->next;
			fast = slow->next;
		}
		slow = slow->next;
		fast = slow->next;
	}

	return (0);
}
