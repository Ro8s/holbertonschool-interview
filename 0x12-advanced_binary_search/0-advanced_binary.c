#include "search_algos.h"

/**
 * advanced_binary - binary serch
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search
 * Return: index of the value
 */
int advanced_binary(int *array, size_t size, int value)
{
	int pichu = 1;
	size_t i = 0, j = 0, res = 0;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i == size - 1)
			printf("\n");
		else
			printf(", ");
	}

	res = (size - 1) / 2;
	if (array[res] == value)
	{
		if (size == 1 || array[res - 1] < value)
			return (res);
	}
	else if (size == 1)
	{
		return (-1);
	}

	if (array[res] < value)
	{
		j += res + 1, array += res + 1;
		if (size % 2 != 0)
			res--;
	}
	res++;

	pichu = advanced_binary(array, res, value);
	if (pichu != -1)
		return (pichu + j);
	return (-1);
}

