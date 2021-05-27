#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * lenght_list - prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: number of nodes
 */
int lenght_list(listint_t *head)
{
	int counter = 0;

	listint_t *node = NULL;

	node = malloc(sizeof(listint_t));

	node = head;
	if (node == NULL)
		return (0);

	while (node != NULL)
	{
		counter += 1;
		node = node->next;
	}
	return (counter);
}

/**
 * is_palindrome - prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: number of nodes
 */
int is_palindrome(listint_t **head)
{
	int n = 0, counter = 0, i = 0;
	int *arr = NULL;
	listint_t *temp = NULL;

	if (*head == NULL)
		return (1);

	n = lenght_list(*head);
	if (n == 0)
		return (1);

	arr = malloc(sizeof(int) * n);
	if (arr == NULL)
		return (0);

	temp = malloc(sizeof(listint_t));
	if (temp == NULL)
		return (0);

	temp = *head;

	while (temp != NULL)
	{
		arr[counter] = temp->n;
		counter += 1;
		temp = temp->next;
	}
	for (i = 0; i <= n / 2; i++)
	{
		if (arr[i] != arr[n - 1 - i])
			return (0);
	}
	free(temp);
	return (1);
}
