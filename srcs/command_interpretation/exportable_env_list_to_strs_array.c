/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportable_env_list_to_strs_array.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:32:30 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/09 18:32:42 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_variable_str(t_variable *variable)
{
	char	*variable_str;

	ft_asprintf(&variable_str, "%s=%s", variable->key, variable->value);
	return (variable_str);
}

static void	exportables_variables_to_strs_array(t_variable_list env,
			char **array)
{
	char	*current_variable;
	size_t	i;

	i = 0;
	current_variable = NULL;
	while (env != NULL)
	{
		if (((t_variable *)env->content)->is_exportable == true)
		{
			current_variable = build_variable_str(env->content);
			if (current_variable == NULL)
			{
				ft_dprintf(STDERR_FILENO, "minishell: malloc error "
					"during command execution stting. Aborting.\n");
				exit (FAILURE);
			}
			array[i] = current_variable;
		}
		env = env->next;
		++i;
	}
}

char	**exportable_env_list_to_strs_array(void)
{
	t_variable_list	env;
	char			**env_array;
	size_t			env_size;

	env = *get_environment();
	env_size = 0;
	while (env != NULL)
	{
		if (((t_variable *)env->content)->is_exportable == true)
		{
			++env_size;
		}
		env = env->next;
	}
	env_array = (char **)malloc(sizeof(char *) * (env_size + 1));
	if (env_array != NULL)
	{
		env_array[env_size] = NULL;
		exportables_variables_to_strs_array(*get_environment(),
			env_array);
	}
	return (env_array);
}
