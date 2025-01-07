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

extern t_minishell_data	minishell_data;

int	set_variable(const char *key, const char *value,
				bool make_it_exportable)
{
	add_variable_to_variables_list(key, value,
		make_it_exportable);
	return (EXIT_SUCCESS);
}