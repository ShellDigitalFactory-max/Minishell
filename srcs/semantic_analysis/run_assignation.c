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

static t_status	add_assignation_to_temp_env(t_lexem token_lexem)
{
	t_temporary_environment	*temp_env;
	t_temporary_environment	new_node;
	char					*assignation;

	temp_env = get_temp_env();
	assignation = ft_strdup(token_lexem);
	if (assignation == NULL)
		return (PROCESS_FAILURE);
	new_node = ft_lstnew(assignation);
	if (new_node == NULL)
		return (PROCESS_FAILURE);
	ft_lstadd_back(temp_env, new_node);
	return (PROCESS_SUCCESS);
}

t_machine_states	run_assignation(t_token *current_token)
{
	t_machine_states	machine_next_state;
	char				*assignation_value;

	if (current_token->token_type == TOKEN_LIST_START)
		return (machine_next_state = ASSIGNATION);
	if (current_token->token_type == TOKEN_LIST_END)
		return (machine_next_state = SEMANTIC_PROCESS_END);
	assignation_value = NULL;
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