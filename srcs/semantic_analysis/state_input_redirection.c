/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_input_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:59 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/20 15:32:09 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_semantic_analysis_state_return state_input_redirection(
									t_machine_states *machine_state,
									t_token *current_token,
									t_command *current_command)
{
	if (current_command->command_redirections.in_stream != NULL)
	{
		free(current_command->command_redirections.in_stream);
		current_command->command_redirections.in_stream = NULL;
	}
	current_command->command_redirections.in_stream
		= ft_strdup(current_token->token_lexem);
	if (current_command->command_redirections.in_stream == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during command "
		"pipeline building. Aborting\n");
		exit(FAILURE);
	}
	if (current_command->command_name == NULL)
		*machine_state = STATE_ASSIGNATION;
	else
		*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}