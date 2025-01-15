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

t_machine_states	run_assignation(t_token *current_token,
						t_command_data *current_command_data,
						char **temp_environment)
{
	t_machine_states	machine_next_state;
	char				*assignation_value;

	assignation_value = NULL;
	if (assignation_checker(current_token->token_lexem) == INVALID_ASSIGNATION)
	{
		return (machine_next_state = REDIRECTION);
	}
	else
}