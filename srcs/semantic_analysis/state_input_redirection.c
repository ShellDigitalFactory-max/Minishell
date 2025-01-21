/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_input_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:59 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/20 15:32:09 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display_opening_errors(t_lexem file_name)
{
	if (errno == ENOENT)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: No such file or directory\n",
			file_name);
	}
	else if (errno == EACCES)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: Permission denied\n",
			file_name);
	}
	else if (errno == EMFILE || errno == ENFILE)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: Too many open files\n",
			file_name);
	}
	else
		ft_dprintf(STDERR_FILENO, "minishell: %s: failed to open %s: %s\n",
			file_name, strerror(errno));
}

t_semantic_analysis_state_return state_input_redirection(
									t_machine_states *machine_state,
									t_token *current_token,
									t_command *current_command)
{
	int	infile_fd;

	if (current_command->command_redirections.in_stream > STDIN_FILENO)
	{
		if (close(current_command->command_redirections.in_stream) == -1)
			perror("minishell: close");
	}
	infile_fd = open(current_token->token_lexem, O_RDONLY | __O_CLOEXEC);
	if (infile_fd < 0)
	{
		display_opening_errors(current_token->token_lexem);
		*machine_state = STATE_COMMAND;
		current_command->command_redirections.in_stream = infile_fd;
		return (TOKEN_PROCESSED);
	}
	current_command->command_redirections.in_stream = infile_fd;
	if (current_command->command_name == NULL)
		*machine_state = STATE_ASSIGNATION;
	else
		*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}