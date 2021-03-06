#include "holberton.h"

/**
 * pr - print
 * @s: string. number
 * Return: void
 */
void pr(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		puts(s + 1);
	}
}

/**
 * dig - check if s is a number.
 * @n: string to check.
 * Return: 0 if s is a number or 1.
 */
int dig(char *n)
{
	int i, digit = 0;

	for (i = 0; n[i] && !digit; i++)
	{
		if (n[i] < '0' || n[i] > '9')
			digit++;
	}
	return (digit);
}

/**
 * operations - multi, adds
 * @num1: first number.
 * @num2: second number.
 * @len1: length of num1.
 * @len2: length of num2.
 * Return: result of multiplies.
 */
char *operations(char *num1, char *num2, int len1, int len2)
{
	char *result = NULL;
	int i, j, carry, len_total = (len1 + len2);

	result = malloc(sizeof(char) * len_total);
	if (!result)
	{
		pr("Error");
		exit(98);
	}
	for (i = 0; i < len_total; i++)
		result[i] = '0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0');
			carry += result[i + j + 1] - '0';
			result[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}
		if (carry)
			result[i + j + 1] = (carry % 10) + '0';
	}
	return (result);
}

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

