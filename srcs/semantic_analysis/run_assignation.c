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

t_semantic_analysis_state_return state_assignation(t_token *current_token)
{
	t_machine_states	machine_next_state;

	if (current_token->token_type == TOKEN_LIST_START)
		return (machine_next_state = ASSIGNATION);
	if (current_token->token_type == TOKEN_LIST_END)
		return (machine_next_state = SEMANTIC_PROCESS_END);
	if (assignation_checker(current_token->token_lexem) == INVALID_ASSIGNATION)
	{
		return (machine_next_state = REDIRECTION);
	}
	else
		if (add_assignation_to_temp_env(current_token->token_lexem)
				== PROCESS_FAILURE)
		{
			ft_dprintf(STDERR_FILENO, "minishell: malloc error during"
			" temporary environment building. Aborting\n");
			exit(FAILURE);
		}
	return (machine_next_state = ASSIGNATION);
}