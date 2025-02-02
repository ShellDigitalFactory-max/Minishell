/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:37:02 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/30 14:37:14 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_command_name(t_command *command)
{
	if (command->command_args != NULL)
	{
		command->command_name = ft_strdup(command->command_args->content);
		if (command->command_name == NULL)
		{
			ft_dprintf(STDERR_FILENO, "minishell: malloc error during command "
				"pipeline building. Aborting.\n");
			exit(FAILURE);
		}
	}
}
