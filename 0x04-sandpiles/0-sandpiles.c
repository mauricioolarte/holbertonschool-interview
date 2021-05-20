#include <stdlib.h>
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * isStable - Print 3x3 grid
 * @grid: 3x3 grid
 * Return: 0
 */
int isStable(int grid[3][3])
{
	int i = 0, j = 0, flag = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				flag = 1;
		}
	}
	return (flag);
}

/**
 * sandpiles_sum - Print 3x3 grid
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int flag = 1, i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
	printf("=\n");
	print_grid(grid1);
	while (flag)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (i > 0)
						grid1[i - 1][j] += 1;
					if (j < 2)
						grid1[i][j + 1] += 1;
					if (i < 2)
						grid1[i + 1][j] += 1;
					if (j > 0)
						grid1[i][j - 1] += 1;
					grid1[i][j] -= 4;
				}
			}
		}
		flag = isStable(grid1);
		if (flag)
		{
			printf("=\n");
			print_grid(grid1);
		}
	}
}
