#include "shell.h"

/**
 * shell_exit - Exits shell
 * @info: Structure containing potential arguments
 *
 * description: This function handles the "exit" command in the shell. It exits the shell
 * with a given exit status based on the argument provided. If no argument is
 * provided, the default exit status is 0. If the argument is not a valid number,
 * it prints an error message and returns a non-zero exit status.
 *
 * Return: Exits the shell with the specified exit status.
 * Returns 0 if info->argv[0] is not equal to "exit".
 */

int shell_exit(info_t *info)
{
	int c_exit;

	if (info->argv[1])
	{
	c_check = convert_string(info->argv[1]);
	if (c_exit == 0 && info->argv[1][0] != '0')
	{
	info->status = 2;
	print_error(info, "Illegal number: ");
	_eputs(info->argv[1]);
	_eputschar('\n');
	return (1);
	}

	info->err_num = c_exit;
	return (-2);
	}

	info->err_num = -1;
	return (-2);
}
