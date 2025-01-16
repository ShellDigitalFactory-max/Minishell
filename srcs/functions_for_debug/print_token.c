/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:54:43 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/16 12:14:11 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(void *content)
{
	const char		*token_types[] = {"PIPE", "INPUT_REDIR",
		"OUTPUT_REDIR", "APPEND_OPERATOR", "HEREDOC",
		"TOKEN_LIST_START", "TOKEN_LIST_END", "WORD"};
	const t_token	*token = (t_token *)content;

	if (token != NULL)
	{
		printf("Lexem: %s\n", token->token_lexem);
		printf("Type: %s\n", token_types[token->token_type]);
		printf("\n");
	}
}
