#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
*new_node - insert a new node
*@number: number to insert
*Return: null or new node
*/

listint_t *new_node(int number)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	return (new);
}
/**
*insert_node - insert a new node
*@head: head linked list
*@number: number to insert
*Return: null or new node
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *temp;
	listint_t *new;

	new = new_node(number);
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	current = *head;
	if (current->n > number)
	{
		*head = new;
		(*head)->next = current;
		return (new);
	}

	if (current->next == NULL)
	{
		current->next = new;
		return (new);
	}
	else
	{
		while (current->next != NULL)
		{
			if (current->next->n >= number)
			{
				temp = current->next;
				current->next = new;
				new->next = temp;
				return (new);
			}
			current = current->next;
		}
	}
	current->next = new;
	return (new);
}
