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

static t_semantic_analysis_state_return	run_state(
											t_machine_states *machine_state,
											t_token *current_token,
											t_command *current_command)
{
	const t_token	*token = (t_token *)current_token;
	static t_semantic_state_function states_functions[] = {
		state_assignation,
		state_input_redirection,
		state_output_redirection,
		state_append_redir,
		state_heredoc,
		state_command,
	};

	return (states_functions[*machine_state](machine_state, token));
}

t_status run_state_machine(t_token_list token_list, t_command_pipeline *cmd_pipeline)
{
	t_machine_states					machine_state;
	t_command 							*current_command;
	t_semantic_analysis_state_return	state_return;

	machine_state = SEMANTIC_PROCESS_START;
	current_command = NULL;
	while (machine_state != SEMANTIC_PROCESS_END)
	{
		if (machine_state == SEMANTIC_PROCESS_START || machine_state == STATE_NEW_COMMAND)
		{
			free(current_command);
			current_command = create_command();
			machine_state = STATE_ASSIGNATION;
		}
		state_return = run_state(&machine_state, token_list->content, current_command);
		if (machine_state == STATE_END_OF_COMMAND)
			state_return = state_end_of_command(&machine_state, cmd_pipeline, current_command, token_list);
		if (state_return == TOKEN_PROCESSED)
			token_list = token_list->next;
	}
	return (PROCESS_SUCCESS);
}

t_command_pipeline	semantic_analyzer(t_token_list token_list)
{
	t_command_pipeline	*cmd_pipeline;

	cmd_pipeline = (t_command_pipeline *)ft_calloc(1, sizeof(t_command_pipeline));
	if (cmd_pipeline == NULL || run_state_machine(token_list, cmd_pipeline) == PROCESS_FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during command "
		"pipeline building. Aborting\n");
		exit(FAILURE);
	}
	return (cmd_pipeline);
}

t_semantic_analysis_state_return	state_command(t_token *token, t_machine_states *machine_state, t_command_pipeline	*cmd_pipeline, t_command *current_command)
{
	if (token->token_type == INPUT_REDIR_OPERATOR)
	{
		*machine_state = STATE_INPUT_REDIRECT;
		return (TOKEN_PROCESSED);
	}
	add token->lexem to cmd.args

	return (TOKEN_PROCESSED);

}

t_semantic_analysis_state_return	state_end_of_command(t_machine_states *machine_state, t_command_pipeline *cmd_pipeline, t_command *current_command, t_token *current_token)
{
	if (current_command->args == NULL)
	{
		ft_lstadd_back(get_environment(), current_command->command_environment);
	}
	else
	{
		ft_lstadd_back(&cmd_pipeline, current_command);
	}
	if (current_token->token_type == TOKEN_LIST_END)
	{
		*machine_state = SEMANTIC_PROCESS_END;
		return (END_OF_TOKEN_LIST);
	}
	else
	{
		*machine_state = STATE_NEW_COMMAND;
		return (TOKEN_PROCESSED);
	}
}