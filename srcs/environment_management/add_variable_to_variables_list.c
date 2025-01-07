/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_variable_to_variables_list.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:48:23 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/06 21:48:51 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_adding_status	add_variable_to_environment(t_variable_list environment,
		const char *key, const char *value, bool is_exportable)
{
	t_variable		*new_variable;
	t_variable_list	new_node;

	new_variable = create_variable(key, value, is_exportable);
	if (new_variable == NULL)
	{
		return (ADDING_FAILURE);
	}
	new_node = ft_lstnew(new_variable);
	if (new_node == NULL)
	{
		free(new_node);
		return (ADDING_FAILURE);
	}
	ft_lstadd_back(&environment, new_node);
	return (ADDING_SUCCESS);
}