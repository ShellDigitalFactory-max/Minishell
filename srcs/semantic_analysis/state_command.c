/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:41:26 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/23 15:41:36 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_semantic_analysis_state_return	update_machine_state(
											const t_token_type token_type,
											t_machine_states *machine_state)
{
	if (token_type == INPUT_REDIR_OPERATOR)
		*machine_state = STATE_INPUT_REDIRECT;
	else if (token_type == OUTPUT_REDIR_OPERATOR)
		*machine_state = STATE_OUTPUT_REDIRECT;
	else if (token_type == APPEND_OPERATOR)
		*machine_state = STATE_APPEND_REDIRECT;
	else if (token_type == HEREDOC_OPERATOR)
		*machine_state = STATE_HEREDOC;
	else if (token_type == PIPE_OPERATOR || token_type == TOKEN_LIST_END)
	{
		*machine_state = STATE_END_OF_COMMAND;
		return (TOKEN_NOT_PROCESSED);
	}
	return (TOKEN_PROCESSED);
}

t_semantic_analysis_state_return	state_command(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command)
{
	(void)current_command;
	if (current_token->token_type != WORD)
	{
		return (update_machine_state(current_token->token_type, machine_state));
	}
	//add token->lexem to cmd.args
	return (TOKEN_PROCESSED);
}
