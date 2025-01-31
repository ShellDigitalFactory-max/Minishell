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

// static char	**split_path_var(char *env_var)
// {
// 	char	**splitted_path_var;

// 	splitted_path_var = ft_split(env_var, ':');
// 	return (splitted_path_var);
// }

char	**build_path_array(char **command_env)
{
	// char	**path_array;
	char	*path_var;

	// path_array = NULL;
	path_var = ft_getenv("PATH", command_env);
	printf("Command env 1 = %s\n", command_env[0]);
	// if (path_var == NULL)
	// 	return (path_array);
	printf("\ntest = %s\n", path_var);
	// path_array = split_path_var(path_var);
	return (ft_split(path_var, ':'));
}

t_command_status	build_complete_path(t_command *command, char **command_env)
{
	size_t	i;
	size_t	test = 0;
	char	*old_path;
	char	**path_array;

	path_array = build_path_array(command_env);
	// if (path_array == NULL)
	// {
	// 	// EXIT A FAIRE !!!!!!!!!!!!!!!!!!!
	// }
	i = 0;
	old_path = command->command_name;
	while(path_array[test] != NULL)
	{
		printf("before : %s\n", path_array[test]);
		++test;
	}
	while (path_array[i] != NULL)
	{
		// ft_bzero(command->command_name, ft_strlen(command->command_name));
		if (ft_asprintf(&command->command_name, "%s%s%s", path_array[i],
				ABSOLUTE_PREFIX, old_path) == -1)
		{
			// EXIT A FAIRE !!!!!!
		}
		// free(old_path);
		if (check_complete_path(command) == VALID_COMMAND)
			return (VALID_COMMAND);
		++i;
		printf("after : %s\n", command->command_name);
	}
	return (INVALID_COMMAND);
}