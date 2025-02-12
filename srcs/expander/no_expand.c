/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:09:59 by linux             #+#    #+#             */
/*   Updated: 2025/02/12 02:28:36 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_no_expand(char c, t_quote_state quote_state)
{
	if (quote_state == SINGLE_QUOTE && (c == '$' || c == '~'))
		return (true);
	else if (quote_state == DOUBLE_QUOTE && c == '~')
		return (true);
	else if ((quote_state == SINGLE_QUOTE && c == '\"')
		|| (quote_state == DOUBLE_QUOTE && c == '\''))
		return (true);
	else if (c != '~' && c != '\0' && c != '\'' && c != '\"' && c != '$')
		return (true);
	return (false);
}

t_lexem	no_expand(t_lexem word, size_t *i, t_lexem expanded_word,
	t_quote_state quote_state)
{
	size_t	i_nexp;
	t_lexem	tmp;
	t_lexem	tmp_no_expand;

	i_nexp = *i;
	while (is_no_expand(word[i_nexp], quote_state))
	{
		++i_nexp;
	}
	tmp = expanded_word;
	tmp_no_expand = ft_substr(word, *i, i_nexp - *i);
	expanded_word = ft_strjoin(expanded_word, tmp_no_expand);
	free(tmp);
	free(tmp_no_expand);
	*i = i_nexp;
	return (expanded_word);
}
