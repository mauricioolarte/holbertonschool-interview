#include "lists.h"

/**
 * find_listint_loop - check if there are a loop in a linked list.
 * @head: pointer to first element of a list.
 * Return: address the loop init, or NULL if not loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast;
	listint_t *slow;

	if (head == NULL)
		return (NULL);

	fast = head;
	slow = head;

	while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}
