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

void	display_opening_errors(const char *file_name)
{
	if (errno == ENOENT)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: No such file or directory\n",
			file_name);
	}
	else if (errno == EACCES)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: Permission denied\n",
			file_name);
	}
	else if (errno == EMFILE || errno == ENFILE)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: Too many open files\n",
			file_name);
	}
	else if (errno == EISDIR)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: Is a directory\n",
			file_name);
	}
	else
		ft_dprintf(STDERR_FILENO, "minishell: %s: failed to open %s: %s\n",
			file_name, strerror(errno));
}
