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

static char	**split_path_variable(char *path_variable)
{
	char	**splitted_path_variable;

	splitted_path_variable = ft_split(path_variable, ':');
	return (splitted_path_variable);
}

char	**build_path_array(char **command_env)
{
	char	**path_array;
	char	*path_var;

	path_array = NULL;
	path_var = ft_getenv("PATH", command_env);
	if (path_var == NULL)
		return (path_array);
	path_array = split_path_variable(path_var);
	return (path_array);
}

t_command_status	build_complete_path(t_command *command, char **command_env)
{
	size_t	i;
	char	*old_path;
	char	**path_array;

	path_array = build_path_array(command_env);
	if (path_array == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc failure during "
		"command binary searching.Aborting.\n");
		exit(FAILURE);
	}
	i = 0;
	old_path = command->command_name;
	while (path_array[i] != NULL)
	{
		if (ft_asprintf(&command->command_name, "%s%s%s", path_array[i],
				ABSOLUTE_PREFIX, old_path) == -1)
		{
			if (command->command_name == NULL)
			{
				ft_dprintf(STDERR_FILENO, "minishell: malloc failure "
				"during command binary searching.Aborting.\n");
				exit(FAILURE);
			}
		}
		if (check_complete_path(command) == VALID_COMMAND)
			return (VALID_COMMAND);
		++i;
	}
	return (INVALID_COMMAND);
}
