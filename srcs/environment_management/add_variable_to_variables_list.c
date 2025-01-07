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

t_variable_list add_variable_to_variables_list(t_variable_list variables_list,
		const char *key, const char *value, bool is_exportable)
{
	t_variable		*new_variable;
	t_variable_list	new_node;

	new_variable = create_variable(key, value, is_exportable);
	if (new_variable == NULL)
	{
		return (NULL);
	}
	new_node = ft_lstnew(new_variable);
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	ft_lstadd_back(&variables_list, new_node);
	return (variables_list);
}