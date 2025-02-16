/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:21:06 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/13 23:10:38 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

static t_list	*ft_list_find_previous_element(t_list *lst, t_list *node)
{
	t_list	*previous_element;

	if (lst != NULL)
	{
		previous_element = lst;
		while (previous_element != NULL)
		{
			if (previous_element->next == node)
			{
				return (previous_element);
			}
			previous_element = previous_element->next;
		}
	}
	return (NULL);
}

static size_t	ft_get_max_size(const char *a, const char *b)
{
	if (ft_strlen(a) > ft_strlen(b))
		return (ft_strlen(a));
	return (ft_strlen(b));
}

static t_variable_list get_variable_in_env(t_variable_list env, char *variable_key)
{
	t_variable_list	to_find;

	to_find = env;
	while(to_find != NULL)
	{
		if (ft_strncmp(((t_variable *)to_find->content)->key, variable_key,
				ft_get_max_size(((t_variable *)to_find->content)->key,
				variable_key)) == 0)
			return (to_find);
		to_find = to_find->next;
	}
	return (NULL);
}

static void	unset_variable(char *variable)
{
	t_variable_list		env;
	t_variable_list		variable_to_unset;
	t_variable_list		previous_variable_in_env;

	env = *(get_environment());
	variable_to_unset = get_variable_in_env(env, variable);
	if (variable_to_unset == NULL)
		return ;
	previous_variable_in_env = ft_list_find_previous_element(env, variable_to_unset);
	if (previous_variable_in_env == NULL)
		return ;
	if (previous_variable_in_env != NULL)
		previous_variable_in_env->next = variable_to_unset->next;
	else
		env = variable_to_unset->next;
	delete_variable(variable_to_unset->content);
	free(variable_to_unset);
}

static void	unset_variables(char **variables)
{
	size_t	i;

	i = 0;
	while (variables[i] != NULL)
	{
		unset_variable(variables[i]);
		++i;
	}
}

int	unset(t_command *command)
{
	char	**variables_to_unset;

	variables_to_unset = NULL;
	if (ft_lstsize(command->command_args) == 1)
		return (EXIT_SUCCESS);
	variables_to_unset = list_to_strs_array(command->command_args,
			args_list_to_args_array);
	if (variables_to_unset == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc failure during export builtin "
		 "process. Aborting\n");
		exit(EXIT_FAILURE);
	}
	unset_variables(variables_to_unset + 1);
	ft_free_and_null(variables_to_unset);
	return (EXIT_SUCCESS);
}
