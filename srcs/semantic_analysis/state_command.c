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

static void	add_argument_to_command_args(const char *argument_lexem,
					t_command_args *current_command_arguments)
{
	t_command_args		new_argument;
	t_command_argument	argument_value;

	argument_value = ft_strdup(argument_lexem);
	if (argument_value == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during "
			"command pipeline builing. Aborting.\n");
		exit(FAILURE);
	}
	new_argument = ft_lstnew(argument_value);
	if (new_argument == NULL)
	if (argument_value == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during "
			"command pipeline builing. Aborting.\n");
		exit(FAILURE);
	}
	ft_lstadd_back(current_command_arguments, new_argument);
}

t_semantic_analysis_state_return	state_command(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command)
{
	if (current_token->token_type != WORD)
	{
		return (update_machine_state(current_token->token_type, machine_state));
	}
	add_argument_to_command_args(current_token->token_lexem, &current_command->command_args);
	if (current_command->command_nature == ONLY_ASSIGNATION)
		current_command->command_nature = POSSIBLE_BINARY;
	*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}
