#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "slide_line.h"

/**
 * left - function to slide and merge
 *
 * @line: pointer to array
 * @size: size of array
 */
void left(int *line, size_t size)
{
	size_t signus = 1, i = 0;

	for (i = 0; i < size - 1; i++)
	{
		size_t index = i + 1;

		while (index)
		{
			if (*(line + index - signus) == 0 && (line + index) != 0)
			{
				*(line + index - signus) = *(line + index);
				*(line + index) = 0;
			}
			if (*(line + index - signus) == *(line + index))
			{
				*(line + index - signus) += *(line + index);
				*(line + index) = 0;
			}
			index -= 1;
		}
	}
}

/**
 * right - function to slide and merge
 *
 * @line: pointer to array
 * @size: size of array
 */
void right(int *line, size_t size)
{
	size_t signus = -1, i = 0;

	for (i = size - 1; i > 0; i--)
	{
		size_t index = i - 1;

		while (index)
		{
			if (*(line + index - signus) == 0 && (line + index) != 0)
			{
				*(line + index - signus) = *(line + index);
				*(line + index) = 0;
			}
			if (*(line + index - signus) == *(line + index))
			{
				*(line + index - signus) += *(line + index);
				*(line + index) = 0;
			}
			index -= 1;
		}
	}
}

/**
 * slide_line - function to slide and merge
 *
 * @line: pointer to array
 * @size: size of array
 * @direction: slide right or left
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != 1 && direction != 2)
		return (0);

	if (direction == 2)
		right(line, size);
	if (direction == 1)
		left(line, size);
	return (1);
}
