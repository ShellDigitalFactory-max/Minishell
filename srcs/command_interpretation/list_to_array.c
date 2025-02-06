/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:25:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/31 16:25:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_variable_str(t_variable *variable)
{
	char	*variable_str;

	ft_asprintf(&variable_str, "%s=%s", variable->key, variable->value);
	return (variable_str);
}


void	exportables_variables_to_strs_array(t_variable_list env, char **array)
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
			env = env->next;
			++i;
		}
	}
}

void	env_list_to_env_array(t_variable_list env, char **array)
{
	char	*current_variable;
	size_t	i;

	i = 0;
	current_variable = NULL;
	while (env != NULL)
	{
		current_variable = build_variable_str(env->content);
		if (current_variable == NULL)
		{
			ft_dprintf(STDERR_FILENO, "minishell: malloc error "
			"during command execution stting. Aborting.\n");
			exit (FAILURE);
		}
		array[i] = current_variable;
		env = env->next;
		++i;
	}
}

void	args_list_to_args_array(t_command_args args, char **array)
{
	size_t	i;

	i = 0;
	while (args != NULL)
	{
		array[i] = ft_strdup(args->content);
		if (array[i] == NULL)
		{
			ft_dprintf(STDERR_FILENO, "minishell: malloc error "
			"during command execution stting. Aborting.\n");
			exit (FAILURE);
		}
		args = args->next;
		++i;
	}
}

char	**list_to_strs_array(t_list *lst, void (*conversion_funct)(t_list *, char **))
{
	const size_t	array_size = ft_lstsize(lst);
	char			**array;

	array = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (array != NULL)
	{
		array[array_size] = NULL;
		conversion_funct(lst, array);
	}
	return (array);
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
		exportables_variables_to_strs_array(*get_environment(), env_array);
	}
	return (env_array);
}