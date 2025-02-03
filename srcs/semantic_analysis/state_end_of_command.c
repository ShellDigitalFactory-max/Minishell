/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_end_of_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:45:24 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/23 15:45:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_command(t_command *command)
{
	return (command->command_name != NULL);
}

static bool	is_environment(t_command *command)
{
	return (command->command_environment != NULL);
}

// static bool	is_pipe(t_token_type token_type)
// {
// 	return (token_type == PIPE_OPERATOR);
// }

static t_command_nature	define_command_nature(t_command *command)
{
	if (is_command(command) == false && is_environment(command))
		return (ONLY_ASSIGNATION);
	else if (is_builtin(command->command_name))
		return (BUILTIN);
	else if (is_command(command))
		return (POSSIBLE_BINARY);
	return (UNDEFINED);
}

t_semantic_analysis_state_return	state_end_of_command(
										t_semantic_machine *semantic_machine,
										t_command_pipeline *cmd_pipeline,
										t_command *current_command,
										t_token *current_token)
{
	t_command_pipeline	pipeline_segment;

	get_command_name(current_command);
	current_command->command_nature = define_command_nature(current_command);
	pipeline_segment = ft_lstnew(current_command);
	if (pipeline_segment == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during command "
			"pipeline building. Aborting.\n");
		exit(FAILURE);
	}
	ft_lstadd_back(cmd_pipeline, pipeline_segment);
	if (current_token->token_type == TOKEN_LIST_END)
	{
		semantic_machine->machine_state = SEMANTIC_PROCESS_END;
		return (END_OF_TOKEN_LIST);
	}
	else
	{
		semantic_machine->machine_state = STATE_NEW_COMMAND;
		return (TOKEN_PROCESSED);
	}
}
