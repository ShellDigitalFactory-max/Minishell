/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_command_pipeline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:17:14 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/11 15:17:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	close_command_pipeline(t_command_pipeline cmd_pipeline,
		pid_t last_command_pid)
{
	pid_t	current_command_pid;
	int		last_command_status;
	int		exit_status;

	while (cmd_pipeline != NULL)
	{
		current_command_pid
			= waitpid(((t_command *)cmd_pipeline->content)->command_pid,
				&last_command_status, 0);
		if (current_command_pid == last_command_pid)
		{
			if (WIFEXITED(last_command_status))
				exit_status = WEXITSTATUS(last_command_status);
			else if (WIFSTOPPED(last_command_status))
				exit_status = 128 + WSTOPSIG(last_command_status);
			else if (WIFSIGNALED(last_command_status))
				exit_status = (128 + WTERMSIG(last_command_status));
			else
				exit_status = -1;
		}
		cmd_pipeline = cmd_pipeline->next;
	}
	set_exit_status(exit_status);
	return (exit_status);
}
