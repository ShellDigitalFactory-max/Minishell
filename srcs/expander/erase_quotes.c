/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:21:03 by linux             #+#    #+#             */
/*   Updated: 2025/02/13 17:07:46 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_surrounded_by_quotes(char *word)
{
	size_t	word_len;

	if (word == NULL || *word == '\0')
		return (false);
	word_len = ft_strlen(word);
	if (word_len < 2)
		return (false);
	if (*word == '\"' && word[word_len -1] == '\"')
		return (true);
	else if (*word == '\'' && word[word_len -1] == '\'')
		return (true);
	else
		return (false);
}

static char	*erase_quotes_in_word(t_lexem word, t_quote_state *quote_state)
{
	size_t	i;
	size_t	j;
	t_lexem	new_word;

	i = 0;
	j = 0;
	new_word = ft_calloc(ft_strlen(word) + 1, sizeof(char));
	if (new_word == NULL)
		expander_exit();
	while (word[i] != '\0')
	{
		if (is_quote(word[i], *quote_state) == false)
		{
			new_word[j] = word[i];
			++j;
		}
		else
			change_quote_state(word[i], quote_state);
		++i;
	}
	return (new_word);
}

void	erase_quotes(t_token_list token_list)
{
	t_list			*current_token;
	t_token			*token;
	char			*expanded_token;
	t_quote_state	quote_state;

	current_token = token_list;
	quote_state = NO_QUOTE;
	while (current_token)
	{
		token = current_token->content;
		if (token->token_type == WORD)
		{
			token->is_surrounded_by_quotes
				= is_surrounded_by_quotes(token->token_lexem);
			expanded_token = erase_quotes_in_word(token->token_lexem,
					&quote_state);
			free(token->token_lexem);
			token->token_lexem = expanded_token;
		}
		current_token = current_token->next;
	}
}
