/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_from_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:52:27 by linux             #+#    #+#             */
/*   Updated: 2025/02/12 17:05:22 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_get_max_size(const char *a, const char *b)
{
	if (ft_strlen(a) > ft_strlen(b))
		return (ft_strlen(a));
	return (ft_strlen(b));
}

t_lexem	get_variable_from_env(const char *key)
{
	t_variable_list	*environment;
	t_list			*current_variable;
	t_variable		*variable;

	environment = get_environment();
	current_variable = *environment;
	while (current_variable != NULL)
	{
		variable = current_variable->content;
		if (ft_strncmp(variable->key, key,
				ft_get_max_size(variable->key, key)) == 0)
			return (ft_strdup(variable->value));
		current_variable = current_variable->next;
	}
	if (current_variable == NULL )
		return (ft_strdup(""));
	return (NULL);
}
