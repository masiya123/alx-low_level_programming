#include "shell.h"

/**
 * fetch_environ - returns the string array copy of our environment
 * @shell_info: Pointer to struct containing shell info.
 *
 * Return: Pointer to the environment string array
 */
char **fetch_environ(info_t *shell_info)
{
	if (!shell_info->environ || shell_info->env_changed)
	{
		shell_info->environ = list_to_strings(shell_info->env);
		shell_info->env_changed = 0;
	}

	return (shell_info->environ);
}

/**
 * remove_env_var - Remove an environment variable
 * @shell_info: Pointer to struct containing shell info.
 * @var: the string env var property
 * Return: 1 on delete, 0 otherwise
 */
int remove_env_var(info_t *shell_info, char *var)
{
	list_t *node = shell_info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			shell_info->env_changed = delete_node_at_index(&(shell_info->env), i);
			i = 0;
			node = shell_info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (shell_info->env_changed);
}

/**
 * set_env_var - Initialize a new environment variable,
 *               or modify an existing one
 * @shell_info: Pointer to struct containing shell info.
 * @var: the string env var property
 * @value: the string env var value
 * Return: 0 on success, 1 on failure
 */
int set_env_var(info_t *shell_info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = shell_info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			shell_info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(shell_info->env), buf, 0);
	free(buf);
	shell_info->env_changed = 1;
	return (0);
}

