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

t_minishell_data	minishell_data;

static int	main_process(t_current_loop_data *loop_data)
{
	if (loop_data->user_input_line == CTRL_D)
		exit_shell_routine();
	if (lexe_input(loop_data) == LEXING_FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Memory allocation failure during lexing.\n");
		return (EXIT_FAILURE);
	}
	if (parse_input(loop_data->tokenized_user_input_line)
		== INVALID_SYNTAX)
	{
		//ici pour set $? ??
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	core_routine(t_current_loop_data *loop_data)
{
	while (MSH_LOOP)
	{
		loop_data->user_input_line = prompt_gets_user_input();
		main_process(loop_data);
		free(loop_data->user_input_line);
		delete_token_list(loop_data->tokenized_user_input_line);
	}
	return (EXIT_SUCCESS);
}

static int	launch_shell(void)
{
	t_current_loop_data	loop_data;
	struct sigaction	sa;

	ft_bzero(&minishell_data, sizeof(minishell_data));
	ft_bzero(&loop_data, sizeof(loop_data));
	setup_signals(&sa);
	return (core_routine(&loop_data));
}

int	main(void)
{
	return (launch_shell());
}
#endif
