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

static void	init_signals(const struct sigaction *sa)
{
	if (sigaction(SIGINT, sa, NULL) == FAILURE)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	signal(SIGQUIT, SIG_IGN);
}

void	setup_signals(struct sigaction *sa)
{
	ft_memset(sa, 0, sizeof(struct sigaction));
	sa->sa_handler = signal_handler;
	init_signals(sa);
}

void	sigint_routine(void)
{
	set_exit_status(128 + SIGINT);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		sigint_routine();
	}
}
