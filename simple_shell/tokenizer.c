#include "shell.h"

/**
 * **split_string - splits a string into words. Repeat delimiters are ignored
 * @input_str: the input string
 * @delimiter: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string(char *input_str, char *delimiter)
{
	int i, j, k, m, num_words = 0;
	char **output_str;

	if (input_str == NULL || input_str[0] == 0)
		return (NULL);
	if (!delimiter)
		delimiter = " ";
	for (i = 0; input_str[i] != '\0'; i++)
		if (!is_delim(input_str[i], delimiter) && (is_delim(input_str[i + 1], delimiter) || !input_str[i + 1]))
			num_words++;

	if (num_words == 0)
		return (NULL);
	output_str = malloc((1 + num_words) * sizeof(char *));
	if (!output_str)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (is_delim(input_str[i], delimiter))
			i++;
		k = 0;
		while (!is_delim(input_str[i + k], delimiter) && input_str[i + k])
			k++;
		output_str[j] = malloc((k + 1) * sizeof(char));
		if (!output_str[j])
		{
			for (k = 0; k < j; k++)
				free(output_str[k]);
			free(output_str);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			output_str[j][m] = input_str[i++];
		output_str[j][m] = 0;
	}
	output_str[j] = NULL;
	return (output_str);
}

/**
 * **split_string2 - splits a string into words
 * @input_str: the input string
 * @delimiter: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **split_string2(char *input_str, char delimiter)
{
	int i, j, k, m, num_words = 0;
	char **output_str;

	if (input_str == NULL || input_str[0] == 0)
		return (NULL);
	for (i = 0; input_str[i] != '\0'; i++)
		if ((input_str[i] != delimiter && input_str[i + 1] == delimiter) ||
		    (input_str[i] != delimiter && !input_str[i + 1]) || input_str[i + 1] == delimiter)
			num_words++;
	if (num_words == 0)
		return (NULL);
	output_str = malloc((1 + num_words) * sizeof(char *));
	if (!output_str)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (input_str[i] == delimiter && input_str[i] != delimiter)
			i++;
		k = 0;
		while (input_str[i + k] != delimiter && input_str[i + k] && input_str[i + k] != delimiter)
			k++;
		output_str[j] = malloc((k + 1) * sizeof(char));
		if (!output_str[j])
		{
			for (k = 0; k < j; k++)
				free(output_str[k]);
			free(output_str);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			output_str[j][m] = input_str[i++];
		output_str[j][m] = 0;
	}
	output_str[j] = NULL;
	return (output_str);
}

