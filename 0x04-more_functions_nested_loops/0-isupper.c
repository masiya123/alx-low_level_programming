#include "main.h"
/**
 * _isupper - detect upper case alphabets
 *
 * @c: input charater
 *
 * Return: (1) for true (0) false
 *
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
