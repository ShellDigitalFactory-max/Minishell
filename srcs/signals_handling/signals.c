/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:46:42 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/12 14:32:38 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	init_signals(const struct sigaction *sa)
// {
// 	if (sigaction(SIGINT, sa, NULL) == FAILURE)
// 	{
// 		perror("sigaction");
// 		exit(EXIT_FAILURE);
// 	}
// 	signal(SIGQUIT, SIG_IGN);
// }

// void	setup_signals(struct sigaction *sa)
// {
// 	ft_memset(sa, 0, sizeof(struct sigaction));
// 	sa->sa_handler = signal_handler;
// 	init_signals(sa);
// }

static void	sigint_routine(int signum)
{
	(void)signum;
	set_exit_status(128 + SIGINT);
	write(STDIN_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	setup_main_prompt_signals_handling(void)
{
	signal(SIGINT, sigint_routine);
	signal(SIGTERM, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
}

// void	signal_handler(int signum)
// {
// 	if (signum == SIGINT)
// 	{
// 		sigint_routine();
// 	}
// }
