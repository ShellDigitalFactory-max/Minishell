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

static void	exit_failure_routine(void)
{
	ft_dprintf(STDERR_FILENO, "minishell: malloc failure "
		"during command binary searching.Aborting.\n");
	exit(FAILURE);
}

static void	free_routine(char *command_suffix, char **path_array)
{
	free(command_suffix);
	ft_free_and_null(path_array);
}

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
	char	*command_suffix;
	char	**path_array;

	path_array = build_path_array(command_env);
	if (path_array == NULL)
		exit_failure_routine();
	i = 0;
	command_suffix = ft_strdup(command->command_name);
	while (path_array[i] != NULL)
	{
		if (ft_asprintf(&command->command_binary_path, "%s%s%s", path_array[i],
				ABSOLUTE_PREFIX, command_suffix) == -1)
			exit_failure_routine();
		if (check_complete_path(command) == VALID_COMMAND)
		{
			free(command_suffix);
			return (VALID_COMMAND);
		}
		free(command->command_binary_path);
		++i;
	}
	free_routine(command_suffix, path_array);
	return (INVALID_COMMAND);
}
