/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_variable_from_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:16 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/08 18:45:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_variable_key_equal(void *variable_as_content, void *key)
{
	const t_variable	*variable = (t_variable *)variable_as_content;

	if (variable == NULL || variable->key == NULL || key == NULL)
		return (false);
	return (ft_strcmp(variable->key, key) == 0);
}

t_variable	*find_variable_from_key(t_variable_list *environment,
				const char *key)
{
	return (ft_list_find_first_content_match(environment, key,
				is_variable_key_equal));
}