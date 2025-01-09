/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:49 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/09 17:28:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_variable_key(const char *keyvalue)
{
	char	*key;
	size_t	i;

	i = 0;
	while (keyvalue[i] != EQUAL_OPERATOR)
	{
		++i;
	}
	key = ft_strndup(keyvalue, (i));
	return (key);
}