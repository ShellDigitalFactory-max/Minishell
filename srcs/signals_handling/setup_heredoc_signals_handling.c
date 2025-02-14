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
	g_received_signal = signum;
	write(STDOUT_FILENO, "\n", 1);
	set_exit_status(128 + signum);
	rl_replace_line("", 0);
	rl_done = 1;
	simulate_eof();
}

void	setup_heredoc_signals_handling(void)
{
	signal(SIGINT, sigint_for_heredoc);
	signal(SIGTERM, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
}