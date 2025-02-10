/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_env_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:30:59 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/09 18:31:08 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_variable_str(t_variable *variable)
{
	char	*variable_str;

	ft_asprintf(&variable_str, "%s=%s", variable->key, variable->value);
	return (variable_str);
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
