/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:49:55 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/04 20:50:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_variable(const char *key, const char *value, bool make_it_exportable)
{
	const t_variable_list	*environment = get_environment();
	const bool				is_exportable = make_it_exportable == true;
	t_variable				*variable;

	variable = find_variable_from_key(environment, key);
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