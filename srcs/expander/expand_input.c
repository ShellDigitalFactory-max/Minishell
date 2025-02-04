/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:02:16 by linux             #+#    #+#             */
/*   Updated: 2025/02/04 06:23:39 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void expand_input(t_token_list token_list)
{
	t_list	*current_token;
	t_token	*token;
	char	*expanded_token;

	current_token = token_list;
	while (current_token)
	{
		token = current_token->content;
		if (token->token_type == WORD)
		{
			expanded_token = expand_word(token->token_lexem);
			free(token->token_lexem);
			token->token_lexem = expanded_token;
		}
		current_token = current_token->next;
	}
}

