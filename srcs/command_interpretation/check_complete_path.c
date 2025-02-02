/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_complete_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:54:56 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/01 15:55:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command_status	check_complete_path(t_command *command)
{
	if (access(command->command_binary_path, F_OK | X_OK) == 0)
	{
		return (VALID_COMMAND);
	}
	return (INVALID_COMMAND);
}