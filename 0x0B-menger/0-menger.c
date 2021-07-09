#include "menger.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * menger - graphic menger sponge
 * @level: Level menger sponge
 */
void menger(int level)
{
	int size = 0, j = 0, k = 0, moveonx = 0, moveony = 0;
	char character;

	size = pow(3, level);

	while (j < size)
	{
		for (k = 0; k < size;)
		{
			character = '#';
			moveonx = j;
			moveony = k++;
			while (moveony > 0 || moveonx > 0)
			{
				if (moveony % 3 == 1 && moveonx % 3 == 1)
				{
					character = ' ';
				}
				moveonx = moveonx / 3;
				moveony = moveony / 3;
			}
			printf("%c", character);
		}
		printf("\n");
		j++;
	}
}
