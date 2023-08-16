#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * op_add - ruturns the sum of a and b
  * @a: int to the sum
  * @b: int to the sum
  *
  * Return: a sum of an int
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - the subtraction of a and b
  * @a: int to the sum
  * @b: int to the sum
  *
  * Return: a sum of an int
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - a multiplication of two ints
  * @a: sum of int
  * @b: sum of int
  *
  * Return: a sum of int a and b
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  * op_div - a division sum of two numbers
  * @a: sum of an int
  * @b: sum of an int
  *
  * Return: a sum of a and b
  */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
  * op_mod - modulo of two numbers
  * @a: sum of an int
  * @b: sum of an int
  *
  * Return: a sum of a and b
  */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
