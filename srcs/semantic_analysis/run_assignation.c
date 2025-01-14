/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_assignation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:25:34 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/14 14:25:50 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_machine_states	run_assignation(t_token_list current_token,
						t_command_data *current_command_data)
{
	const t_token_list	token = (t_token_list)current_token;
	t_machine_states	next_machine_state;

	if (((t_token *)token->next->content)->token_type == TOKEN_LIST_END)
		return (next_machine_state = END);
	if (assignation_checker(((t_token *)token->content)->token_lexem)
			== INVALID_ASSIGNATION)
		return (next_machine_state = INPUT_REDIR);
	if (((t_token *)token->next->content)->token_type == WORD)
		store_assignation(((t_token *)token->content)->token_lexem);
	return (next_machine_state = ASSIGNATION);
}