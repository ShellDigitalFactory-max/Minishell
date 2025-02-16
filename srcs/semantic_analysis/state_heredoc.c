/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:38 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/22 18:51:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*process_data(char *heredoc_content, char *temp_line)
{
	ensure_stdin_is_open();
	if (g_received_signal == 130)
		set_exit_status(130);
	free(temp_line);
	return (heredoc_content);
}

static void	update_heredoc_content(char **heredoc_content, char *temp_line,
				char *new_line, int *heredoc_lines)
{
	ft_asprintf(&new_line, "%s%s\n", *heredoc_content, temp_line);
	free(temp_line);
	free(*heredoc_content);
	*heredoc_content = new_line;
	if (*heredoc_lines == 0)
		*(heredoc_lines) += 2;
	else
		++*(heredoc_lines);
}

static char	*build_heredoc_content(const char *delimiter)
{
	char		*new_line;
	char		*heredoc_content;
	char		*temp_line;
	int			lines;

	lines = 0;
	heredoc_content = ft_strdup("");
	new_line = NULL;
	while (HEREDOC_PROCESSING)
	{
		if (g_received_signal == SIGINT)
			break ;
		temp_line = prompt_gets_user_input(SUBPROMPT);
		if (g_received_signal == SIGINT)
			break ;
		if (temp_line == CTRL_D)
		{
			heredoc_interruption_routine(delimiter, lines);
			break ;
		}
		if (is_delimiter(delimiter, temp_line))
			break ;
		update_heredoc_content(&heredoc_content, temp_line, new_line, &lines);
	}
	return (process_data(heredoc_content, temp_line));
}

static void	save_heredoc_content(t_command *current_command,
									char *heredoc_content, int pipefd[2])
{
	write(pipefd[1], heredoc_content, ft_strlen(heredoc_content));
	free(heredoc_content);
	close(pipefd[1]);
	if (current_command->command_redirections.in_stream > STDIN_FILENO)
	{
		if (close(current_command->command_redirections.in_stream) == -1)
			perror("minishell: close");
	}
	current_command->command_redirections.in_stream = pipefd[0];
}

t_semantic_analysis_state_return	state_heredoc(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command)
{
	int		pipefd[2];
	char	*heredoc_content;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(FAILURE);
	}
	heredoc_content = build_heredoc_content(current_token->token_lexem);
	save_heredoc_content(current_command, heredoc_content, pipefd);
	if (current_command->command_args == NULL)
		semantic_machine->machine_state = STATE_ASSIGNATION;
	else
		semantic_machine->machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}
