/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_from_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:52:27 by linux             #+#    #+#             */
/*   Updated: 2025/02/10 19:47:33 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (ft_strcmp(variable->key, key) == 0)
			return (ft_strdup(variable->value));
		current_variable = current_variable->next;
	}
	if (current_variable == NULL)
		return (ft_strdup(""));
	return (NULL);
}
