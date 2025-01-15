/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:41:28 by linux             #+#    #+#             */
/*   Updated: 2025/01/15 18:16:09 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin_command(char *command)
{
	char	**builtin_tab = make_builtin_tab();
	size_t	i = 0;

	while (builtin_tab[i] != NULL)
	{
		if (ft_strcmp(builtin_tab[i], command) == 0)
			return (true);
		i++;
	}
	return (false);
}
