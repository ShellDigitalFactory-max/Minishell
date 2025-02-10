/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:33:56 by linux             #+#    #+#             */
/*   Updated: 2025/02/10 16:26:24 by linux            ###   ########.fr       */
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
	t_lexem		temp_word;

	++(*i);
	variable_name = get_variable_name(word, i);
	if (variable_name == NULL)
	{
		free(expanded_word);
		expander_exit();
	}
	variable_value = get_variable_from_env(variable_name);
	if (variable_value == NULL)
	{
		free(expanded_word);
		free(variable_name);
		expander_exit();
	}
	temp_word = expanded_word;
	expanded_word = ft_strjoin(expanded_word, variable_value);
	free(variable_name);
	free(variable_value);
	free(temp_word);
	return (expanded_word);
}
