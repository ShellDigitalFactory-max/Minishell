/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:12:12 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/11 14:12:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_status_value(void)
{
	const t_variable	*exit_status_variable
		= find_variable_in_environment_from_key(EXIT_STATUS_KEY,
			get_environment());
	int					exit_status;

	exit_status = ft_atoi(exit_status_variable->value);
	return (exit_status);
}
