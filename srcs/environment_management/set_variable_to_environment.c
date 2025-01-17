/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable_to_environment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:38:33 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/17 16:38:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	set_variable_to_environment(const char *key, const char *value,
				bool make_it_exportable, t_variable_list *environment)
{
	const bool		is_exportable = make_it_exportable == true;
	t_variable_list		*environment;
	t_variable			*variable;
	char				*key_to_find;

	variable = NULL;
	key_to_find = (char *)key;
	variable = find_variable_from_key(environment, key_to_find);
	if (variable != NULL)
	{
		return (update_variable(variable, value, is_exportable));
	}
	else
	{
		variable = create_variable(key, value, is_exportable);
		return (add_variable_to_environment(environment, variable));
	}
}