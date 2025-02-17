/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:48:56 by linux             #+#    #+#             */
/*   Updated: 2025/02/17 13:20:49 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	set_variables(char *old_pwd, char **target, char **args)
{
	if (getcwd(old_pwd, PATH_MAX) == NULL)
	{
		old_pwd = ft_strcpy(old_pwd, "");
	}
	*target = get_target_from_args(args);
	if (*target == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	change_directory(char *target)
{
	if (chdir(target) == -1)
	{
		free(target);
		perror("cd");
		return (EXIT_FAILURE);
	}
	free(target);
	return (EXIT_SUCCESS);
}

static int	exec_cd(char *old_pwd, char **target, char **args)
{
	if (set_variables(old_pwd, target, args))
		return (EXIT_SUCCESS);
	if (change_directory(*target))
		return (EXIT_FAILURE);
	return (false);
}

int	cd(t_command *command)
{
	char			*target;
	char			old_pwd[PATH_MAX];
	char			**args;

	args = list_to_strs_array(command->command_args, args_list_to_args_array);
	if (args == NULL)
		return (EXIT_FAILURE);
	if (ft_lstsize(command->command_args) > 2)
	{
		ft_free_and_null(args);
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (exec_cd(old_pwd, &target, args))
	{
		ft_free_and_null(args);
		return (EXIT_FAILURE);
	}
	if (update_env_variables(old_pwd))
	{
		ft_free_and_null(args);
		return (EXIT_FAILURE);
	}
	ft_free_and_null(args);
	return (EXIT_SUCCESS);
}
