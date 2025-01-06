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

t_lexing_status	lexe_input(t_current_loop_data *loop_data)
{
	loop_data->tokenized_user_input_line
		= tokenize(loop_data->user_input_line);
	if (loop_data->tokenized_user_input_line == NULL)
		return (LEXING_FAILURE);
	return (LEXING_SUCCESS);
}
