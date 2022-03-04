#include "menger.h"

/**
* menger - prints a menger sponge
* @level: sponge level
* Return: -
*/
void menger(int level)
{
	int x = 0, y = 0, s_s = pow(3, level), space = 0, sx = 0, sy = 0;

	for (x = 0; x < s_s; x++)
	{
		for (y = 0; y < s_s; y++)
		{
			for (sx = x, sy = y, space = 0; sx || sy; sx /= 3, sy /= 3)
				if (sx % 3 == 1 && sy % 3 == 1)
					space = 1;
			printf("%c", space ? ' ' : '#');
		}
		printf("\n");
	}
}
