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

void	semantic_analyzer(t_minishell_context *minishell_context)
{
	//t_command_pipeline	command_pipeline;
	t_machine_states	machine_state;
	t_token_list		token_list;

	machine_state = SEMANTIC_PROCESS_START;
	token_list = ((t_token_list)minishell_context->command_session.tokenized_user_input_line);
	while (machine_state != SEMANTIC_PROCESS_END)
	{
		machine_state = run_assignation(token_list->content);
		token_list = token_list->next;
	}
	print_env(get_temporary_environment());
}