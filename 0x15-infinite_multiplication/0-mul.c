#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * print_num - prints an array of integers like a number
 * @valAcum: array 
 * @size: size 
 */
void print_num(int *valAcum, int size)
{
	int i = 0;

	if (!valAcum && !size)
	{
		printf("0\n");
		exit(0);
	}
	while (valAcum[i] == 0)
		i++;
	for (; i < size; i++)
	{
		printf("%d", valAcum[i]);
	}
	printf("\n");
}

/**
 * multiply - multiplies two large numbers
 * @mult1: string 
 * @mult2: string 
 * Return: 1 on success, 0 on failure
 */
int multiply(char *mult1, char *mult2)
{
	int i, j;
	int len1, len2, acumprod, n1, n2 = 0;
	int *valAcum;

	len1 = strlen(mult1);
	len2 = strlen(mult2);

	valAcum = calloc(len1 + len2, sizeof(len1 + len2));
	if (!valAcum)
		return (0);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = mult1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = mult2[j] - '0';
			acumprod = (n1 * n2) + valAcum[i + j + 1];
			valAcum[i + j] += acumprod / 10;
			valAcum[i + j + 1] = acumprod % 10;
		}
	}
	print_num(valAcum, len1 + len2);
	free(valAcum);
	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: number
 * @argv: number
 * Return: 0 in success, 1 on failure
 */
int main(int argc, char **argv)
{
	int i, j = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; argv[i]; i++)
		for (j = 0; argv[i][j]; j++)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(98);
			}

	if (*argv[1] == '0' || *argv[2] == '0')
		print_num(NULL, 0);
	if (!multiply(argv[1], argv[2]))
		return (1);
	return (0);
}
