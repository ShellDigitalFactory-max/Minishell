/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:11:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/27 14:11:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexing_status	lexe_input(t_command_session *current_command)
{
	current_command->tokenized_user_input_line
		= tokenize(current_command->user_input_line);
	if (current_command->tokenized_user_input_line == NULL)
		return (LEXING_FAILURE);
	return (LEXING_SUCCESS);
}
