#include "substring.h"

/**
 * find_substring -  Finds all the possible substrings.
 * @s: string to scan.
 * @words: Is the array .
 * @nb_words: Is the number of elements.
 * @n: address to store the number of elements.
 * Return: An allocated array.
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int indexx, count, string_l, w_len, checks, i, j, k;
	int *match, *i_arra;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	string_l = strlen(s);
	w_len = strlen(words[0]);
	i_arra = malloc(string_l * sizeof(int));
	if (!i_arra)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);

	for (i = count = 0; i <= string_l - nb_words * w_len; i++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				indexx = i + j * w_len;
				checks = strncmp(s + indexx, *(words + k), w_len);
				if (!*(match + k) && !checks)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(i_arra + count) = i, count += 1;
	}
	free(match);
	*n = count;
	return (i_arra);
}
