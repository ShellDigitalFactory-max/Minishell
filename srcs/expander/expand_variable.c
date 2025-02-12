/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:33:56 by linux             #+#    #+#             */
/*   Updated: 2025/02/12 15:27:30 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lexem	manage_specific_case(t_lexem word, t_lexem expanded_word,
		size_t *i)
{
	t_lexem	temp_expanded;

	printf("manage_specific_case\n");
	temp_expanded = expanded_word;
	if (word[*i + 1] == '?')
	{
		expanded_word = ft_strjoin(temp_expanded,
				ft_itoa(get_exit_status_value()));
		++(*i);
		free(temp_expanded);
	}
	else if (word[*i + 1] != '\"' && word[*i + 1] != '\'')
	{
		expanded_word = ft_strjoin(temp_expanded, "$");
		free(temp_expanded);
	}
	++(*i);
	return (expanded_word);
}

static t_lexem	init_variable_from_env(t_lexem expanded_word,
	t_lexem variable_name)
{
	t_lexem	variable_value;

	variable_value = get_variable_from_env(variable_name);
	if (variable_value == NULL)
	{
		free(expanded_word);
		free(variable_name);
		expander_exit();
	}
	return (variable_value);
}

static char	*get_variable_name(t_lexem word, size_t *i, t_lexem expanded_word)
{
	size_t		j;
	char		*variable_name;

	j = *i;
	if (ft_isdigit(word[j]))
	{
		++j;
	}
	else
	{
		while (ft_isalnum(word[j]) || word[j] == '_')
		{
			++j;
		}
	}
	variable_name = ft_substr(word, *i, j - *i);
	if (variable_name == NULL)
	{
		free(expanded_word);
		expander_exit();
	}
	*i = j;
	return (variable_name);
}

static bool	is_not_valid_variable_name(char *variable_name, size_t *i)
{
	if (variable_name[*i] == '$' && ft_isalnum(variable_name[*i + 1]) == 0
		&& variable_name[*i + 1] != '_')
		return (true);
	return (false);
}

t_lexem	expand_variable(t_lexem word, size_t *i, t_lexem expanded_word)
{
	t_lexem		variable_name;
	t_lexem		variable_value;
	t_lexem		temp_word;

	if (is_not_valid_variable_name(word, i) == true)
	{
		expanded_word = manage_specific_case(word, expanded_word, i);
		++(*i);
		return (expanded_word);
	}
	++(*i);
	variable_name = get_variable_name(word, i, expanded_word);
	variable_value = init_variable_from_env(expanded_word, variable_name);
	temp_word = expanded_word;
	expanded_word = ft_strjoin(expanded_word, variable_value);
	free(variable_name);
	free(variable_value);
	free(temp_word);
	return (expanded_word);
}
