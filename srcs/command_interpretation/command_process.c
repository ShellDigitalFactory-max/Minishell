/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:23:58 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/04 14:24:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setup_command_redirections(t_command *command)
{
	if (command->command_redirections.in_stream != STDIN_FILENO && command->command_redirections.in_stream!= -1)
	{
		dup2(command->command_redirections.in_stream, STDIN_FILENO);
		close(command->command_redirections.in_stream);
	}
	if (command->command_redirections.out_stream != STDOUT_FILENO && command->command_redirections.out_stream != -1)
	{
		dup2(command->command_redirections.out_stream, STDOUT_FILENO);
		close(command->command_redirections.out_stream);
	}
	if (command->command_redirections.opening_status == OPENING_ERROR)
	{
		ft_dprintf(STDERR_FILENO, "%s\n", command->opening_failure_msg);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	close_command_process_unused_fds(t_minishell_context *minishell_context, t_command *command)
{
	t_command_pipeline	cmd_pipeline;

	cmd_pipeline = minishell_context->command_session.command_pipeline;
	while (cmd_pipeline)
	{
		if (cmd_pipeline->content != command)
		{
			if (((t_command *)cmd_pipeline->content)->command_redirections.in_stream != -1)
				close(((t_command *)cmd_pipeline->content)->command_redirections.in_stream);
			if (((t_command *)cmd_pipeline->content)->command_redirections.out_stream != -1)
				close(((t_command *)cmd_pipeline->content)->command_redirections.out_stream);
		}
		cmd_pipeline = cmd_pipeline->next;
	}
}

void	command_process(t_minishell_context *minishell_context, t_command *command)
{
	close_command_process_unused_fds(minishell_context, command);
	if (setup_command_redirections(command) == EXIT_FAILURE)
	{
		clean_command_process(minishell_context);
		delete_command_pipeline(&minishell_context->command_session.command_pipeline);
		exit(FAILURE);
	}
	if (command->command_nature == BUILTIN)
		execute_builtin(minishell_context, command, BUILTIN_IN_PIPELINE);
	if (execute_command(command) == INVALID_COMMAND)
	{
		clean_command_process(minishell_context);
		delete_command_pipeline(&minishell_context->command_session.command_pipeline);
		exit(FAILURE);
	}
}
