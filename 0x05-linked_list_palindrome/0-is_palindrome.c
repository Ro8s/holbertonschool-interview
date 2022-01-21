#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if it is a palindrome or 0 in another case
 */
int is_palindrome(listint_t **head)
{
listint_t *aux;
int array[1901];
int index = 0;
int i = 0;
int comp;

if (!head)
return (1);
aux = *head;
while (aux)
{
array[index] = aux->n;
index++;
aux = aux->next;
}
comp = index;
for (; i < index / 2; i++)
{
if (array[i] != array[comp - i - 1])
{
return (0);
}
}
return (1);
}
