#include "shell.h"

/**
 * main - entry point of the program
 * @arg_count: count of arguments
 * @arg_vector: vector of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int arg_count, char **arg_vector)
{
	info_t info[] = { INFO_INIT };
	int file_descriptor = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (file_descriptor)
		: "r" (file_descriptor));

	if (arg_count == 2)
	{
		file_descriptor = open(arg_vector[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(arg_vector[0]);
				_eputs(": 0: Can't open ");
				_eputs(arg_vector[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = file_descriptor;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, arg_vector);
	return (EXIT_SUCCESS);
}

