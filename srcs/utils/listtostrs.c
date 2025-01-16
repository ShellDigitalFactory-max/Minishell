/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listtostrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:16:47 by linux             #+#    #+#             */
/*   Updated: 2025/01/16 12:10:34 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	*make_var_line(t_variable *var)
{
	char	*var_line;

	var_line = ft_strjoin(var->key, "=");
	if (var_line == NULL)
		return (NULL);
	var_line = ft_strjoin(var_line, var->value);
	if (var_line == NULL)
		return (NULL);
	return (var_line);
}

char	**listtostrs(t_variable_list list)
{
	char		**strs;
	size_t		i;
	size_t		len;
	t_variable	*var;

	len = ft_lstsize(list);
	strs = malloc(sizeof(char *) * (len + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (list != NULL)
	{
		var = (t_variable *)list->content;
		strs[i] = make_var_line(var);
		if (strs[i] == NULL)
		{
			free_strs(strs);
			return (NULL);
		}
		++i;
		list = list->next;
	}
	strs[i] = NULL;
	return (strs);
}
