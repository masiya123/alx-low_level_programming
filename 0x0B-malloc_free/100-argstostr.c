#include "main.h"
#include <stdlib.h>

/**
 * argstostr - function that concatenates all the arguments of your program.
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: a pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str, *s;
	int x, y, i, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (x = 0; x < ac; x++)
	{
		s = av[x];
		y = 0;

		while (s[y++])
			len++;
		len++;
	}

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	for (x = 0, y = 0; x < ac && y < len; x++)
	{
		s = av[x];
		i = 0;

		while (s[i])
		{
			str[y] = s[i];
			i++;
			y++;
		}
		str[y++] = '\n';
	}
	str[y] = '\0';

	return (str);
}
