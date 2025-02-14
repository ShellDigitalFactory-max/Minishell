/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:34:01 by linux             #+#    #+#             */
/*   Updated: 2025/02/14 18:01:35 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(t_command *command)
{
	t_new_line_status	new_line_status;
	char				**args;
	size_t				i;

	new_line_status = NEW_LINE;
	args = list_to_strs_array(command->command_args, args_list_to_args_array);
	if (args == NULL)
		return (EXIT_FAILURE);
	i = 0;
	if ()
}
