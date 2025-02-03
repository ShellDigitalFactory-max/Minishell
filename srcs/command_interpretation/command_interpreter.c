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

static int launch_command(t_minishell_context *minishell_context,
				t_command *command)
{
	pid_t	child_pid;

	//setup_command();
	child_pid = fork();
	if (child_pid < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: error during process forking. "
		"Aborting.\n");
		exit(FAILURE);
	}
	if (child_pid == 0)
	{
		if (execute_command(command) == INVALID_COMMAND)
		{
			clean_child_process(minishell_context);
			exit (EXIT_FAILURE);
		}
	}
	waitpid(child_pid, NULL, 0);
	return (EXIT_SUCCESS);
}

static int	command_interpreter(t_minishell_context *minishell_context, t_command *command)
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

	cmd_pipeline = minishell_context->command_session.command_pipeline;
	return (command_interpreter(minishell_context, cmd_pipeline->content));
}
