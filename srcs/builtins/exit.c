/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:45:34 by linux             #+#    #+#             */
/*   Updated: 2025/02/15 17:15:16 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_isnumber(char *args)
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

int	error_exit(char *arg)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	return (EXIT_FAILURE);
}

int	exit_builtin(t_command *command)
{
	int		exit_code;
	char	**args;

	args = list_to_strs_array(command->command_args, args_list_to_args_array);
	exit_code = 0;
	if (ft_lstsize(command->command_args) > 2)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_lstsize(command->command_args) > 1)
	{
		if (ft_isnumber(args[1]))
		{
			exit_code = ft_atoi(args[1]);
		}
		else
		{
			return (error_exit(args[1]));
		}
	}
	ft_putstr_fd("exit\n", 2);
	exit(exit_code);
	return (exit_code);
}
