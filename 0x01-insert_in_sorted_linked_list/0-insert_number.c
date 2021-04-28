#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
*insert_node - insert a new node
*@head: head linked list
*@number: number to insert
*Return: null or new node
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *temp;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		while (current->next != NULL)
		{
			if (current->next->n > number)
			{
				temp = current->next;

				current->next = new;
				new->next = temp;
				return (new);
			}
			current = current->next;
		}
	}
	return (NULL);
}
