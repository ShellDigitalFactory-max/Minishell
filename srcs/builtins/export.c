/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:24 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/06 16:38:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	swap_variables(char **first_variable, char **second_variable)
{
	char	*temp;

	temp = *first_variable;
	*first_variable = *second_variable;
	*second_variable = temp;
}

static void	bubble_sort_env(char **env, int count)
{
	int	sorted;
	int	i;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < count - 1)
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
			{
				swap_variables(&env[i], &env[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}

static void	display_variables(char **sorted_env, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		printf("declare -x %s\n", sorted_env[i]);
		++i;
	}
}

static void	display_sorted_exportables_variables(char **env)
{
	char	**sorted_env;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (env[count] != NULL)
	{
		count++;
	}
	sorted_env = malloc(count * sizeof(char *));
	if (sorted_env == NULL)
	{
		perror("malloc");
		exit(FAILURE);
	}
	while (i < count)
	{
		sorted_env[i] = env[i];
		i++;
	}
	bubble_sort_env(sorted_env, count);
	display_variables(sorted_env, count);
	free(sorted_env);
	ft_free_and_null(env);
}

static int	export_variables(char **variables)
{
	size_t	i;

	i = 0;
	while (variables[i] != NULL)
	{
		if (assignation_checker(variables[i]) == INVALID_ASSIGNATION)
		{
			ft_dprintf(STDERR_FILENO, "minishell: export: `%s': not a valid identifier\n", variables[i]);
		}
		else
			set_variable_from_keyvalue(variables[i], EXPORTABLE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	export(t_command *command)
{
	char	**variables_to_export;

	variables_to_export = NULL;
	if (ft_lstsize(command->command_args) == 1)
	{
		display_sorted_exportables_variables(
			exportable_env_list_to_strs_array());
		return (EXIT_SUCCESS);
	}
	variables_to_export = list_to_strs_array(command->command_args, args_list_to_args_array);
	export_variables(variables_to_export + 1);
	ft_free_and_null(variables_to_export);
	return (EXIT_SUCCESS);
}
