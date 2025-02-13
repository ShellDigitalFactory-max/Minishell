/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:59:34 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/13 15:15:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prompt_asks_next_history_entry(const char *user_input_line)
{
	add_user_input_line_to_history(user_input_line);
}

static void simulate_eof(void)
{
	const int devnull = open("/dev/null", O_RDONLY);

	if (devnull != -1)
	{
		dup2(devnull, STDIN_FILENO);
		close(devnull);
	}
}

void	sigint_for_heredoc(int signum)
{
	(void)signum;
	stop = 1;
	write(STDIN_FILENO, "\n", 1);
	set_exit_status(128 + SIGINT);
	rl_replace_line("", 0);
	rl_done = 1;
	simulate_eof();
}

char	*prompt_gets_user_input(bool is_subprompt)
{
	static struct sigaction	sa;
	char					*user_input_line;

	if (is_subprompt == false)
	{
		setup_signals(&sa);
		user_input_line = readline(MSH_PROMPT);
		prompt_asks_next_history_entry(user_input_line);
	}
	else
	{
		setup_signals(&sa);
		signal(SIGINT, sigint_for_heredoc);
		user_input_line = readline("captain'hirdock>");
	}
	setup_default_signals_handling();
	return (user_input_line);
}
