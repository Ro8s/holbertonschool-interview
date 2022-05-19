#include "holberton.h"

/**
 * main - multiplies two positive numbers.
 * @av: arguments value (num1, num2)
 * @ac: arguments count
 * Return: on success 0 or 98 on error.
 */
int main(int ac, char **av)
{
	int len1 = 0, len2 = 0;
	char *num1 = av[1], *num2 = av[2], *result = NULL;

	if (ac != 3 || dig(num1) || dig(num2))
	{
		pr("Error");
		exit(98);
	}
	if (av[1][0] == 48 || av[2][0] == 48)
	{
		pr("0");
		exit(0);
	}
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = operations(num1, num2, len1, len2);
	if (result[0] == '0')
		pr(result + 1);
	else
		pr(result);
	free(result);
	return (0);
}

