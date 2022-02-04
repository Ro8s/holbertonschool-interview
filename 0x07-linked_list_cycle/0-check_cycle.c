#include "lists.h"

/**
 * check_cycle - checks if a linked list is cycle
 * @list: linked list
 * Return: 1 or 0
 */
int check_cycle(listint_t *list)
{
listint_t *a, *b;

a = list;
b = list;
while (a && b && b->next)
{
a = a->next;
b = b->next->next;
if (a == b)
return (1);
}
return (0);
}

