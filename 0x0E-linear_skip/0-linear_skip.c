#include "search.h"
/**
 * sc - search for a value.
 * @b: main node
 * @end: final node
 * @value: value to search
 * Return: NULL if not found or the node
 */
skiplist_t *sc(skiplist_t *b, skiplist_t *end, int value)
{
	char *format = "Value found between indexes [%li] and [%li]\n";
	char *fmt = "Value checked at index [%li] = [%i]\n";

	printf(format, b->index, end->index);
	while (b != end->next)
	{
		printf(fmt, b->index, b->n);
		if (value == b->n)
			return (b);
		b = b->next;
	}
	return (NULL);
}
/**
 * linear_skip - search for a number in a linear skip
 * @head: list of type skiplis_t
 * @value: value to search into list
 * Return: NULL or node with the value
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *b, *end;
	char *format = "Value checked at index [%li] = [%i]\n";

	if (!head)
		return (NULL);
	end = head;
	while (end && end->next && end->n < value)
	{
		b = end;
		if (!end->express)
		{
			while (end->next)
				end = end->next;
			continue;
		}
		else
			end = end->express;
		printf(format, end->index, end->n);
	}
	return (sc(b, end, value));
}