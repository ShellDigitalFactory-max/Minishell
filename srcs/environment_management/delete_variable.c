/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:04:28 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/06 21:05:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell_data	minishell_data;

void	delete_variable(void *data)
{
	t_variable	*variable_to_delete;

	variable_to_delete = (t_variable *)data;
	free(variable_to_delete->key);
	if (variable_to_delete->value != NULL)
		free(variable_to_delete->value);
	free(variable_to_delete);
}