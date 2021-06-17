#include <stdio.h>

/**
 * is_palindrome - check if a number is palindrome
 * @n: unsigned long number to check
 * Return: 0 0r 1
*/

int is_palindrome(unsigned long n)
{
	unsigned long r, sum = 0, temp;

	temp = n;

	while (n > 0)
	{
		r = n % 10;
		sum = (sum * 10) + r;
		n = n / 10;
	}
	if (temp == sum)
	{
		return (1);
	}
	return (0);
}
