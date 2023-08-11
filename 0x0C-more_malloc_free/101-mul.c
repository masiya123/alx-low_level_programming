#include "main.h"

/**
 * _print - a string one place to the left and prints the string
 * @str: string to move
 * @l: size of string
 * Return: void
 */
void _print(char *str, int l)
{
	int x, a;

	x = a = 0;
	while (x < l)
	{
		if (str[x] != '0')
			a = 1;
		if (a || x == l - 1)
			_putchar(str[x]);
		x++;
	}

	_putchar('\n');
	free(str);
}

/**
 * mul - program that multiplies a char with a
 * string and places the answer into dest
 * @n: char to multiply
 * @num: string to multiply
 * @num_index: last non NULL index of num
 * @dest: destination of multiplication
 * @dest_index: highest index to start addition
 * Return: pointer to dest, or NULL on failure
 */
char *mul(char n, char *num, int num_index, char *dest, int dest_index)
{
	int i, k, mul, mulrem, add, addrem;

	mulrem = addrem = 0;
	for (i = num_index, i = dest_index; i >= 0; i--, k--)
	{
		mul = (n - '0') * (num[i] - '0') + mulrem;
		mulrem = mul / 10;
		add = (dest[k] - '0') + (mul % 10) + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	for (addrem += mulrem; k >= 0 && addrem; k--)
	{
		add = (dest[k] - '0') + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	if (addrem)
	{
		return (NULL);
	}
	return (dest);
}

/**
 * check_for_digits - function that checks the arguments
 * to ensure they are digits
 * @av: pointer to arguments
 * Return: 0 if digits, 1 if not
 */
int check_for_digits(char **av)
{
	int i, x;

	for (i = 1; i < 3; i++)
	{
		for (x = 0; av[i][x]; x++)
		{
			if (av[i][x] < '0' || av[i][x] > '9')
				return (1);
		}
	}
	return (0);
}

/**
 * init - program thst initializes a string
 * @str: sting to initialize
 * @l: length of strinf
 * Return: void
 */
void init(char *str, int l)
{
	int j;

	for (j = 0; j < l; j++)
		str[j] = '0';
	str[j] = '\0';
}

/**
 * main - function that multiply two numbers
 * @argc: number of arguments
 * @argv: argument vector
 * Return: zero, or exit status of 98 if failure
 */
int main(int argc, char *argv[])
{
	int num1, num2, num3, x, i;
	char *a;
	char *t;
	char e[] = "Error\n";

	if (argc != 3 || check_for_digits(argv))
	{
		for (x = 0; e[x]; x++)
			_putchar(e[x]);
		exit(98);
	}
	for (num1 = 0; argv[1][num1]; num1++)
		;
	for (num2 = 0; argv[2][num2]; num2++)
		;
	num3 = num1 + num2 + 1;
	a = malloc(num3 * sizeof(char));
	if (a == NULL)
	{
		for (x = 0; e[x]; x++)
			_putchar(e[x]);
		exit(98);
	}
	init(a, num3 - 1);
	for (x = num2 - 1, i = 0; x >= 0; x--, i++)
	{
		t = mul(argv[2][x], argv[1], num1 - 1, a, (num3 - 2) - i);
		if (t == NULL)
		{
			for (x = 0; e[x]; x++)
				_putchar(e[x]);
			free(a);
			exit(98);
		}
	}
	_print(a, num3 - 1);
	return (0);
}
