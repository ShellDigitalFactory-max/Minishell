/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:23:41 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/13 23:10:24 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command_line_analysis_status	command_line_analysis(
									t_minishell_context *minishell_context)
{
	if (minishell_context->command_session.user_input_line == CTRL_D)
		exit_shell_routine();
	if (lexe_input(&minishell_context->command_session)
		== LEXING_FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "minishell: memory allocation failure "
			"during lexing. Aborting.\n");
		exit(FAILURE);
	}
	if (is_empty_input(
			minishell_context->command_session.tokenized_user_input_line)
		== true)
		return (EMPTY_COMMAND_LINE);
	expand_input(minishell_context->command_session.tokenized_user_input_line);
	if (parse_input(
			minishell_context->command_session.tokenized_user_input_line)
		== INVALID_SYNTAX)
	{
		return (INVALID_COMMAND_LINE);
	}
	minishell_context->command_session.command_pipeline = semantic_analyzer
		(minishell_context->command_session.tokenized_user_input_line);
	return (COMMAND_PIPELINE_SET);
}

static void	current_loop_process(t_minishell_context *minishell_context)
{
	if (command_line_analysis(minishell_context) == COMMAND_PIPELINE_SET)
	{
		command_pipeline_interpreter(minishell_context);
	}
}

int	core_routine(t_minishell_context *minishell_context)
{
	while (MSH_LOOP)
	{
		minishell_context->command_session.user_input_line
			= prompt_gets_user_input(MAIN_PROMPT);
		current_loop_process(minishell_context);
		clean_current_loop_context(minishell_context);
	}
	return (EXIT_SUCCESS);
}
