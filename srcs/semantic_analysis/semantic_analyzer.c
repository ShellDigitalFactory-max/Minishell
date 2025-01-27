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
	static t_semantic_state_function states_functions[] = {
		state_assignation,
		state_input_redirection,
		state_output_redirection,
		state_append_redirection,
		state_heredoc,
		state_command,
	};

	return (states_functions[*machine_state](machine_state, current_token, current_command));
}

static t_status	run_state_machine(t_token_list token_list, t_command_pipeline *cmd_pipeline)
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
			current_command = create_command();
			machine_state = STATE_ASSIGNATION;
		}
		state_return = run_state(&machine_state, token_list->content, current_command);
		if (machine_state == STATE_END_OF_COMMAND)
			state_return = state_end_of_command(&machine_state, cmd_pipeline, 
				current_command, token_list->content);
		if (state_return == TOKEN_PROCESSED)
			token_list = token_list->next;
	}
	return (PROCESS_SUCCESS);
}

t_command_pipeline	semantic_analyzer(t_token_list token_list)
{
	t_command_pipeline	*cmd_pipeline;

	cmd_pipeline = (t_command_pipeline *)ft_calloc(1, sizeof(t_command_pipeline));
	if (cmd_pipeline == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during command "
		"pipeline building. Aborting\n");
		exit(FAILURE);
	}
	if (run_state_machine(token_list, cmd_pipeline) == PROCESS_FAILURE)
	{
		delete_command_pipeline(cmd_pipeline);
		return (NULL);
	}
	return (*cmd_pipeline);
}
