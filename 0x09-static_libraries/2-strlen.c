#include "main.h"
/**
 * _strlen - program returns the length of a string
 * @s: string
 * Return: 0 is success
 */
int _strlen(char *s)
{
	int a = 0;

	for (; *s++;)
		a++;
	return (a);
}
