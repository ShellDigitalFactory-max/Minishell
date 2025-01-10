/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/09 16:26:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	build_environment(char **variables)
{
	size_t	i;

	i = 0;
	while (variables[i] != NULL)
	{
		if (set_variable_from_keyvalue(variables[i], EXPORTABLE)
			== PROCESS_FAILURE)
			return (PROCESS_FAILURE);
		++i;
	}
	return (PROCESS_SUCCESS);
}
