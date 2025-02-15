/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:43:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/31 14:43:54 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_command_status	check_relative_path(t_command *command,
							char **command_env)
{
	(void)command_env;
	command->command_binary_path = command->command_args->content;
	return (check_complete_path(command));
}

static t_command_status	check_complete_absolute_path(t_command *command,
							char **command_env)
{
	(void)command_env;
	command->command_binary_path = command->command_args->content;
	return (check_complete_path(command));
}

static t_command_status	check_uncomplete_absolute_path(t_command *command,
							char **command_env)
{
	if (ft_getenv("PATH", command_env) == NULL)
		return (INVALID_COMMAND);
	return (build_complete_path(command, command_env));
}

t_command_status	command_path_manager(
						t_command *command, char **command_env,
						const t_path_type command_path_type)
{
	const t_path_manager_func	path_manager_functions[] = {
		check_relative_path,
		check_complete_absolute_path,
		check_uncomplete_absolute_path,
	};

	return (path_manager_functions[command_path_type](command, command_env));
}
