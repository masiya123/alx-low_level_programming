#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: numner of argument
 * @argv: arguments
 * Return: Always 0 (success)
 */
int main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
