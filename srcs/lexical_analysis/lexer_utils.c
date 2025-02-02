/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:33:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/21 15:33:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_input_end(const char *input)
{
	return (*input == '\0');
}

bool	is_separator(const char c)
{
	return (c == ' ' || c == '\t');
}

char	*is_operator(const char c)
{
	return (ft_strchr(OPERATORS_DICTIONARY, c));
}
