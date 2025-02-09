/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_list_to_args_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:19:44 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/09 18:19:57 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
