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

static bool	is_command_alone(t_command_pipeline	command_pipeline)
{
	return (ft_lstsize(command_pipeline) == 1);
}

static void	main_process_io_management(t_command *command)
{
	if (command->command_redirections.in_stream > STDIN_FILENO)
	{
		close(command->command_redirections.in_stream);
	}
	if (command->command_redirections.out_stream > STDOUT_FILENO)
	{
		close(command->command_redirections.out_stream);
	}
}

static void	launch_command(t_minishell_context *minishell_context,
				t_command *command)
{
	pid_t	command_process_pid;

	command_process_pid = fork();
	if (command_process_pid < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: error during process forking. "
			"Aborting.\n");
		exit(FAILURE);
	}
	command->command_pid = command_process_pid;
	if (command_process_pid > 0)
	{
		main_process_io_management(command);
	}
	if (command_process_pid == 0)
	{
		command_process(minishell_context, command);
	}
}

static void	command_interpreter(t_minishell_context *minishell_context,
				t_command *command)
{
	if (command->command_nature == ONLY_ASSIGNATION
		&& is_command_alone(
			minishell_context->command_session.command_pipeline))
	{
		add_command_env_to_shell_env(command->command_environment);
	}
	else if (command->command_nature == BUILTIN
		&& is_command_alone(
			minishell_context->command_session.command_pipeline))
	{
		set_exit_status(execute_builtin(minishell_context, command,
				BUILTIN_ALONE));
	}
	else
		launch_command(minishell_context, command);
}

int	command_pipeline_interpreter(t_minishell_context *minishell_context)
{
	t_command_pipeline	cmd_pipeline;
	t_command_pipeline	current_command;
	pid_t				last_command_pid;

	cmd_pipeline = minishell_context->command_session.command_pipeline;
	current_command = cmd_pipeline;
	while (current_command != NULL)
	{
		command_interpreter(minishell_context, current_command->content);
		last_command_pid = ((t_command *)current_command->content)->command_pid;
		current_command = current_command->next;
	}
	if (ft_lstsize(cmd_pipeline) == 1
		&& ((t_command *)cmd_pipeline->content)->command_nature == BUILTIN)
		return (get_exit_status_value());
	if (ft_lstsize(cmd_pipeline) == 1
		&& ((t_command *)cmd_pipeline->content)->command_nature == ONLY_ASSIGNATION)
		return (get_exit_status_value());
	else
		return (close_command_pipeline(cmd_pipeline, last_command_pid));
}
