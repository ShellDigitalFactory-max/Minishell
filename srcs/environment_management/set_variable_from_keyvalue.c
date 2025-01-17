/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable_from_keyvalue.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:14:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/07 19:14:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	set_variable_from_keyvalue(const char *keyvalue,
			bool make_it_exportable, t_variable_list *environment)
{
	t_status	process_status;
	char		*key;
	char		*value;

	key = get_variable_key(keyvalue);
	if (key == NULL)
		return (process_status = PROCESS_FAILURE);
	value = get_variable_value(keyvalue);
	if (value == NULL)
	{
		free(key);
		return (process_status = PROCESS_FAILURE);
	}
	process_status = set_variable(key, value, make_it_exportable, environment);
	if (process_status != PROCESS_FAILURE)
	{
		free(key);
		free(value);
	}
	return (process_status);
}
