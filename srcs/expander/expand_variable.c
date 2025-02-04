/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:33:56 by linux             #+#    #+#             */
/*   Updated: 2025/02/04 06:23:28 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_variable_name(t_lexem word, size_t *i)
{
	size_t		j;
	char		*variable_name;

	j = *i;
	while (ft_isalnum(word[j]) || word[j] == '_')
		++j;
	variable_name = ft_substr(word, *i, j - *i);
	*i = j;
	return (variable_name);
}

t_lexem	expand_variable(t_lexem word, size_t *i, t_lexem expanded_word)
{
	t_lexem		variable_name;
	t_lexem		variable_value;

	++(*i);
	variable_name = get_variable_name(word, i);
	variable_value = get_variable_from_env(variable_name);
	expanded_word = ft_strjoin(expanded_word, variable_value);
	free(variable_name);
	free(variable_value);
	return (expanded_word);
}
