/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:43:18 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/10 18:43:30 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_exit_status(int exit_status)
{
	char	*exit_status_keyvalue;
	char	*exit_status_value;

	exit_status_value = ft_itoa(exit_status);
	if (exit_status_value == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc failure during "
			"exit_status update.Aborting.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_asprintf(&exit_status_keyvalue, "?=%s", exit_status_value) == -1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc failure during "
			"exit_status update.Aborting.\n");
		exit(EXIT_FAILURE);
	}
	set_variable_from_keyvalue(exit_status_keyvalue, NOT_EXPORTABLE);
	free(exit_status_value);
	free(exit_status_keyvalue);
}
