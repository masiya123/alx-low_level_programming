#include "variadic_functions.h"

/**
 * print_all - function that prints all of the
 * arguments when specified
 * @format: specifies the necessary operations
 * Return: void
 */

void print_all(const char * const format, ...)
{
	int j;
	int flag;
	char *str;
	va_list a_list;

	va_start(a_list, format);
	j = 0;
	while (format != NULL && format[j] != '\0')
	{
		switch (format[j])
		{
			case 'c':
				printf("%c", va_arg(a_list, int));
				flag = 0;
				break;
			case 'i':
				printf("%i", va_arg(a_list, int));
				flag = 0;
				break;
			case 'f':
				printf("%f", va_arg(a_list, double));
				flag = 0;
				break;
			case 's':
				str = va_arg(a_list, char*);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				flag = 0;
				break;
			default:
				flag = 1;
				break;
		}
		if (format[j + 1] != '\0' && flag == 0)
			printf(", ");
		j++;
	}
	printf("\n");
	va_end(a_list);
}
