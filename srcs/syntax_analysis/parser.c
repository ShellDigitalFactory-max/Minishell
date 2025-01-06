/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:05:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 17:15:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display_syntax_error(const t_token_list invalid_token)
{
	const t_token	*invalid_token_content = (t_token *)invalid_token->content;

	ft_dprintf(STDERR_FILENO, "minishell: syntax error near"
		" unexpected token `%s'\n", invalid_token_content->token_lexem);
}

static t_token_type	*get_possibilities_list(const t_token_type token_type)
{
	static t_token_type	following_possibilities[][9] = {
		//PIPE
	{INPUT_REDIR_OPERATOR, OUTPUT_REDIR_OPERATOR,
		APPEND_OPERATOR, HEREDOC_OPERATOR, WORD, INVALID_TOKEN},
		//INPUT_REDIR
	{WORD, INVALID_TOKEN},
		//OUTPUT_REDIR
	{WORD, INVALID_TOKEN},
		//APPEND
	{WORD, INVALID_TOKEN},
		//HEREDOC
	{WORD, INVALID_TOKEN},
		//START
	{INPUT_REDIR_OPERATOR, OUTPUT_REDIR_OPERATOR, APPEND_OPERATOR,
		HEREDOC_OPERATOR, TOKEN_LIST_END, WORD, INVALID_TOKEN},
		//END
	{TOKEN_LIST_END, INVALID_TOKEN},
		//WORD
	{PIPE_OPERATOR, INPUT_REDIR_OPERATOR,
		OUTPUT_REDIR_OPERATOR, APPEND_OPERATOR, HEREDOC_OPERATOR,
		TOKEN_LIST_END, WORD, INVALID_TOKEN},
	};

	return (following_possibilities[token_type]);
}

static t_types_matching_status	check_tokens_types(
			t_token_type current_token_type,
			t_token_type next_token_type)
{
	const t_token_type	*possibilities_list
		= get_possibilities_list(current_token_type);
	size_t				i;

	i = 0;
	while (possibilities_list[i] != INVALID_TOKEN)
	{
		if (next_token_type == possibilities_list[i])
			return (MATCH_FOUND);
		++i;
	}
	return (NO_MATCH_FOUND);
}

static t_syntax_status	check_tokens_sequence(t_token_list token)
{
	t_token	*current_token;
	t_token	*next_token;

	current_token = (t_token *)token->content;
	if (current_token->token_type == TOKEN_LIST_END)
	{
		return (VALID_SYNTAX);
	}
	next_token = (t_token *)token->next->content;
	if (check_tokens_types(current_token->token_type,
			next_token->token_type) == NO_MATCH_FOUND)
	{
		return (INVALID_SYNTAX);
	}
	return (PARSING_IN_PROGRESS);
}

t_syntax_status	parse_input(t_token_list token_list)
{
	t_token_list	current_token;
	t_syntax_status	parser_output;

	current_token = token_list;
	parser_output = PARSING_IN_PROGRESS;
	while (parser_output == PARSING_IN_PROGRESS)
	{
		parser_output = check_tokens_sequence(current_token);
		if (parser_output != INVALID_SYNTAX)
			current_token = current_token->next;
	}
	if (parser_output == INVALID_SYNTAX)
		display_syntax_error(current_token->next);
	//set variable $? !!!!
	return (parser_output);
}
