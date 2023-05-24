#include "shell.h"

/**
 * custom_exit - Shell exit
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Exits with an exit status
 * (0) if info.argv[0] and != "exit"
 */
int custom_exit(info_t *info)
{
	int exit_status;

	if (info->argv[1]) /* If there's an exit arguement */
	{
	exit_status = _erratoi(info->argv[1]);
	if (exit_status == -1)
	{
		info->status = 2;
		print_error(info, "Illegal number: ");
		_eputs(info->argv[1]);
		_eputchar('\n');
		return (1);
	}
	info->err_num = _erratoi(info->argv[1]);
	return (-2);
	}

	info->err_num = -1;
	return (-2);
}

/**
 * change_d - This changes the current directory
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0
 */
int change_d(info_t *info)
{
	char *current_dir, *new_dir, buffer[1024];
	int chdir_ret;

	current_dir = get_current_directory(buffer, 1024);
	if (!current_dir)
		custom_puts("TODO: >>get_current_directory failure emsg here<<\n");
	if (!info->argv[1])
	{
		new_dir = get_current_directory(info, "HOME=");
		if (!new_dir)
			chdir_ret = /* TODO: what should this be? */
				change_directory((new_dir = get_current_variable(info, "PWD=")) ? new_dir : "/");
		else
			chdir_ret = change_directory(new_dir);
	}
	else if (custom_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_custom_enviroment_variable(info, "OLDPWD="))
		{
			custom_puts(current_dir);
			custom_putchar('\n');
			return (1);
		}
		custom_puts(get_custom_enviroment_variable(info, "OLDPWD="));
		custom_putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			change_directory((new_dir = get_custom_enviroment_variable(info, "OLDPWD=")) ? new_dir : "/");
	}
	else
		chdir_ret = change_directory(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_custom_error(info, "can't cd to ");
		custom_puts(info->argv[1]);
		custom_putchar('\n');
	}
	else
	{
		set_custom_environment_variable(info, "OLDPWD", get_custom_environment_variable(info, "PWD="));
		set_custom_environment_variable(info, "PWD", get_current_directory(buffer, 1024));
	}
	return (0);
}

/**
 * custom_help - Displays help information
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int custom_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	custom_puts("Help function is not implemented yet. \n");
	if (0)
		custom_puts(*arg_array); /* temp att_unused workaround */

	return (0);
}

