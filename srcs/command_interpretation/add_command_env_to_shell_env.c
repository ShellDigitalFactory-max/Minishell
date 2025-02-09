/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command_env_to_shell_env.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:36:52 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/30 20:37:03 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_variables_to_shell_env(char **variables)
{
	t_variable	*already_in_env;
	char		*variable_key;
	bool		is_exportable;
	size_t		i;

	i = 0;
	while (variables[i] != NULL)
	{
		variable_key = get_variable_key(variables[i]);
		already_in_env = find_variable_from_key(get_environment(),
				variable_key);
		if (already_in_env != NULL)
			is_exportable = already_in_env->is_exportable;
		else
			is_exportable = NOT_EXPORTABLE;
		if (set_variable_from_keyvalue(variables[i], is_exportable)
			== PROCESS_FAILURE)
		{
			ft_dprintf(STDERR_FILENO, "minishell: malloc failure during "
				"environment_update. Aborting.\n");
			exit(FAILURE);
		}
		free(variable_key);
		++i;
	}
}

void	add_command_env_to_shell_env(t_variable_list command_env)
{
	char	**variables_to_add;

	variables_to_add = list_to_strs_array(command_env, env_list_to_env_array);
	if (variables_to_add == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc failure during "
			"environment_update. Aborting.\n");
		exit(FAILURE);
	}
	add_variables_to_shell_env(variables_to_add);
	ft_free_and_null(variables_to_add);
}
