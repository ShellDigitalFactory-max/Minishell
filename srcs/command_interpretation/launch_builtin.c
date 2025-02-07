/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:21:50 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/01 18:22:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin_type	get_builtin_type(const char *command_name)
{
	static const char	*builtins_dictionary[] = {
		"env",
		"export",
		NULL,
	};
	t_builtin_type	type;

	type = 0;
	while (builtins_dictionary[type] != NULL)
	{
		if (ft_strcmp(builtins_dictionary[type], command_name) == 0)
			break ;
		++type;
	}
	return (type);
}

static int	execute_alone_builtin(t_command *command, t_builtin builtin)
{
	int	builtin_return;
	int	saved_stdout;

	saved_stdout = 0;
	if (command->command_redirections.out_stream != STDOUT_FILENO)
	{
		saved_stdout = dup(STDOUT_FILENO);
		dup2(command->command_redirections.out_stream, STDOUT_FILENO);
		close(command->command_redirections.out_stream);
	}
	builtin_return = builtin(command);
	if (saved_stdout != 0)
	{
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
	}
	return (builtin_return);
}

int	execute_builtin(t_minishell_context *minishell_context, t_command *command, bool is_in_pipeline)
{
	const t_builtin_type	builtin_type
								= get_builtin_type(command->command_name);

	static t_builtin		builtins[] = {
		env,
		export,
	};
	int						builtin_return;

	builtin_return = 0;
	if (is_in_pipeline == false)
	{
		return (execute_alone_builtin(command, builtins[builtin_type]));
	}
	if (is_in_pipeline == true)
	{	
		builtin_return = builtins[builtin_type](command);
		clean_command_process(minishell_context);
		delete_command_pipeline(&minishell_context->command_session.command_pipeline);
		close_command_process_unused_fds(minishell_context, command);
		exit(builtin_return);
	}
	return (builtin_return);
}
