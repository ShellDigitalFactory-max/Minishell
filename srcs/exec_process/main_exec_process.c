/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:21:45 by linux             #+#    #+#             */
/*   Updated: 2025/01/15 18:08:12 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_status	exec_word(t_token *token)
{
	if (is_builtin_command(token->token_lexem) == true)
	{
		exec_builtin(token->token_lexem);
	}
	return (PROCESS_SUCCESS);
}

static	t_status	exec_token(t_token *token)
{
	static t_status	(*token_handlers[])(t_token *token) = {
		[PIPE_OPERATOR] = NULL,
		[INPUT_REDIR_OPERATOR] = NULL,
		[OUTPUT_REDIR_OPERATOR] = NULL,
		[APPEND_OPERATOR] = NULL,
		[HEREDOC_OPERATOR] = NULL,
		[TOKEN_LIST_START] = NULL,
		[TOKEN_LIST_END] = NULL,
		[WORD] = &exec_word,
		[INVALID_TOKEN] = NULL
	};
	token_handlers[token->token_type](token);
	return (PROCESS_SUCCESS);
}

t_status	exec_process(t_minishell_context *ms_context)
{
	t_token_list	token_list;
	t_token			*token;

	token_list = ms_context->command_session.tokenized_user_input_line;
	while (token_list != NULL)
	{
		if (token_list->content != NULL)
		{
			token = (t_token *)token_list->content;
			if (token->token_lexem != NULL && token->token_type != INVALID_TOKEN && token->token_type != TOKEN_LIST_START && token->token_type != TOKEN_LIST_END)
				exec_token(token);
		}
		token_list = token_list->next;
	}
	return (PROCESS_SUCCESS);
}
