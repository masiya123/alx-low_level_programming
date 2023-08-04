#include "main.h"

/**
 * _isupper - use uppercase letters to check
 * @c: character to check
 *
 * Return: 0 or 1 (Success)
 */
int _isupper(int c)

{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);

}
