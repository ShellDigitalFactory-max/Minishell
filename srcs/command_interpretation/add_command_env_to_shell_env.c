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
	size_t	i;

	i = 0;
	while(variables[i] != NULL)
	{
		if (set_variable_from_keyvalue(variables[i], NOT_EXPORTABLE)
			== PROCESS_FAILURE)
		{
			ft_dprintf(STDERR_FILENO, "minishell: malloc failure during "
			"environment_update. Aborting.\n");
			exit(FAILURE);
		}
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
}
