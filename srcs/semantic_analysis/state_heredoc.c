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

static char	*build_heredoc_content(const char *delimiter)
{
	char	*new_line;
	char	*line;
	char	*temp_line;

	line = ft_strdup("");
	while(true)
	{
		temp_line = readline(">");
		// if (temp_line[0] == '\0')
		// {
		// 	rl_replace_line("", 0);
		// 	rl_redisplay();
		// }
		if (ft_strcmp(delimiter, temp_line) == 0)
		{
			free(temp_line);
			break;
		}
		ft_asprintf(&new_line, "%s%s\n", line, temp_line);
		free(line);
		line = new_line;
		free(temp_line);
	}
	return (line);
}

t_semantic_analysis_state_return	state_heredoc(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command)
{
	int		pipefd[2];
	(void)current_command;
	char	*heredoc_content;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(FAILURE);
	}
	heredoc_content = build_heredoc_content(current_token->token_lexem);
	write(pipefd[1], heredoc_content, ft_strlen(heredoc_content));
	free(heredoc_content);
	close(pipefd[1]);
	close(pipefd[0]);
	current_command->command_redirections.in_stream = pipefd[0];
	*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}
