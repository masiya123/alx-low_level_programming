#include "shell.h"

/**
 * check_interactive - checks if shell is in interactive mode
 * @shell_info: pointer to struct containing shell info
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int check_interactive(info_t *shell_info)
{
	return (isatty(STDIN_FILENO) && shell_info->readfd <= 2);
}

/**
 * check_delim - checks if a character is a delimiter
 * @char_to_check: the character to check
 * @delim_string: the delimiter string
 * Return: 1 if true (character is a delimiter), 0 if false
 */
int check_delim(char char_to_check, char *delim_string)
{
	while (*delim_string)
		if (*delim_string++ == char_to_check)
			return (1);
	return (0);
}

/**
 * check_alpha - checks if a character is alphabetic
 * @char_input: The character to check
 * Return: 1 if char_input is alphabetic, 0 otherwise
 */
int check_alpha(int char_input)
{
	if ((char_input >= 'a' && char_input <= 'z') ||
	(char_input >= 'A' && char_input <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * convert_to_int - converts a string to an integer
 * @str_input: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int convert_to_int(char *str_input)
{
	int index, sign_flag = 1, num_flag = 0, final_output;
	unsigned int result = 0;

	for (index = 0;  str_input[index] != '\0' && num_flag != 2; index++)
	{
		if (str_input[index] == '-')
			sign_flag *= -1;

		if (str_input[index] >= '0' && str_input[index] <= '9')
		{
			num_flag = 1;
			result *= 10;
			result += (str_input[index] - '0');
		}
		else if (num_flag == 1)
			num_flag = 2;
	}

	if (sign_flag == -1)
		final_output = -result;
	else
		final_output = result;

	return (final_output);
}

