/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_assignation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:25:34 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/14 14:25:50 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_status	add_assignation_to_command_env(t_command *command,
					char *assignation)
{
	return (set_variable_from_keyvalue_to_environment(assignation,
			NOT_EXPORTABLE,
			&command->command_environment));
}

t_semantic_analysis_state_return	state_assignation(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command)
{
	if (current_token->token_type == TOKEN_LIST_START)
		return (TOKEN_PROCESSED);
	if (assignation_checker(current_token->token_lexem) == INVALID_ASSIGNATION)
	{
		semantic_machine->machine_state = STATE_COMMAND;
		return (TOKEN_NOT_PROCESSED);
	}
	else
	{
		if (add_assignation_to_command_env(current_command,
				current_token->token_lexem) == PROCESS_FAILURE)
		{
			ft_dprintf(STDERR_FILENO, "minishell: malloc error during"
				" temporary environment building. Aborting\n");
			exit(FAILURE);
		}
		semantic_machine->machine_state = STATE_ASSIGNATION;
		return (TOKEN_PROCESSED);
	}
}
