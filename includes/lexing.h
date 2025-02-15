/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:01:04 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/18 17:01:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

// INCLUDES

# include "minishell.h"

// DEFINES

# define SEPARATORS_DICTIONARY " \t"
# define OPERATORS_DICTIONARY "|<>"

// TYPEDEFS

typedef t_list *	t_token_list;
typedef char *		t_lexem;

// ENUMS

typedef enum e_types_matching_status
{
	MATCH_FOUND,
	NO_MATCH_FOUND
}			t_types_matching_status;

typedef enum e_lexing_status
{
	LEXING_SUCCESS,
	LEXING_FAILURE
}			t_lexing_status;

typedef enum e_token_type
{
	PIPE_OPERATOR,
	INPUT_REDIR_OPERATOR,
	OUTPUT_REDIR_OPERATOR,
	APPEND_OPERATOR,
	HEREDOC_OPERATOR,
	TOKEN_LIST_START,
	TOKEN_LIST_END,
	WORD,
	INVALID_TOKEN
}			t_token_type;

// STRUCTURES

typedef struct s_token
{
	t_lexem			token_lexem;
	t_token_type	token_type;
	bool			is_surrounded_by_quotes;
}				t_token;

typedef t_token		t_grammar_element;

// PROTOTYPES

t_token			*create_token(char *lexem, t_token_type token_type);
t_token_list	add_token_to_token_list(t_token_list token_list,
					t_lexem token_lexem, t_token_type token_type);
void			print_token(void *content);
void			print_token_list(t_token_list token_list);
void			delete_token(void *data);
void			delete_token_list(t_token_list token_list);

t_token_list	tokenize(const char *input);
t_token_list	tokenize_operator(const char *input,
					t_token_list token_list);
t_token_list	tokenize_word(const char *input,
					t_token_list token_list);
bool			is_input_end(const char *input);
bool			is_separator(const char c);
char			*is_operator(const char c);
t_token_type	search_operator_in_lexer_dictionary(
					const char operator);
size_t			get_last_lexem_size(t_token_list token_list);

#endif
