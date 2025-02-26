/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_output_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:28:23 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/20 21:28:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_semantic_analysis_state_return	state_output_redirection(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command)
{
	int	outfile_fd;

	if (current_command->command_redirections.opening_status != OPENING_FAILURE)
	{
		if (current_command->command_redirections.out_stream > STDOUT_FILENO)
		{
			if (close(current_command->command_redirections.out_stream) == -1)
				perror("minishell: close");
		}
		outfile_fd = open(current_token->token_lexem, O_WRONLY | O_CREAT
				| O_TRUNC | __O_CLOEXEC, 0644);
		if (outfile_fd < 0)
		{
			save_opening_error(current_command, current_token->token_lexem);
			current_command->command_redirections.out_stream = OPENING_ERROR;
			current_command->command_redirections.opening_status
				= OPENING_FAILURE;
		}
		current_command->command_redirections.out_stream = outfile_fd;
	}
	semantic_machine->machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}
