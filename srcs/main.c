/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:39 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/14 16:25:29 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#ifndef TEST_MODE

static int	main_process(t_minishell_context *minishell_context)
{
	if (minishell_context->command_session.user_input_line == CTRL_D)
		exit_shell_routine();
	if (lexe_input(&minishell_context->command_session)
		== LEXING_FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Memory allocation failure during lexing.\n");
		return (EXIT_FAILURE);
	}
	if (parse_input(minishell_context->command_session.tokenized_user_input_line)
		== INVALID_SYNTAX)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	core_routine(t_minishell_context *minishell_context)
{
	while (MSH_LOOP)
	{
		minishell_context->command_session.user_input_line
			= prompt_gets_user_input();
		main_process(minishell_context);
		free(minishell_context->command_session.user_input_line);
		delete_token_list(
			minishell_context->command_session.tokenized_user_input_line);
	}
	return (EXIT_SUCCESS);
}

static int	launch_shell(void)
{
	t_minishell_context	minishell_context;
	struct sigaction	sa;

	ft_bzero(&minishell_context, sizeof(minishell_context));
	setup_signals(&sa);
	return (core_routine(&minishell_context));
}

int	main(void)
{
	return (launch_shell());
}
#endif