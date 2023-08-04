#include <stdio.h>

/**
 * main - program thats prints all arguments it receives.
 * @argc: number of argument count
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
