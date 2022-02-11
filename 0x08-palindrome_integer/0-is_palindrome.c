#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"
/**
 *is_palindrome - function that checks if a number is pal.
 *@n: Number
 *Return: 1 if it's pal or 0 otherwise
 */

int is_palindrome(unsigned long n)
{
int rev = 0
int rem;
int orig = n;

while (n != 0)
{
rem = n % 10;
rev = rev * 10 + rem;
n /= 10;
}
if (orig == rev)
return (1);
else
return (0);
}
