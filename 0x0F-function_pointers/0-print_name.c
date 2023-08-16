#include "function_pointers.h"

/**
 * print_name - function that prints a name.
 * @name: the name given
 * @f: function print a name
 *
 * Rteurn: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)

		f(name);
}
