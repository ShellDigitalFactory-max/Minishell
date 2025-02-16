/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:16 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/16 22:50:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_process(t_minishell_context *minishell_context,
			t_command *command)
{
	clean_command_process(minishell_context);
	delete_command_pipeline(
		&minishell_context->command_session.command_pipeline);
	close_command_process_unused_fds(minishell_context, command);
	get_minishell_context(NULL, 1);
}
