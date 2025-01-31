/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:20:21 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/31 14:20:30 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_path_type	get_path_type(const char *command)
{
	if (*command == RELATIVE_PREFIX)
		return (RELATIVE_PATH);
	if (*command == *ABSOLUTE_PREFIX)
		return (COMPLETE_ABSOLUTE_PATH);
	return (UNCOMPLETE_ABSOLUTE_PATH);
}

static t_command_status	get_command_validity(t_command *command)
{
	const t_path_type	command_path_type
		= get_path_type(command->command_name);

	return (command_path_manager(command,
				command_path_type));
}

void	execute_command(t_command *command)
{
	char	**command_arguments;
	char	**command_environment;

	command_arguments = list_to_strs_array(command->command_args, args_list_to_args_array);
	command_environment = list_to_strs_array(command->command_environment, env_list_to_env_array);
	if (get_command_validity(command) == VALID_COMMAND)
	{
		execve(command->command_name,command_arguments, command_environment);
		// SECU EXECVE
	}
	ft_dprintf(STDERR_FILENO, "minishell: command not found: %s\n",
		command->command_args->content);
}
