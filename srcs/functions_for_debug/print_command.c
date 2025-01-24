/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:14:55 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/24 17:15:04 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_command(void *to_print)
{
	t_command	*command_struct = (t_command *)to_print;

	printf("arguments =\n");
	print_arguments_list((t_command_args)command_struct->command_args);

	if ((t_variable_list *)command_struct->command_environment != NULL)
	{
		printf("env=\n");
		print_env((t_variable_list *)command_struct->command_environment);
	}
}