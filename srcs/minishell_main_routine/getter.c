/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:28:51 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/16 21:29:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell_context	*get_minishell_context(t_minishell_context *ptr, int reset)
{
	static t_minishell_context	*minishell_context;

	if (reset == 1)
	{
		minishell_context = NULL;
		return (NULL);
	}
	if (ptr == NULL)
		return (minishell_context);
	else
		minishell_context = ptr;
	return (minishell_context);
}
