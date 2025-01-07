/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:46:37 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/06 21:46:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_variable_values(t_variable *variable, const char *key,
				const char *value)
{
	variable->key = ft_strndup(key, ft_strlen(key));
	if (variable->key == NULL)
		return (EXIT_FAILURE);
	if (value == NULL)
		variable->value = ft_strdup("");
	else
		variable->value = ft_strndup(value, ft_strlen(value));
	if (variable->value == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_variable	*create_variable(const char *key, const char *value,
						bool is_exportable)
{
	t_variable	*new_variable;

	new_variable = (t_variable *)malloc(sizeof(t_variable));
	if (new_variable == NULL)
		return (NULL);
	new_variable->is_exportable = is_exportable;
	if (set_variable_values(new_variable, key, value) == EXIT_FAILURE)
	{
		delete_variable(new_variable);
		return (NULL);
	}
	return (new_variable);
}