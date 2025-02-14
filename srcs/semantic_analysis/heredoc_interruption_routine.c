/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_interruption_routine.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:00:29 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/14 20:00:42 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_interruption_routine(const char *delimiter, int heredoc_lines)
{
	if (heredoc_lines == 0)
		heredoc_lines = 1;
	ft_dprintf(STDERR_FILENO, "minishell: warning: here-document "
		"at line %d delimited by end-of-file (wanted `%s')\n",
	heredoc_lines, delimiter);
}
