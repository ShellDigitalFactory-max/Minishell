/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_append_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:47:11 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/22 15:47:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_semantic_analysis_state_return	state_append_redirection(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command)
{
	int	outfile_fd;

	if (current_command->command_redirections.out_stream > STDOUT_FILENO)
	{
		if (close(current_command->command_redirections.out_stream) == -1)
			perror("minishell: close");
	}
	outfile_fd = open(current_token->token_lexem, O_WRONLY | O_CREAT
					| O_APPEND | __O_CLOEXEC, 0644);
	if (outfile_fd < 0)
	{
		display_opening_errors(current_token->token_lexem);
		current_command->command_redirections.out_stream = OPENING_ERROR;
		*machine_state = STATE_OPENING_FAILURE;
		return (OPENING_FAILURE);
	}
	current_command->command_redirections.out_stream = outfile_fd;
	*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}
