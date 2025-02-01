/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_interpreter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:13:43 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/31 17:13:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int launch_command(t_command_pipeline cmd_pipeline)
{
	pid_t	child_pid;

	//setup_command();
	child_pid = fork();
	if (child_pid < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: error during process forking. "
		"Abort.\n");
		exit(FAILURE);
	}
	if (child_pid == 0)
	{
		execute_command(cmd_pipeline->content);
	}
	waitpid(child_pid, NULL, 0);
	return (EXIT_SUCCESS);
}

int	command_interpreter(t_minishell_context *minishell_context)
{
	t_command_pipeline	cmd_pipeline;

	cmd_pipeline = minishell_context->command_session.command_pipeline;
	if (((t_command *)cmd_pipeline->content)->command_nature == ONLY_ASSIGNATION)
	{
		add_command_env_to_shell_env(
			((t_command *)cmd_pipeline->content)->command_environment);
		return (EXIT_SUCCESS);
	}
	if (((t_command *)cmd_pipeline->content)->command_nature == BUILTIN)
	{
		return (launch_builtin(cmd_pipeline->content));
	}
	return (launch_command(cmd_pipeline));
}
