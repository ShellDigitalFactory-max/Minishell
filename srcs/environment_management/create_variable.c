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

t_variable	*create_variable(const char *key, const char *value,
						bool is_exportable)
{
	t_variable	*new_variable;

	new_variable = (t_variable *)ft_calloc(1, sizeof(t_variable));
	if (new_variable == NULL)
		return (NULL);
	new_variable->key = ft_strdup(key);
	if (new_variable->key == NULL
			|| update_variable(new_variable, value, is_exportable)
				== PROCESS_FAILURE)
	{
		delete_variable(new_variable);
		return (NULL);
	}
	return (new_variable);
}