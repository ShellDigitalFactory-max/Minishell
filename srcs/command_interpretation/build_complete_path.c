/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_complete_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:50:40 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/31 14:50:52 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command_status	build_complete_path(t_command *command)
{
	size_t	i;
	char	*old_path;
	char	**path_array;

	path_array = build_path_array(command);
	if (path_array == NULL)
	{
		// EXIT A FAIRE !!!!!!!!!!!!!!!!!!!
	}
	i = 0;
	while (path_array[i] != NULL)
	{
		old_path = command->command_name;
		ft_bzero(command->command_name, ft_strlen(command->command_name));
		if (ft_asprintf(&command->command_name, "%s%s%s", path_array[i],
				ABSOLUTE_PREFIX, command->command_name) == -1)
		{
			// EXIT A FAIRE !!!!!!
		}
		free(old_path);
		if (check_complete_path(command->command_name) == VALID_COMMAND)
			return (VALID_COMMAND);
		++i;
	}
	return (INVALID_COMMAND);
}