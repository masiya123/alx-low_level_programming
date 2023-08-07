#include "main.h"
#include <stdlib.h>

void util(char **, char *);
void create_word(char **, char *, int, int, int);

/**
 * strtow - function that splits a string
 * @str: the string
 * Return: returns a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int x, flag, len;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	x = flag = len = 0;
	while (str[x])
	{
		if (flag == 0 && str[x] != ' ')
			flag = 1;
		if (x > 0 && str[x] == ' ' && str[x - 1] != ' ')
		{
			flag = 0;
			len++;
		}
		x++;
	}

	len += flag == 1 ? 1 : 0;
	if (len == 0)
		return (NULL);

	words = (char **)malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);

	util(words, str);
	words[len] = NULL;
	return (words);
}

/**
 * util - the util function for fetching words into an array
 * @words: the strings array
 * @str: the string
 */
void util(char **words, char *str)
{
	int x, y, start, flag;

	x = y = flag = 0;
	while (str[x])
	{
		if (flag == 0 && str[x] != ' ')
		{
			start = x;
			flag = 1;
		}

		if (x > 0 && str[x] == ' ' && str[x - 1] != ' ')
		{
			create_word(words, str, start, x, y);
			y++;
			flag = 0;
		}

		y++;
	}

	if (flag == 1)
		create_word(words, str, start, x, y);
}

/**
 * create_word - to creates a word and insert it into the array.
 * @words: the array of strings
 * @str: the string
 * @start: starting index of the word
 * @end: stopping index of the word
 * @index: the index of the array to insert the word
 */
void create_word(char **words, char *str, int start, int end, int index)
{
	int x, y;

	x = end - start;
	words[index] = (char *)malloc(sizeof(char) * (x + 1));

	for (y = 0; start < end; start++, y++)
		words[index][y] = str[start];
	words[index][y] = '\0';
}
