/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:43:59 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/20 15:44:07 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_command_default_redirections(t_command *command)
{
	command->command_redirections.in_stream = STDIN_FILENO;
	command->command_redirections.out_stream = STDOUT_FILENO;
}

t_command	*create_command(void)
{
	t_command	*new_command;

	new_command = (t_command *)ft_calloc(1, sizeof(t_command));
	if (new_command == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during "
		"semantic analysis. Aborting\n");
		exit(FAILURE);
	}
	setup_command_default_redirections(new_command);
	new_command->command_nature = ONLY_ASSIGNATION;
	return (new_command);
}