/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:29:15 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/23 19:29:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	skip_quotes(const char *input)
{
	const char	*next;

	next = NULL;
	if (*input == '\'')
		next = ft_strchr(input + 1, '\'');
	else if (*input == '\"')
		next = ft_strchr(input + 1, '\"');
	if (next == NULL)
		next = input;
	return (next - input);
}

t_token_list	tokenize_word(const char *input, t_token_list token_list)
{
	size_t	i;
	t_lexem	lexem;

	i = 0;
	while (is_input_end(input + i) == false
		&& is_separator(input[i]) == false
		&& is_operator(input[i]) == NULL)
	{
		i += skip_quotes(input + i) + 1;
	}
	lexem = ft_strndup(input, i);
	if (lexem == NULL)
		return (NULL);
	token_list = add_token_to_token_list(token_list, lexem, WORD);
	free(lexem);
	return (token_list);
}
