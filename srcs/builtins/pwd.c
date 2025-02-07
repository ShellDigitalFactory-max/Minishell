/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:58:00 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/07 15:58:09 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(t_command *command)
{
	char	current_directory[PATH_MAX];

	if (ft_lstsize(command->command_args) > 1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: pwd: no arguments or options "
		"are accepted.\n");
		return (EXIT_FAILURE);
	}
	if (getcwd(current_directory,sizeof(current_directory)) == NULL)
	{
		perror("getcwd:");
		return (EXIT_FAILURE);
	}
	printf("%s\n", current_directory);
	return (EXIT_SUCCESS);
}