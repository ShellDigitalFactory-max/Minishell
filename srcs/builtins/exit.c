/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:45:34 by linux             #+#    #+#             */
/*   Updated: 2025/02/16 17:15:40 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_isnumber(char *args)
{
	int	i;

	i = 0;
	if (args[i] == '-' || args[i] == '+')
		i++;
	while (args[i] != '\0')
	{
		if (!ft_isdigit(args[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	error_exit(char *arg, char **args)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	ft_free_and_null(args);
	return (EXIT_FAILURE);
}

static void	clean_exit(t_command *command)
{
	t_minishell_context	*minishell_context;

	minishell_context = get_minishell_context(NULL, 0);
	clean_process(minishell_context, command);
}

static void	exit_process(t_command *command, char **args,
				int *exit_code)
{
	if (ft_isnumber(args[1]))
		*exit_code = ft_atoi(args[1]);
	else
	{
		error_exit(args[1], args);
		clean_exit(command);
		exit(EXIT_FAILURE);
	}
}

int	exit_builtin(t_command *command)
{
	int		exit_code;
	char	**args;

	args = list_to_strs_array(command->command_args, args_list_to_args_array);
	if (args == NULL)
	{
		ft_dprintf(STDERR_FILENO, "malloc error during exit builtin process. "
			"Aborting\n");
		exit(FAILURE);
	}
	exit_code = 0;
	if (ft_lstsize(command->command_args) > 2)
	{
		ft_free_and_null(args);
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_lstsize(command->command_args) > 1)
		exit_process(command, args, &exit_code);
	ft_putstr_fd("exit\n", 2);
	clean_exit(command);
	ft_free_and_null(args);
	exit((unsigned char)exit_code);
	return ((unsigned char)exit_code);
}
