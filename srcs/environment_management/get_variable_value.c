/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:34:36 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/09 17:34:52 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_variable_value(const char *keyvalue)
{
	char	*value;
	size_t	i;

	i = 0;
	while (keyvalue[i] != EQUAL_OPERATOR)
	{
		++i;
	}
	value = ft_strdup(keyvalue + (i + 1));
	return (value);
}
