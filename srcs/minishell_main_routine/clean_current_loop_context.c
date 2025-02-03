/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_current_loop_context.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:43:13 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:29 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_current_loop_context(t_minishell_context *minishell_context)
{
	free(minishell_context->command_session.user_input_line);
	delete_token_list(
		minishell_context->command_session.tokenized_user_input_line);
	delete_command_pipeline(
		&minishell_context->command_session.command_pipeline);
}