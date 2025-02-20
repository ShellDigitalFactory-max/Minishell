/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_opening_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/21 18:41:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_opening_error(t_command *current_command, const char *file_name)
{
	if (errno == ENOENT)
		ft_asprintf(&current_command->opening_failure_msg,
			"minishell: %s: No such file or directory", file_name);
	else if (errno == EACCES)
		ft_asprintf(&current_command->opening_failure_msg,
			"minishell: %s: Permission denied", file_name);
	else if (errno == EMFILE || errno == ENFILE)
		ft_asprintf(&current_command->opening_failure_msg,
			"minishell: %s: Too many open files", file_name);
	else if (errno == EISDIR)
		ft_asprintf(&current_command->opening_failure_msg,
			"minishell: %s: Is a directory", file_name);
	else
		ft_asprintf(&current_command->opening_failure_msg,
			"minishell: %s: failed to open %s: %s", file_name,
			strerror(errno));
}
