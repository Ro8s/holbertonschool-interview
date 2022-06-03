#include "lists.h"

/**
 * find_listint_loop - Finds a loop
 * @head: header
 * Return: address of the node or null
 **/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first;
	listint_t *after;

	if (!head)
	{
		return (NULL);
	}
	if (!head->next)
	{
		return (NULL);
	}

	first = head->next;
	after = head->next->next;

	while (after && after->next && first != after)
	{
		first = first->next;
		after = after->next->next;
	}

	if (first != after)
		return (NULL);

	first = head;

	while (first != after)
	{
		first = first->next;
		after = after->next;
	}
	return (first);
}
