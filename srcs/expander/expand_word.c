/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:47:34 by linux             #+#    #+#             */
/*   Updated: 2025/02/04 06:28:00 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_expanded_word(t_lexem *expanded_word)
{
	*expanded_word = ft_strdup("");
}

static t_lexem	choose_expand(t_lexem word, size_t *i, t_lexem expanded_word)
{
	if (word[*i] == '$')
	{
		expanded_word = expand_variable(word, i, expanded_word);
	}
	if (word[*i] == '~')
	{
		expanded_word = expand_tilde(i, expanded_word);
	}
	else
		expanded_word = no_expand(word, i, expanded_word);

	return (expanded_word);
}

t_lexem	expand_word(t_lexem word)
{
	t_lexem	expanded_word;
	size_t	i;

	if (word == NULL)
		return (NULL);
	init_expanded_word(&expanded_word);
	if (expanded_word == NULL)
		return (NULL);
	i = 0;
	expanded_word = NULL;
	while (word[i] != '\0')
	{
		expanded_word = choose_expand(word, &i, expanded_word);
	}
	return (expanded_word);
}
