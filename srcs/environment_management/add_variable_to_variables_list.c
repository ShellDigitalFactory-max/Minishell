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

extern t_minishell_data	minishell_data;

static int	add_variable_to_variables_list(const char *key,
				const char *value, bool is_exportable)
{
	t_variable		*new_variable;
	t_variable_list	new_node;

	new_variable = create_variable(key, value, is_exportable);
	if (new_variable == NULL)
	{
		delete_variables_list(minishell_data.variables_list);
		return (EXIT_FAILURE);
	}
	new_node = ft_lstnew(new_variable);
	if (new_variable == NULL)
	{
		free(new_node);
		delete_variables_list(minishell_data.variables_list);
		return (EXIT_FAILURE);
	}
	ft_lstadd_back(minishell_data.variables_list, new_variable);
	return (EXIT_SUCCESS);
}