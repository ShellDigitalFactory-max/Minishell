/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_output_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:28:23 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/20 21:28:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_semantic_analysis_state_return	state_output_redirection(
									t_machine_states *machine_state,
									t_token *current_token,
									t_command *current_command)
{
	size_t	i;

	i = 0;
	while (current_command->command_redirections.out_stream[i] != NULL)
		++i;
	if (i == MAX_REDIRECTIONS)
	{
		ft_dprintf(STDERR_FILENO, "minishell: too many redirections "
		"in a single command\n.");
		return (TOKEN_PROCESSED);
	}
	current_command->command_redirections.out_stream[i]
		= ft_strdup(current_token->token_lexem);
	if (current_command->command_redirections.out_stream[i]
			== NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc error during command "
		"pipeline building. Aborting\n");
		exit(FAILURE);
	}
	*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}