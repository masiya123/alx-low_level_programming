#include "shell.h"

/**
 * fetch_history_file - gets the history file
 * @shell_info: Pointer to struct containing shell info.
 *
 * Return: allocated string containing history file
 */
char *fetch_history_file(info_t *shell_info)
{
	char *buffer, *dir;

	dir = _getenv(shell_info, "HOME=");
	if (!dir)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, dir);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE);
	return (buffer);
}

/**
 * save_history - creates a file, or appends to an existing file
 * @shell_info: Pointer to struct containing shell info.
 *
 * Return: 1 on success, else -1
 */
int save_history(info_t *shell_info)
{
	ssize_t fd;
	char *filename = fetch_history_file(shell_info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = shell_info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * load_history - reads history from file
 * @shell_info: Pointer to struct containing shell info.
 *
 * Return: histcount on success, 0 otherwise
 */
int load_history(info_t *shell_info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buffer = NULL, *filename = fetch_history_file(shell_info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
		return (0);
	rdlen = read(fd, buffer, fsize);
	buffer[fsize] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			add_to_history_list(shell_info, buffer + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		add_to_history_list(shell_info, buffer + last, linecount++);
	free(buffer);
	shell_info->histcount = linecount;
	while (shell_info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(shell_info->history), 0);
	update_history_numbers(shell_info);
	return (shell_info->histcount);
}

/**
 * add_to_history_list - adds entry to a history linked list
 * @shell_info: Pointer to struct containing shell info.
 * @buffer: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int add_to_history_list(info_t *shell_info, char *buffer, int linecount)
{
	list_t *node = NULL;

	if (shell_info->history)
		node = shell_info->history;
	add_node_end(&node, buffer, linecount);

	if (!shell_info->history)
		shell_info->history = node;
	return (0);
}

/**
 * update_history_numbers - renumbers the history linked list after changes
 * @shell_info: Pointer to struct containing shell info.
 *
 * Return: the new histcount
 */
int update_history_numbers(info_t *shell_info)
{
	list_t *node = shell_info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (shell_info->histcount = i);
}

