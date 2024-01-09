#include "shell.h"

/**
 * display_history - displays the history list, one command per line, preceded
 *                   with line numbers, starting at 0.
 * @shell_info: Pointer to struct containing potential arguments.
 *  Return: Always 0
 */
int display_history(info_t *shell_info)
{
	print_list(shell_info->history);
	return (0);
}

/**
 * remove_alias - removes an alias
 * @shell_info: Pointer to struct containing shell info
 * @alias_str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int remove_alias(info_t *shell_info, char *alias_str)
{
	char *alias_end, alias_char;
	int removal_status;

	alias_end = _strchr(alias_str, '=');
	if (!alias_end)
		return (1);
	alias_char = *alias_end;
	*alias_end = 0;
	removal_status = delete_node_at_index(&(shell_info->alias),
		get_node_index(shell_info->alias, node_starts_with(shell_info->alias, alias_str, -1)));
	*alias_end = alias_char;
	return (removal_status);
}

/**
 * add_alias - adds an alias
 * @shell_info: Pointer to struct containing shell info
 * @alias_str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int add_alias(info_t *shell_info, char *alias_str)
{
	char *alias_end;

	alias_end = _strchr(alias_str, '=');
	if (!alias_end)
		return (1);
	if (!*++alias_end)
		return (remove_alias(shell_info, alias_str));

	remove_alias(shell_info, alias_str);
	return (add_node_end(&(shell_info->alias), alias_str, 0) == NULL);
}

/**
 * output_alias - outputs an alias string
 * @alias_node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int output_alias(list_t *alias_node)
{
	char *alias_end = NULL, *alias_start = NULL;

	if (alias_node)
	{
		alias_end = _strchr(alias_node->str, '=');
		for (alias_start = alias_node->str; alias_start <= alias_end; alias_start++)
			_putchar(*alias_start);
		_putchar('\'');
		_puts(alias_end + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * shell_alias - mimics the alias builtin (man alias)
 * @shell_info: Pointer to struct containing potential arguments.
 *  Return: Always 0
 */
int shell_alias(info_t *shell_info)
{
	int i = 0;
	char *alias_end = NULL;
	list_t *alias_node = NULL;

	if (shell_info->argc == 1)
	{
		alias_node = shell_info->alias;
		while (alias_node)
		{
			output_alias(alias_node);
			alias_node = alias_node->next;
		}
		return (0);
	}
	for (i = 1; shell_info->argv[i]; i++)
	{
		alias_end = _strchr(shell_info->argv[i], '=');
		if (alias_end)
			add_alias(shell_info, shell_info->argv[i]);
		else
			output_alias(node_starts_with(shell_info->alias, shell_info->argv[i], '='));
	}

	return (0);
}

