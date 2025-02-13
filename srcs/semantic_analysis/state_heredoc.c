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

static bool	is_delimiter(const char *delimiter, const char *line)
{
	const size_t	delimiter_size = ft_strlen(delimiter);
	const size_t	line_size = ft_strlen(line);

	return (delimiter_size == line_size && ft_strcmp(line, delimiter) == 0);
}

static char	*build_heredoc_content(const char *delimiter)
{
	char	*new_line;
	char	*heredoc_content;
	char	*temp_line;

	heredoc_content = ft_strdup("");
	while (HEREDOC_PROCESSING)
	{
		if (stop == 1)
			break;
		temp_line = prompt_gets_user_input(SUBPROMPT);
		if (stop == 1)
			break;
		if (temp_line == CTRL_D || is_delimiter(delimiter, temp_line))
		{
			free(temp_line);
			break ;
		}
		ft_asprintf(&new_line, "%s%s\n", heredoc_content, temp_line);
		free(temp_line);
		free(heredoc_content);
		heredoc_content = new_line;
	}
	return (heredoc_content);
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
	stop = 0;
	heredoc_content = build_heredoc_content(current_token->token_lexem);
	save_heredoc_content(current_command, heredoc_content, pipefd);
	if (current_command->command_args == NULL)
		semantic_machine->machine_state = STATE_ASSIGNATION;
	else
		semantic_machine->machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}
