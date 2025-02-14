/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:39 by hucherea          #+#    #+#             */
/*   Updated: 2025/02/10 11:40:58 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef TEST_MODE

int	stop;

static int	launch_shell(char **env)
{
	t_minishell_context	minishell_context;

	display_minishell_header();
	setup_default_signals_handling();
	ft_bzero(&minishell_context, sizeof(minishell_context));
	if (build_environment(env) == PROCESS_FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Fatal error while initializing minishell's"
			" environment\n");
		exit(EXIT_FAILURE);
	}
	set_exit_status(EXIT_SUCCESS);
	return (core_routine(&minishell_context));
}

int	main(int ac, char **av, char **env)
{
	if (ac != 1 || av[1] != NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: no arguments are accepted.\n");
		return (EXIT_FAILURE);
	}
	return (launch_shell(env));
}

#endif
