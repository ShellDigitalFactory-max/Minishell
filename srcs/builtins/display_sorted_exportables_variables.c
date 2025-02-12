/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sorted_exportables_variables.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:00:53 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/11 20:01:08 by tchobert         ###   ########.fr       */
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
		printf("export %s\n", sorted_env[i]);
		++i;
	}
}

void	display_sorted_exportables_variables(char **env)
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
