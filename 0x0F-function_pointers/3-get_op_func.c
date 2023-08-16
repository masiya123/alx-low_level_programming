#include "3-calc.h"
#include <stdlib.h>
#include <string.h>

/**
  * get_op_func - function that selects the correct function
  * @s: is the operator passed as argument to the program
  *
  * Return: 0
  */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{ "+", op_add },
	{ "-", op_sub },
	{ "*", op_mul },
	{ "/", op_div },
	{ "%", op_mod },
	{ NULL, NULL }
	};
	int x = 0;

	while (x < 5)
	{
		if (strcmp(s, ops[x].op) == 0)
			return (ops[x].f);

		x++;
	}

	return (0);
}
