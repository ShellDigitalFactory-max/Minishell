/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_end_of_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:45:24 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/23 15:45:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_semantic_analysis_state_return	state_end_of_command(
										t_machine_states *machine_state,
										t_command_pipeline *cmd_pipeline, 
										t_command *current_command,
										t_token *current_token)
{
	t_command_pipeline	pipeline_segment;

	pipeline_segment = ft_lstnew(current_command);
	if (pipeline_segment == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during command "
			"pipeline building. Aborting.\n");
		exit(FAILURE);
	}
	ft_lstadd_back(cmd_pipeline, pipeline_segment);
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