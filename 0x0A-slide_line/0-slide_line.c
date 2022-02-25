#include "slide_line.h"

/**
 * slide_line - function that reporduce 2048 game but in a single line
 * @line: pointer to the array
 * @size: size of array
 * @direction: direction 
 * Return: 1 in success, or 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t indexFind = 0, indexRep = 0, i = 1, stop = size;
	int aux = -1;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		indexFind = size - 1;
		indexRep = size - 1;
		i = -1;
		stop = -1;
	}

	while (indexFind != stop)
	{
		if (line[indexFind] != 0)
		{
			if (aux == line[indexFind])
			{
				line[indexFind] += aux;
				aux = -1;
			}
			else
			{
				aux = line[indexFind];
				if ((direction == SLIDE_LEFT && indexFind != 0)
					||
					((direction == SLIDE_RIGHT && indexFind != (size - 1))))
					if (line[indexRep] != 0)
						indexRep += i;
			}
			line[indexRep] = line[indexFind];
			if (indexRep != indexFind)
				line[indexFind] = 0;
		}
		indexFind += i;
	}

	return (1);
}