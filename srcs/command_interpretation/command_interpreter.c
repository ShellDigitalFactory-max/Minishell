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

static t_builtin_type	get_builtin_type(const char *command_name)
{
	static const char	*builtins_dictionary[] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit",
		NULL,
	};
	t_builtin_type	type;

	type = ECHO;
	while (builtins_dictionary[type] != NULL)
	{
		if (ft_strcmp(builtins_dictionary[type], command_name) == 0)
			break ;
		++type;
	}
	return (type);
}

static int launch_builtin(t_command *command)
{
	const t_builtin_type	builtin_type
								= get_builtin_type(command->command_name);

	static t_builtin	builtins[] = {
		echo,
		cd,
		pwd,
		export,
		unset,
		env,
		exit,
	};

	return (builtins[builtin_type]);
}

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
}

int	command_interpreter(t_minishell_context *minishell_context)
{
	t_command_pipeline	cmd_pipeline;

	cmd_pipeline = minishell_context->command_session.command_pipeline;
	if (((t_command *)cmd_pipeline->content)->command_nature == ONLY_ASSIGNATION)
	{
		add_command_env_to_shell_env(((t_command *)cmd_pipeline->content)->command_environment);
		print_env(get_environment());
		return (EXIT_SUCCESS);
	}
	if (((t_command *)cmd_pipeline->content)->command_nature == BUILTIN)
	{
		return (launch_builtin());
	}
	return (launch_command(cmd_pipeline));
}
