/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:50:23 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/01 16:50:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_exportable_variable(void *content)
{
	const t_variable	*variable = (t_variable *)content;

	if (variable->is_exportable == true)
	{
		printf("%s", variable->key);
		printf("=");
		printf("%s\n", variable->value);
	}
}

int	env(t_command *current_command)
{
	if (ft_lstsize(current_command->command_args) != 1)
	{
		ft_dprintf(STDERR_FILENO, "env: no options or arguments "
			"are accepted.\n");
		return (EXIT_FAILURE);
	}
	ft_lstiter(*get_environment(), print_exportable_variable);
	return (EXIT_SUCCESS);
}
