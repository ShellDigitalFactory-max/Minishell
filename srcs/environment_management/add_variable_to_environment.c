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

t_status	add_variable_to_environment(t_variable_list *environment,
				t_variable *variable)
{
	t_variable_list	new_node;

	new_node = ft_lstnew(variable);
	if (new_node == NULL)
		return (PROCESS_FAILURE);
	ft_lstadd_back(environment, new_node);
	return (PROCESS_SUCCESS);
}
