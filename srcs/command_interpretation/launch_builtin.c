/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:21:50 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/01 18:22:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin_type	get_builtin_type(const char *command_name)
{
	static const char	*builtins_dictionary[] = {
		"env",
		NULL,
	};
	t_builtin_type	type;

	type = 0;
	while (builtins_dictionary[type] != NULL)
	{
		if (ft_strcmp(builtins_dictionary[type], command_name) == 0)
			break ;
		++type;
	}
	return (type);
}

int	launch_builtin(t_command *command)
{
	const t_builtin_type	builtin_type
								= get_builtin_type(command->command_name);

	static t_builtin	builtins[] = {
		env,
	};

	return (builtins[builtin_type](command));
}