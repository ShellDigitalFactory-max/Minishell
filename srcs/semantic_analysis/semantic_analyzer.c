/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic_analyzer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:37:14 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/14 13:37:26 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

void	semantic_analyzer(t_token_list token_list)
{
	//t_command_pipeline	command_pipeline;
	
	t_machine_states	machine_state;
	t_command_pipeline	*cmd_pipeline;
	t_command 			*current_command;
	t_semantic_analysis_state_return		state_return;


	cmd_pipeline = ft_calloc(sizeof(t_command_pipeline), 1);
	machine_state = SEMANTIC_PROCESS_START;
	current_command = NULL;
	while (machine_state != SEMANTIC_PROCESS_END)
	{
		if (machine_state == SEMANTIC_PROCESS_START || machine_state == PIPE_OPERATOR) {
			free(current_command);
			current_command = create_command();
		}
		state_return = run_state[machine_state](&machine_state, token_list->content);
		if (state_return == TOKEN_PROCESSED)
			token_list = token_list->next;
	}
	print_env(get_temporary_environment());
	return cmd_pipeline;
}


void state_command(t_token *token, t_machine_states *machine_state, t_command_pipeline	*cmd_pipeline, t_command *current_command)
{
	if (token->token_type == INPUT_REDIR_OPERATOR)
	{
		*machine_state = STATE_INPUT_REDIRECT;
		return PASS_TO_NEXT_STATE
	}
	add token->lexem to cmd.args

	return TOKEN_PROCESSED

}

void state_end_of_command(t_token_list token_list, t_machine_states *machine_state, t_command_pipeline	*cmd_pipeline, t_command *current_command)
{
	if (current_command->args == NULL)
	{
		ft_list_add_back(get_environment(), current_command->command_environment);
	}
	else
	{
		ft_list_add_back(cmd_pipeline, current_command);
	}
}