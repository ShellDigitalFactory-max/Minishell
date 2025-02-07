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

static int	launch_shell(char **env)
{
	t_minishell_context	minishell_context;
	struct sigaction	sa;

	display_minishell_header();
	ft_bzero(&minishell_context, sizeof(minishell_context));
	if (build_environment(env) == PROCESS_FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Fatal error while initializing minishell's"
			" environment\n");
		exit(EXIT_FAILURE);
	}
	setup_signals(&sa);
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