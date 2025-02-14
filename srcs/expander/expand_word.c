/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:47:34 by linux             #+#    #+#             */
/*   Updated: 2025/02/13 23:09:54 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_expanded_word(t_lexem *expanded_word)
{
	*expanded_word = ft_strdup("");
	if (*expanded_word == NULL)
	{
		expander_exit();
	}
}

static t_lexem	choose_expand(t_lexem word, size_t *i, t_lexem expanded_word,
	t_quote_state *quote_state)
{
	if (word[*i] == '$' && *quote_state != SINGLE_QUOTE)
	{
		expanded_word = expand_variable(word, i, expanded_word, *quote_state);
	}
	if (word[*i] == '~' && *quote_state == NO_QUOTE)
	{
		expanded_word = expand_tilde(i, expanded_word);
	}
	else
		expanded_word = no_expand(word, i, expanded_word, quote_state);
	return (expanded_word);
}

t_lexem	expand_word(t_lexem word, t_quote_state *quote_state)
{
	t_lexem	expanded_word;
	size_t	i;

	if (word == NULL)
		return (NULL);
	init_expanded_word(&expanded_word);
	i = 0;
	while (word[i] != '\0')
	{
		expanded_word = choose_expand(word, &i, expanded_word,
				quote_state);
	}
	return (expanded_word);
}
