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
	t_path_type	path_type;

	if (*command == RELATIVE_PREFIX)
	{
		path_type = RELATIVE_PATH;
	}
	else if (*command == *ABSOLUTE_PREFIX)
	{
		path_type = COMPLETE_ABSOLUTE_PATH;
	}
	else
	{
		path_type = UNCOMPLETE_ABSOLUTE_PATH;
	}
	return (path_type);
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
	
	command_arguments = list_to_array(command);
	command_environment = list_to_array(command);
	if (get_command_validity(command) == VALID_COMMAND)
	{
		execve(command->command_name,command_arguments, command_environment);
		// SECU EXECVE
	}
	ft_dprintf(STDERR_FILENO, "minishell: command not found: %s\n",
		command->command_args->content);
}

	// if (user_input == NULL || *user_input == '\0'
	// 	|| is_full_of_spaces(user_input) == true)
	// 	exit (EXIT_FAILURE);