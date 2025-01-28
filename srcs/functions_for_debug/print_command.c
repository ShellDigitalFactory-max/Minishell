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

static void	print_command_nature(t_command_nature command_nature)
{
	if (command_nature == NO_ENTRY)
		printf("\nCommand nature: NO ENTRY\n\n");
	else if (command_nature == ONLY_ASSIGNATION)
		printf("\nCommand nature: ONLY ASSIGNATION\n\n");
	else if (command_nature == POSSIBLE_BINARY)
		printf("\nCommand nature: POSSIBLE BINARY\n\n");
	else
		printf("\nCommand nature: BUILTIN\n\n");
}

void	print_command(void *to_print)
{
	t_command	*command_struct = (t_command *)to_print;

	printf("\nCOMMAND COMPOSITION:\n\n");
	printf("Command_name: %s\n\n", command_struct->command_name);
	printf("Command arguments:\n\n");
	print_arguments_list((t_command_args)command_struct->command_args);

	if ((t_variable_list *)command_struct->command_environment != NULL)
	{
		printf("\nCommand environment:\n\n");
		print_env((t_variable_list *)(&command_struct->command_environment));
	}
	print_command_nature(command_struct->command_nature);
	if (command_struct->command_redirections.in_stream != STDIN_FILENO
			&& command_struct->command_redirections.in_stream > 0)
		printf("\nCommand infile set.\n\n");
	if (command_struct->command_redirections.out_stream != STDOUT_FILENO
			&& command_struct->command_redirections.out_stream > 0)
		printf("\nCommand outfile set.\n\n");
	if (command_struct->opening_failure_msg == NULL)
		printf("\nCommand opening failures: none\n\n");
	else
		printf("\nCommand opening failure: %s\n\n", command_struct->opening_failure_msg);
	printf("\n-----------------------------\n\n");
}