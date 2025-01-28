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

t_semantic_analysis_state_return	state_input_redirection(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command)
{
	int	infile_fd;

	if (current_command->command_redirections.opening_status != OPENING_FAILURE)
	{
		if (current_command->command_redirections.in_stream > STDIN_FILENO)
		{
			if (close(current_command->command_redirections.in_stream) == -1)
				perror("minishell: close");
		}
		infile_fd = open(current_token->token_lexem, O_RDONLY | __O_CLOEXEC);
		if (infile_fd < 0)
		{
			save_opening_error(current_command, current_token->token_lexem);
			current_command->command_redirections.in_stream = OPENING_ERROR;
			current_command->command_redirections.opening_status = OPENING_FAILURE;
		}
		current_command->command_redirections.in_stream = infile_fd;
	}
	if (current_command->command_args == NULL)
		*machine_state = STATE_ASSIGNATION;
	else
		*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}
