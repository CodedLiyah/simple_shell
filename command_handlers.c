#include "shell.h"

/**
 * shell_exit - Exits shell
 * @info: Structure containing potential arguments
 *
 * This function exits the shell with the specified exit status. If `info->argv[1]`
 * is not equal to "exit", it attempts to convert it to an integer and sets the
 * `info->err_num` accordingly. If an illegal number is encountered, an error is
 * printed. If no argument is provided, `info->err_num` is set to -1.
 *
 * Return: Exits the shell with the specified exit status.
 * Returns 0 if info->argv[0] is not equal to "exit".
 */

int shell_exit(info_t *info)
{
	int c_check;

	if (info->argv[1])
	{
	c_check = convert_string(info->argv[1]);
	if (c_check == 0 && info->argv[1][0] != '0')
	{
	info->status = 2;
	print_error(info, "Illegal number: ");
	_eputs(info->argv[1]);
	_eputchar('\n');
	return (1);
	}

	info->err_num = c_check;
	return (-2);
	}

	info->err_num = -1;
	return (-2);
}

/**
 * shell_cd - Facilitates the process of navigation and switching
 * @info - A structure containing potential arguments
 *
 * This function facilitates the process of changing the current working directory
 * based on the provided arguments. If no argument is provided, it attempts to change
 * the directory to the value of the "HOME" environment variable. If the argument is
 * "-", it changes the directory to the value of the "OLDPWD" environment variable.
 * Otherwise, it attempts to change the directory to the specified path.
 *
 * Return: Always 0
 */

int shell_cd(info_t *info)
{
	int chdir_r;
	char *cd, *td, bu[1024];

	cd = getcwd(bu, 1024);
	if (!cd)
		_eputs("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])
	{
	td = _getenv(info, "HOME=");
	if (!td)
	chdir_r = /* TODO: handle default behavior */
		chdir_r((td = _getenv(info, "PWD=")) ? td : "/");
	return (1)
	else
	chdir_r = chdir(td);
	}

	else if (strcmp(info->argv[1], "-") == 0)
	{
	if (!_getenv(info, "OLDPWD="))
	{
		_puts(cd);
		_eputchar('\n');
		return (1);
	}

	_puts(_getenv(info, "OLDPWD="));
	_putchar('\n');
	chdir_r = /* TODO: handle default behavior */
	chdir((td = _getenv(info, "OLDPWD=")) ? td : "/");
	}

	else
		chdir_r = chdir(info->argv[1]);

	if (chdir_r == -1)
	{
	print_error(info, "can't cd to ");
	_eputs(info->argv[1]);
	_eputchar('\n');
	}
	else
	{
	_getenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(bu, 1024));
	}
	return (0);
}

/**
 * shell_help - Displays help information
 * @info: Structure containting arguments
 *
 * This function displays help information. However, it is not yet implemented.
 *
 * Return: Always 0
 */

int shell_help(info_t *info)
{
	char **arg_a = info->argv;

	_puts("Help command is not yet implemented.\n");

	_puts(*arg_a); /* Temporary unused variable workaround */

	return (0);
}
