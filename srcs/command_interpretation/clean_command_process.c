/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_command_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:26:32 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/04 14:26:47 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_command_process(t_minishell_context *minishell_context)
{
	delete_variables_list();
	delete_token_list(
		minishell_context->command_session.tokenized_user_input_line);
	delete_command_pipeline(
		&minishell_context->command_session.command_pipeline);
}