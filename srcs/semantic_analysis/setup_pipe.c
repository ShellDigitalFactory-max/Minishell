/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:49:37 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/09 19:49:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_pipe(t_semantic_machine *semantic_machine,
				t_command *command)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(FAILURE);
	}
	if (command->command_redirections.out_stream == STDOUT_FILENO)
		command->command_redirections.out_stream = pipefd[1];
	else
		close(pipefd[1]);
	semantic_machine->next_command_input = pipefd[0];
}
