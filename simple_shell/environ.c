#include "shell.h"

/**
 * print_env - prints the current environment
 * @shell_info: Pointer to struct containing potential arguments.
 * Return: Always 0
 */
int print_env(info_t *shell_info)
{
	print_list_str(shell_info->env);
	return (0);
}

/**
 * get_env_var - gets the value of an environment variable
 * @shell_info: Pointer to struct containing shell info
 * @var_name: environment variable name
 *
 * Return: the value of the environment variable
 */
char *get_env_var(info_t *shell_info, const char *var_name)
{
	list_t *node = shell_info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, var_name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_env_var - Initialize a new environment variable,
 *               or modify an existing one
 * @shell_info: Pointer to struct containing shell info
 * Return: Always 0
 */
int set_env_var(info_t *shell_info)
{
	if (shell_info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(shell_info, shell_info->argv[1], shell_info->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_env_var - Remove an environment variable
 * @shell_info: Pointer to struct containing shell info
 * Return: Always 0
 */
int unset_env_var(info_t *shell_info)
{
	int i;

	if (shell_info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= shell_info->argc; i++)
		_unsetenv(shell_info, shell_info->argv[i]);

	return (0);
}

/**
 * fill_env_list - populates environment linked list
 * @shell_info: Pointer to struct containing shell info
 * Return: Always 0
 */
int fill_env_list(info_t *shell_info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	shell_info->env = node;
	return (0);
}

