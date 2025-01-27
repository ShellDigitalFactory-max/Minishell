/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:09:11 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/27 14:09:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(const char *command_name)
{
	static const char *	builtins_dictionary[] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit",
		NULL,
	};
	size_t	i;

	i = 0;
	if (command_name == NULL)
		return (false);
	while (builtins_dictionary[i] != NULL)
	{
		if (ft_strcmp(builtins_dictionary[i], command_name) == 0)
			return (true);
		++i;
	}
	return (false);
}
