/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:45:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/08 13:46:03 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	update_variable(t_variable *variable, const char* value,
					const bool is_exportable)
{
	variable->is_exportable = is_exportable;
	if (value != NULL)
	{
		free(variable->value);
		variable->value = ft_strdup(value);
		if (variable->value == NULL)
			return (PROCESS_FAILURE);
	}
	return (PROCESS_SUCCESS);
}