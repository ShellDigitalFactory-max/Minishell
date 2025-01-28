/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_command_pipeline.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:40:11 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/27 17:40:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_argument(void *argument_to_delete)
{
	char	*argument;

	argument = (char *)argument_to_delete;
	free(argument);
}

void	delete_command(void *command_to_delete)
{
	t_command	*command;

	command = (t_command *)command_to_delete;
	if (command->command_name != NULL)
		free(command->command_name);
	ft_lstclear(&command->command_args, delete_argument);
	delete_variables_list_in_environment(&command->command_environment);
	if (command->opening_failure_msg != NULL)
		free(command->opening_failure_msg);
	free(command);
}

void	delete_command_pipeline(t_command_pipeline *cmd_pipeline)
{
	ft_lstclear(cmd_pipeline, delete_command);
}