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

t_semantic_analysis_state_return	state_heredoc(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command)
{
	(void)current_token;
	(void)current_command;
	*machine_state = STATE_COMMAND;
	return (TOKEN_PROCESSED);
}