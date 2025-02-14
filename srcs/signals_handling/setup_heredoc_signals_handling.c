/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_heredoc_signals_handling.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:53:56 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/14 15:54:12 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void simulate_eof(void)
{
	const int devnull = open("/dev/null", O_RDONLY);

	if (devnull != -1)
	{
		dup2(devnull, STDIN_FILENO);
		close(devnull);
	}
}

static void	sigint_for_heredoc(int signum)
{
	(void)signum;
	stop = 1;
	write(STDIN_FILENO, "\n", 1);
	set_exit_status(128 + SIGINT);
	rl_replace_line("", 0);
	rl_done = 1;
	simulate_eof();
}

void	setup_heredoc_signals_handling(void)
{
	signal(SIGINT, sigint_for_heredoc);
}