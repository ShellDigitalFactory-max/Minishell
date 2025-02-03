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

static void	clean_child_process(t_minishell_context *minishell_context)
{
	delete_variables_list();
	delete_token_list(minishell_context->command_session.tokenized_user_input_line);
	delete_command_pipeline(&minishell_context->command_session.command_pipeline);
}

static int	setup_command_redirections(t_command *command)
{
	if (command->command_redirections.opening_status == OPENING_ERROR)
	{
		ft_dprintf(STDERR_FILENO, "%s\n", command->opening_failure_msg);
		return (EXIT_FAILURE);
	}
	if (command->command_redirections.in_stream != STDIN_FILENO)
	{
		dup2(command->command_redirections.in_stream, STDIN_FILENO);
		close(command->command_redirections.in_stream);
	}
	if (command->command_redirections.out_stream != STDOUT_FILENO)
	{
		dup2(command->command_redirections.out_stream, STDOUT_FILENO);
		close(command->command_redirections.out_stream);
	}
	return (EXIT_SUCCESS);
}

static int	command_process(t_minishell_context *minishell_context, t_command *command)
{
	if (setup_command_redirections(command) == EXIT_FAILURE || execute_command(command) == INVALID_COMMAND)
	{
		clean_child_process(minishell_context);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	launch_command(t_minishell_context *minishell_context,
				t_command *command)
{
	pid_t	command_process_pid;

	command_process_pid = fork();
	if (command_process_pid > 0)
	{
		if (command->command_redirections.in_stream > STDIN_FILENO)
			close(command->command_redirections.in_stream);
		if (command->command_redirections.out_stream > STDOUT_FILENO)
			close(command->command_redirections.out_stream);
	}

	if (command_process_pid < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: error during process forking. "
		"Aborting.\n");
		exit(FAILURE);
	}
	command->command_pid = command_process_pid;
	if (command_process_pid == 0)
	{
		if (command_process(minishell_context, command) == EXIT_FAILURE)
			exit(FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	command_interpreter(t_minishell_context *minishell_context,
				t_command *command)
{
	if (command->command_nature == ONLY_ASSIGNATION)
	{
		add_command_env_to_shell_env(command->command_environment);
		return (EXIT_SUCCESS);
	}
	if (command->command_nature == BUILTIN)
	{
		return (launch_builtin(command));
	}
	return (launch_command(minishell_context, command));
}

int	command_pipeline_interpreter(t_minishell_context *minishell_context)
{
	t_command_pipeline	cmd_pipeline;
	t_command_pipeline	current_command;

	cmd_pipeline = minishell_context->command_session.command_pipeline;
	current_command = cmd_pipeline;
	while (current_command != NULL)
	{
		command_interpreter(minishell_context, current_command->content);
		current_command = current_command->next;
	}
	while (cmd_pipeline != NULL)
	{
		waitpid(((t_command *)cmd_pipeline->content)->command_pid, NULL, 0);
		cmd_pipeline = cmd_pipeline->next;
	}
	return (EXIT_SUCCESS);
}
