#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
*Insert_node - insert a new node
*@head: head linked list
*@number: number to insert
*Return: null or new node
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newnode = NULL;
	listint_t *temporal = NULL;
	
	if ((*head) == NULL)
	{
		return (NULL);
	}
	temporal = (listint_t *) malloc(sizeof(listint_t));
	if (temporal == NULL)
	{
		return (NULL);
	}
	temporal = (*head);
	while(temporal)
	{
		if (temporal->next && (temporal->next->n >= number))
		{
			if (temporal->n <= number)
			{
				newnode = malloc(sizeof(listint_t));
				if (newnode == NULL){
				return (NULL);
			}
			newnode->n = number;
			newnode->next = temporal->next;
			temporal->next = newnode;
			return(newnode);
		}         
		if(temporal->next)
		{
			temporal = temporal->next;
		}
		else
		{
			return(NULL);
		}
	}
	return(NULL);
}
