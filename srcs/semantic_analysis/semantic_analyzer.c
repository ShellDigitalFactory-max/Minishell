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

static void	add_temp_env_to_environment(void)
{
	
}

static void	consume_temp_env(void)
{
	add_temp_env_to_environment();
}

void	semantic_analyzer(t_minishell_context *minishell_context)
{
	//t_command_pipeline	command_pipeline;
	t_machine_states	machine_state;
	t_token_list		token_list;

	machine_state = ASSIGNATION;
	token_list = ((t_token_list)minishell_context->command_session.tokenized_user_input_line);
	while (machine_state != SEMANTIC_PROCESS_END)
	{
		machine_state = run_assignation(token_list->content);
		token_list = token_list->next;
	}
	print_temp_env();
	printf("\n\n\n\n");
	consume_temp_env();
	clear_temp_env();
}